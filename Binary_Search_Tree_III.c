#include <stdio.h>          
#include <stdlib.h>

#define NIL -1



typedef struct {
    int key;
    int parent;
    int left;
    int right;
} node;
 

node data[500001];

int root, X;
 
int Min(int);
int find(int , int );
int Suc(int );
void Del(int );
void Ins(int );
void Ino(int );
void Pre(int );


int main()
{
    char array[8];
    int n, x, i;
 
    root = NIL;
    X = 0;

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        scanf("%s", array);

        if(array[0] == 'd'){
            scanf("%d", &x);
            Del(find(root, x));
        }
 
        else if(array[0] == 'f'){
            scanf("%d", &x);
            printf("%s\n", find(root, x) != NIL ? "yes" : "no");
        }
 
        else if(array[0] == 'i'){
            scanf("%d", &x);
            Ins(x);
        }
 
       else if(array[0] == 'p'){

            Ino(root);
            printf("\n");
 
            Pre(root);
            printf("\n");
        }
    }
 
    return 0;
}

int Min(int u)
{
    while (data[u].left != NIL)u = data[u].left;
 
    return u;
}
 
int find(int u, int k)
{
    while (u != NIL && k != data[u].key)
    {
        if (k < data[u].key)u = data[u].left;

        else u = data[u].right;
    }
 
    return u;
}
 
int Suc(int u)
{
    int y;

    if (data[u].right != NIL)return Min(data[u].right);
 
    y = data[u].parent;

    while (y != NIL && u == data[y].right)
    {
        u = y;
        y = data[y].parent;
    }
 
    return y;
}
 
void Del(int z)
{
    int y, x; 
    if (data[z].left == NIL || data[z].right == NIL)y = z;

    else y = Suc(z);
 
    if (data[y].left != NIL)x = data[y].left;

    else x = data[y].right;
 
    if (x != NIL)data[x].parent = data[y].parent;
 
    if (data[y].parent == NIL)root = x;

    else
    {
        if (y == data[data[y].parent].left)data[data[y].parent].left = x;

        else data[data[y].parent].right = x;
    }
 
    if (y != z)data[z].key = data[y].key;

}
 
void Ins(int k)
{
    int z, y = NIL, x = root;
      z = X++;

 
    data[z].key = k;
    data[z].left = NIL;
    data[z].right = NIL;
 
    while (x != NIL)
    {
        y = x;

        if (data[z].key < data[x].key)x = data[x].left;

        else x = data[x].right;
    }
 
    data[z].parent = y;

    if (y == NIL)root = z;

    else
    {
        if (data[z].key < data[y].key)data[y].left = z;

        else data[y].right = z;
    }
}
 
void Ino(int u)
{
    if (u == NIL)
        return;
 
    Ino(data[u].left);
    printf(" %d", data[u].key);
    Ino(data[u].right);
}
 
void Pre(int u)
{
    if (u == NIL)return;
 
    printf(" %d", data[u].key);
    Pre(data[u].left);
    Pre(data[u].right);
}
 
