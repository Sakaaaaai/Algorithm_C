/*
input
13
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0

output
node 0: parent = -1, depth = 0, root, [1, 4, 10]
node 1: parent = 0, depth = 1, internal node, [2, 3]
node 2: parent = 1, depth = 2, leaf, []
node 3: parent = 1, depth = 2, leaf, []
node 4: parent = 0, depth = 1, internal node, [5, 6, 7]
node 5: parent = 4, depth = 2, leaf, []
node 6: parent = 4, depth = 2, leaf, []
node 7: parent = 4, depth = 2, internal node, [8, 9]
node 8: parent = 7, depth = 3, leaf, []
node 9: parent = 7, depth = 3, leaf, []
node 10: parent = 0, depth = 1, internal node, [11, 12]
node 11: parent = 10, depth = 2, leaf, []
node 12: parent = 10, depth = 2, leaf, []
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int parent;
    int depth;
    int k;
    int *c;
} NODE;

NODE node[100000];

void depth_cal(int, int);
void print(int, int, int, int, int *);

int main(void)
{
    int n;
    int id, k, c;
    int root;
    int i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        node[i].parent = -1;
    }
    
    for (i = 0; i < n; i++){
        scanf("%d%d", &id, &k);
        node[id].k = k;
        node[id].c = (int *)malloc(k * sizeof(int));
        for (j = 0; j < k; j++){
            scanf("%d", &node[id].c[j]);
            node[node[id].c[j]].parent = id;
        }
    }
    
    for (root = 0; node[root].parent != -1; root++);
    
    depth_cal(root, 0);
    
    for (i = 0; i < n; i++)print( node[i].parent, node[i].depth, node[i].k, i, node[i].c);
        
    return (0);
}

void depth_cal(int id, int d)
{
    int i;
    
    node[id].depth = d;
    
    for (i = 0; i < node[id].k; i++)depth_cal(node[id].c[i], d + 1);
}

void print(int parent, int depth, int k, int i, int *c)
{

int j;

printf("node %d: parent = %d, depth = %d, ", i, parent, depth);
if (parent == -1){
            printf("root, ");
        }
        else if (k > 0){
            printf("internal node, ");
        }
        else {
            printf("leaf, ");
        }
        printf("[");
        for (j = 0; j < k; j++){
            if (j != 0){
                printf(", ");
            }
            printf("%d", c[j]);
        }
        printf("]\n");
}
