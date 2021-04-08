#include <stdio.h>
#include <stdlib.h>

int row, col;
int a[9][9];

void solution()
{

    for (row = 0; row  < 9; row ++)
    {

        for (col = 0; col < 9; col ++)
            printf(" %d ", a[row][col]);

        printf("\n");
    }

  printf("\n\n");

}

int check(int crow, int ccol){

    int i, j;

    for (i = 0; i < crow; i++)
        if (a[i][ccol] == a[crow][ccol])
            return 0;

    for (j = 0; j < ccol; j++)
        if (a[crow][j] == a[crow][ccol])
            return 0;

    for (i = crow/3*3; i <= crow; i++)
    {
        if (crow == i)
            continue;
        for (j = ccol/3*3; j <= ccol/3*3 + 2; j++)
        {
            if (ccol == j)
                continue;
            if (a[i][j] == a[crow][ccol])
                return 0;
        }
    }
    return 1;
}

void Try(int row, int col)
{

    int i;

    for(i = 1; i <= 9; i++)
    {
        a[row][col] = i;

        if (check(row, col))
        {
            if (col < 8)
                Try(row, col+1);

            else
            {
                if(row < 8)
                    Try(row+1, 0);
                else
                    solution();
            }
        }
    }
}

int main()
{
    Try(0, 0);
    return 0;
}
