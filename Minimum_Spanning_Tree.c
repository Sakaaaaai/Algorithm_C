#include <stdio.h>

#define White 0
#define Gray 1
#define Black 2
#define INFINITY 100000
#define NIL -1

#define N 101

int graf[N][N],color[N], data_1[N], data_2[N];

int count_Answer(int n)
{
    int i, count = 0;

    for (i = 0; i < n; i++)
    {
        if (data_2[i] != NIL)
            count += graf[i][data_2[i]];
    }
    return count;
}

int main()
{
    int i, j, k;
    int n, count = 0;
    int min, tmp;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &graf[i][j]);
    }

    for (i = 0; i < n; i++)
    {
        color[i] = White;
        data_1[i] = INFINITY;
        data_2[i] = NIL;
    }

    data_1[0] = 0;

    for (;;)
    {
        min = INFINITY;

        for (i = 0; i < n; i++)
        {
            if (color[i] != Black)
            {
                if (data_1[i] < min)
                {
                    min = data_1[i];
                    tmp = i;
                }
            }
        }

        if (min == INFINITY)
            break;

        color[tmp] = Black;

        for (i = 0; i < n; i++)
        {
            if (graf[tmp][i] != NIL)
            {
                if (color[i] != Black && graf[tmp][i] < data_1[i])
                {

                    data_2[i] = tmp;
                    data_1[i] = graf[tmp][i];

                    color[i] = Gray;
                }
            }
        }
    }

    count = count_Answer(n);

    printf("%d\n", count);

    return 0;
}

