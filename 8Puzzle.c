/*
input
1 3 0
4 2 5
7 8 6

output
4
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NIL -1
#define MAX 99

int A[4] = {0, -1, 0, 1};
int B[4] = {1, 0, -1, 0};

int c = 0;

int array[3][3];

void swap(int y_2, int x_2, int y, int x)
{

    int tmp;

    tmp = array[y_2][x_2];
    array[y_2][x_2] = array[y][x];
    array[y][x] = tmp;
}

int cal()
{
    int i, j;
    int z = 0, x;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (array[i][j] == 0)
                continue;

            x = array[i][j] - 1;

            z += abs(x / 3 - i) + abs(x % 3 - j);
        }
    }
    return z;
}

int Df(int d, int p, int y, int x)
{
    int i;
    int num, y_2, x_2, tmp;

    num = cal();

    if (num == 0)
        return 1;
    else if (d + num > c)
        return 0;

    for (i = 0; i < 4; i++)
    {
        if (abs(i - p) == 2)
            continue;

        x_2 = x + A[i];
        y_2 = y + B[i];

        if (x_2 < 0 || y_2 < 0 || x_2 >= 3 || y_2 >= 3)
            continue;

        swap(y_2, x_2, y, x);

        if (Df(d + 1, i, y_2, x_2))
            return 1;

        swap(y_2, x_2, y, x);

    }
    return 0;
}


int main()
{
    int i, j;
    int x, y;


    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &array[i][j]);
            if (array[i][j] == 0)
            {
                y = i;
                x = j;
            }
        }
    }


    while (1)
    {
        if (Df(0, MAX, y, x))
        {
            printf("%d\n", c);
            break;
        }
        c++;
    }
    return 0;
}

