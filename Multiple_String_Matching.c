#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MPC 1063
#define WAR 2000
#define PlenDef 10

typedef struct StringNode{
    int *str;
    /* 配列Tのhashを格納する */
    int flg;
    int *num; 
    /* 配列Tの添え字を補完し、クイックソートをしても場所がわかる様にする。 */
}SNode;
 
int n;

/* クイックソート用の中央値を返す */
int med3(int x, int y, int z)
{
    if( x < y )
    {
        if( y < z )
        {
            return y;
        }
        else if( z < x )
        {
            return x;
        }
        else
        {
            return z;
        }
    }
    else
    {
        if( z < y )
        {
            return y;
        }
        else if( x < z )
        {
            return x;
        }
        else
        {
            return z;
        }
    }
}

/* クイックソート */
void quickSort(SNode A,int p, int r)
{
    if(p < r)
    {
        int i=p, j=r;
        int tmp, pibot = med3( A.str[i], A.str[i+(j-i)/2], A.str[j] );
        
        while(1)
        {
            while( A.str[i] < pibot ) i++;
            while( pibot < A.str[j] ) j--;
            if( i >= j ) break;

            tmp = A.str[i];
            A.str[i] = A.str[j];
            A.str[j] = tmp;
            tmp = A.num[i];
            A.num[i] = A.num[j];
            A.num[j] = tmp;
            i++;
            j--;
        }
        quickSort(A, p, i - 1);
        quickSort(A, j + 1, r);
    }
}

SNode init_Snode(SNode A,int Tlen,int Plen)
{
    int TP = Tlen-Plen+1;
    A.str = malloc(sizeof(int)*TP);
    A.flg = 0;
    A.num = malloc(sizeof(int)*TP);
    return A;
}


/* quickSort_Ver 検索 2分探索 */
void Search(SNode B,char T[],char P[],int Pcp,int Tlen,int Plen)
{
    
    int i=0,j = Tlen-1,IJ,flg = 0;
    
    
    /* 2分探索 */
    while(i <= j)
    {        
        IJ = i + (j-i) / 2;
        
        
        if(IJ == 0)
        {
            if(memcmp(&T[B.num[0]],&P[0],Plen)==0)
            {
                flg = 1;
            }
            break;
        }
        
        /* hashが同じ場合 */
        if(B.str[IJ] == Pcp){
            int IJcp = IJ;
            
            /* hashが同じでも衝突を起こしている可能性がある為、前後も探す */
            while(B.str[IJcp] == Pcp)
            {
                if(memcmp(&T[B.num[IJcp]],&P[0],Plen)==0)
                {
                    flg = 1;
                    break;
                }
                IJcp -= 1;
            }
            if(flg == 1){
                break;
            }
            IJcp = IJ;
            while(B.str[IJcp] == Pcp)
            {
                if(memcmp(&T[B.num[IJcp]],&P[0],Plen)==0)
                {
                    flg = 1;
                    break;
                }
                IJcp += 1;
            }
            break;
        }
        else if(Pcp < B.str[IJ])
        {
            j = IJ-1;
        }
        else if(B.str[IJ] < Pcp)
        {
            i = IJ+1;
        }
        
    }
    if(flg == 1)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return;
}
 
/* hash値を作成*/
void hash(char T[],char P[],int Tlen,int Plen,int PlenCC,SNode *SN,int Tcp[])
{
    
    int i,j,Pcp=0,M = MPC;
    
    
    /* 検索する対象をhash化 */
    for(i=0;i<PlenCC;i++)
    {
        Pcp += P[i] * M % WAR;
        M += M;
    }
    
    
    /* 一度作成されているhashであれば工程をスキップし、検索に遷移させる */
    if(SN[PlenCC].flg == 0)
    {
    
        /* char型をhash化(Plenの長さで調整) */
        for(i=0;i<=Tlen-PlenCC;i++)
        {
            M = MPC;
            SN[PlenCC].str[i] = 0;
            
            
            /* 配列Tのhashを作成 */
            for(j=0;j<PlenCC;j++)
            {
                SN[PlenCC].str[i] += (int)T[i+j] * M % WAR;
                M += M;
            }
            SN[PlenCC].num[i] = i;
            
        }
        SN[PlenCC].flg = 1;
        
        quickSort(SN[PlenCC],0,Tlen-PlenCC);
        
    }
    
    Search(SN[PlenCC],T,P,Pcp,Tlen-Plen+2,Plen);

}
 
 
int main()
{

    int i,j,Tlen,Plen,TcntPrev = 0,TcntBih = 1,Pcnt = 0;
    char T[1000000];
    char P[1000];
    SNode SN[PlenDef+1];
     
    scanf("%s",T);
    scanf("%d",&n);
    Tlen = strlen(T);
    
    /* Tの文字が前から何個同じか調べる。*/
    while( TcntPrev<Tlen )
    {
        if(T[0] == T[TcntPrev])
        {
            TcntPrev++;
        }
        else
            break;
    }
    /* Tの文字が後ろから何個同じか調べる。 */
    while( TcntBih<Tlen)
    {
        if(T[Tlen-1] == T[Tlen-TcntBih])
        {
            TcntBih++;
        }
        else
            break;
    }
    int *Tcp = malloc(sizeof(int)*Tlen);

    
    /* 最後の1文字だけ違うかどうかを調べている */
    if(TcntPrev == Tlen-1)
    {
        for( i=0 ; i<n ; i++)
        {
            Pcnt = 0;
            scanf("%s",P);
            Plen = strlen(P);
            if(Plen == 1)
            {
                if(strstr(T,P)==NULL)
                {
                    printf("0\n");
                }
                else
                {
                    printf("1\n");
                }
            }
            else
            {
            
                /* パターンが最後の1文字だけ違うかどうかを調べている */
                while(Pcnt<Plen)
                {
                
                
                    if(P[0]==P[Pcnt])
                    {
                        Pcnt++;
                    }
                    else
                        break;
                }
                
                
                /* 配列Pが全て同じ文字だった場合はPの0番目だけをstrstr関数で探す */
                if(Pcnt == Plen)
                {
                    if(strstr(T,&P[0])==NULL)
                    {
                        printf("0\n");
                    }
                    else
                    {
                        printf("1\n");
                    }
                }
                /* 配列Pの最後の1文字だけ違う場合は最後の文字と最初の文字を調べる */
                else if(Pcnt == Plen-1)
                {
                    if(T[Tlen-1] == P[Plen-1]&&T[0] == P[0])
                    {
                        printf("1\n");
                    }
                    else
                    {
                        printf("0\n");
                    }
                }
                /* 配列Pの途中で文字が入っていた場合、配列Tとは絶対に一致しない為0を表示 */
                else
                {
                    printf("0\n");
                }
            }
        }
    }
    /* 配列Tの最初の一文字目だけ違う場合 */
    else if(TcntBih == Tlen)
    {
        for( i=0 ; i<n ; i++)
        {
            scanf("%s",P);
            Plen = strlen(P);
            Pcnt = 1;
            
            while(Pcnt<Plen)
            {
                if(P[Plen-1]==P[Plen-Pcnt])
                {
                    Pcnt++;
                }
                else
                {
                    break;
                }
            }
            
            if(Plen == Pcnt)
            {
                if(strstr(T,&P[0])==NULL)
                {
                    printf("0\n");
                }
                else
                {
                    printf("1\n");
                }
            }
            else if(Plen-1 == Pcnt)
            {
                
                if(P[0] == T[0] && P[Plen-1] == T[Tlen-1])
                {
                    printf("1\n");
                }
                else
                {
                    printf("0\n");
                }
            }
            else
            {
                printf("0\n");
            }
        }
    }
    /* 上記のどちらでもない場合 */
    else
    {
        for(i = 0;i<n;i++)
        {
            scanf("%s",P);
            Plen = strlen(P);
            
            /* 配列Pの長さが1ならばstrstr関数で探す */
            if(Plen == 1)
            {
                if(strstr(T,&P[0])==NULL)
                {
                    printf("0\n");
                }
                else
                {
                    printf("1\n");
                }
            }
            
            /* 配列Pが配列Tよりも大きい場合は一致する事がない */
            else if(Tlen < Plen)
            {

                printf("0\n");

            }
            
            /* PlenDefよりも配列Pが大きい場合 */
            else if(PlenDef <= Plen)
            {
                /* 初期化したかどうか */
                if(SN[PlenDef].flg == 0)
                    SN[PlenDef] = init_Snode(SN[PlenDef],Tlen,PlenDef);
    
                hash(T,P,Tlen,Plen,PlenDef,SN,Tcp);

            }
            
            /* 配列Pが1よりも大きくPlenDefよりも小さい場合 */
            else
            {
                
                /* 初期化したかどうか */
                if(SN[Plen].flg == 0)
                    SN[Plen] = init_Snode(SN[Plen],Tlen,Plen);
    

                hash(T,P,Tlen,Plen,Plen,SN,Tcp);
    
            }
        }
    }
    free(Tcp);
    return 0;
}
