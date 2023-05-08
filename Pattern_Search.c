/*
input
4 5
00010
00101
00010
00100
3 2
10
01
10

output
0 3
1 2
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int ull;

const ull B1 = 9973;
const ull B2 = 100000007;

int main()
{
  int i, h, w, r, c, j;
  ull t1, t2, e;
  fscanf(stdin, "%d %d\n", &h, &w);
  char a[h][w+3];
  for (i=0; i<h; i++)  fgets(a[i], w+2, stdin);
  fscanf(stdin, "%d %d\n", &r, &c);
  char b[c+3];
  ull bh, tmp;
  bh = 0;
  t2 = 1;
  for (i=0; i<r; i++) {
    fgets(b, c+2, stdin);
    tmp = 0;
    for (j=0; j<c; j++) tmp = tmp * B1 + b[j];
    bh = bh * B2 + tmp;
    t2 *= B2;
  }

  ull *tmp2 = (ull*)malloc(sizeof(ull)*h*w);
  
  for (j=0; j<w; j++) {
    e = a[0][j];
    for (i=1; i<r; i++)   e = e * B2 + a[i][j];
    for (i=0; i+r<=h; i++) {
      *(tmp2+i*w+j) = e;
      if (i+r<h) e = e * B2 - t2 * a[i][j] + a[i+r][j];
    }
  }
  t1 = B1;
  for (i=1; i<c; i++) t1 *= B1;
  for (i=0; i+r<=h; i++) {
    e = *(tmp2+i*w);
    for (j=1; j<c; j++)  e = e*B1 + *(tmp2+i*w+j);
    for (j=0; j+c<=w; j++) {
      if (e==bh) printf("%d %d\n", i, j);
      if (j+c<w) e = e*B1 - t1 * *(tmp2+i*w+j) + *(tmp2+i*w+j+c);
    }
  
  }
  return 0;
}

