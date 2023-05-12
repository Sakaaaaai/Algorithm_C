#include <stdio.h>

#define N 8
#define MAX 15
#define NIL -1

int q[N][N], row[N], col[N];
int dpos[MAX], dneg[MAX];

void Print(void)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (row[i] == j)
                printf("Q");
            else
                printf(".");
        }
        printf("\n");
    }
}

void Put(int i)
{
    int j;
    int a;

    if (i == N)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (q[i][j] == 1)
                {
                    if (row[i] != j)
                        return;
                }
            }
        }

        Print();

        return;
    }

    for (a = 0; a < N; a++)
    {
        if (col[a] == NIL || dpos[i + a] == NIL || dneg[i - a + 7] == NIL)
            continue;

        row[i] = a;

        col[a] = NIL;
        dpos[i + a] = NIL;
        dneg[i - a + 7] = NIL;

        Put(i + 1);

        row[i] = 1;
        col[a] = 1;
        dpos[i + a] = 1;
        dneg[i - a + 7] = 1;
    }
}

int main()
{
    int i, j, k;
    int r, c;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            q[i][j] = NIL;
        }
    }

    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &r, &c);
        q[r][c] = 1;
    }

    Put(0);

    return 0;
}

