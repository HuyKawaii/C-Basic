#include <stdio.h>
#include <stdlib.h>

enum{Q_NUM = 8};

int k;
int x[Q_NUM]; // (i, x[i]) is coordinate of the i_th Queen

void solution(){
  int i;

  for (i = 0; i < Q_NUM; i++)
    printf("(%d, %d)  ", i+1, x[i] + 1);

  printf("\n\n");
}

int check(int k){
  int i;
                     // never capture in row
  for (i = 0; i < k; i++){
    if(x[i] == x[k]) // check in capture in column
        return 0;
    if(((i - k) == (x[i] - x[k])) || ((k - i) == (x[i] - x[k]))) // check if capture in diagonal
        return 0;
  }
  return 1;
}

void Try(int k){
  int i;

  for (i = 0; i < 8; i++){
    x[k] = i;
    if (check(k)){
      if (k == 7)
        solution();
      else
        Try(k+1);
    }
  }
}

int main()
{
    Try(0);
    return 0;
}
