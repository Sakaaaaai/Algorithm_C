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
