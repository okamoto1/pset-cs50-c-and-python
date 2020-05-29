#include <stdio.h>
#include <cs50.h>

void mario(int n, int m);

int main(void)
{
    int n = get_int("Heigh: ");
    mario(n, 0);
}

void mario(int n, int m)
{
    if (n == 0)
    {
        return;
    }
    mario(n - 1, m + 1);
    for (int i = 0; i < m; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}