#include <stdio.h>
#include <stdlib.h>

enum{MAX_LEN = 81};

int main()
{
    FILE *f;
    char s[MAX_LEN];
    int count = 1;

    if ((f = fopen("INPUT.inp", "r+")) == NULL)
    {
        printf("Error! Cannot open file");
        return 1;
    }

    while (fgets(s, MAX_LEN, f) != NULL)
    {
        printf("%d ", count);
        count ++;
        printf("%s", s);
    }

    printf("\n\n");

    return 0;
}
