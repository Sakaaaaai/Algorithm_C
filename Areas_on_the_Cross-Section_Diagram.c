/*
input
\///\_/\/\\/_/\///__\\_\/_\/_/\

output
35
5 4 2 1 19 9
*/

#include <stdio.h>
#include <string.h>

#define N 20001

int total[N];

void Print(int area, int num)
{
    int i;

    printf("%d\n%d", area, num);

    for (i = 0; i < num; i++)

        printf(" %d", total[i]);

    putchar('\n');
}

int main()
{
    int i, j, k;
    int len, volume[N], depth_2[N], higth[N];
    int depth = 0, min = 0, max = 0, area = 0, num = 0;

    char str[N];

    scanf("%s\n", str);

    len = strlen(str);

    for (i = 0; i < len; i++)
    {

        if (str[i] == '/')
        {

            depth++;

            if (max < depth)
                max = depth;
        }

        else if (str[i] == '\\')
            depth--;

        if (min > depth)
            min = depth;
    }

    min *= -1;

    max += min;

    volume[0] = min;

    for (i = 0; str[i] != '\0'; i++)
    {

        if (str[i] == '/'){
            min++;
            volume[i + 1] = min;
        }

        else if (str[i] == '\\'){
            min--;
            volume[i + 1] = min;
        }

        else
            volume[i + 1] = volume[i];
    }

    for (i = 0; i < max + 1; i++)

        higth[i] = -1;

    for (i = 0; i < len; i++)
        depth_2[i] = 0;

    for (i = 0; i < len; i++)
    {
        if (str[i] == '\\')
        {
            higth[volume[i]] = i;
        }

        else if (str[i] == '/')
        {
            if (higth[volume[i + 1]] != -1)
            {
                area += i - higth[volume[i + 1]];

                for (j = higth[volume[i + 1]]; j < i; j++)
                {
                    depth_2[j] += 1;
                }
            }
        }
    }

    for (i = 0; i < len; i++)
        total[i] = 0;

    for (i = 0; i < len; i++)
    {
        total[num] += depth_2[i];
        
        if (total[num] > 0 && depth_2[i] == 0)
            num++;
    }

    Print(area, num);

    return 0;
}
