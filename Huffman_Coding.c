/*
input
aaabbcccdeeeffg

output
41
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 優先度付きキューの構造体
typedef struct queue_t{
	char c;
	int count;
	struct queue_t *left, *right;
} QUEUE_T;

QUEUE_T *PRIORITY_QUEUE[27];


// 小さい頂点を丁度いい所まで浮かび上がらせる
void Up_heap(int pos)
{
	int parent = pos / 2;
	QUEUE_T *x = PRIORITY_QUEUE[pos];

	while(parent >= 1){
		if(PRIORITY_QUEUE[parent]->count > x->count){
			PRIORITY_QUEUE[pos] = PRIORITY_QUEUE[parent];
			pos = parent;
			parent = pos / 2;
		}else
			break;
	}

	PRIORITY_QUEUE[pos] = x;
}


// 一番上(カウントが最小値)の頂点を取り出す、一番下のを一番上に持ってきてから、丁度いい所まで沈める
QUEUE_T *Down_heap(int count)
{
	QUEUE_T *x, *tmp;
	int pos = 1;
	int l = 2;

	x = PRIORITY_QUEUE[1];

	tmp = PRIORITY_QUEUE[1] = PRIORITY_QUEUE[count--];

	while(l <= count){
		if((l + 1) <= count && PRIORITY_QUEUE[l]->count > PRIORITY_QUEUE[l + 1]->count)
			l++;

		if(PRIORITY_QUEUE[l]->count < tmp->count){
			PRIORITY_QUEUE[pos] = PRIORITY_QUEUE[l];
			pos = l;
			l = pos * 2;
		}else
			break;
	}

	PRIORITY_QUEUE[pos] = tmp;

	return x;
}


// 文字に関する情報を頂点としてキューへ登録
void Add(int count, int num, int moji_count)
{
	QUEUE_T *p;

	if( (p = (QUEUE_T *)malloc(sizeof(QUEUE_T))) == NULL){
		printf("malloc error\n");
		exit(1);
	}

	p->c = 97 + num;
	p->count = moji_count;
	p->left = NULL;
	p->right = NULL;

	PRIORITY_QUEUE[count] = p;

	Up_heap(count);
}


// 統合した頂点をキューへ登録、丁度いいところまで浮かび上がらせる
void Add2(QUEUE_T *x, int count)
{
	PRIORITY_QUEUE[count] = x;
	Up_heap(count);
}


// ２つの頂点を統合した頂点を作成
QUEUE_T *Make_huffmann_tree(QUEUE_T *left, QUEUE_T *right)
{
	QUEUE_T *p;

	if( (p = (QUEUE_T *)malloc(sizeof(QUEUE_T))) == NULL){
		printf("malloc error\n");
		exit(1);
	}

	p->c = 'X';
	p->count = left->count + right->count;
	p->left = left;
	p->right = right;

	return p;
}


int SUM = 0;
char CODE[256] = "";

// ハフマンツリーを実際にたどって、ビット列を割り当てる
void Tree_walk(QUEUE_T *x, int depth)
{
	char moji[256];

	if(x->left != NULL){
		strcat(CODE, "0");
		Tree_walk(x->left, depth + 1);
		CODE[strlen(CODE) - 1] = '\0';
	}

	if(x->right != NULL){
		strcat(CODE, "1");
		Tree_walk(x->right, depth + 1);
		CODE[strlen(CODE) - 1] = '\0';
	}

	if(x->left == NULL & x->right == NULL){
		// 文字と割り当てられたビット列の表示
//		printf("ans = %c:%s\n", x->c, CODE);
		SUM += strlen(CODE) * x->count;
	}
}


int main()
{
	QUEUE_T *x, *y, *z;
	char in_str[1000005];
	int moji_count[26];
	int len;
	int count, count2;
	int i, j, k;

	scanf("%s", in_str);

	len = strlen(in_str);

	for(i = 0; i < 26; i++)
		moji_count[i] = 0;

	// 出現文字のカウント
	for(i = 0; i < len; i++)
		moji_count[in_str[i] - 97]++;

	// ヒープ木の作成
	count = 1;
	for(i = 0; i < 26; i++){
		if(moji_count[i] != 0){
//			printf("%c:%d\n", 97 + i, moji_count[i]);
			Add(count++, i, moji_count[i]);
		}
	}

	// ハフマン木の作成
	count--;
	while(count != 1){
		x = Down_heap(count--);
		y = Down_heap(count--);
		z = Make_huffmann_tree(x, y);
		Add2(z, ++count);
	}

	// ハフマツリーをたどってビット列を割り当てる
	Tree_walk(PRIORITY_QUEUE[1], 0);

	// 答え
	if(SUM)
		printf("%d\n", SUM);
	else
		printf("%d\n", PRIORITY_QUEUE[1]->count);

	return 0;
}
