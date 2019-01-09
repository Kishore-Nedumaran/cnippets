#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int n, i, j;
    do
    {
        printf("Height: ");
        n = get_int();                  //gets input
    }
    while (n < 0 || n > 23);

    for (i = 1; i <= n; i++)
    {
        for (j = n - i; j > 0; j--)
        {
            printf(" ");
        }
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
