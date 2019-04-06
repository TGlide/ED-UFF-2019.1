#include <stdio.h>

int main(void)
{
    int n, m, res = 1;

    while (1)
    {
        printf("Digite n: ");
        scanf("%d", &n);

        printf("Digite m: ");
        scanf("%d", &m);

        do
        {
            printf("%d ", res);
            res *= m;
        } while (res < n);

        puts("\n");
    }

    return 0;
}