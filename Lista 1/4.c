#include <stdio.h>

int isPrime(int n)
{
    for (int i = n - 1; i > 1; i--)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    // TODO: Make more efficient
    int n, count;
    while (1)
    {
        count = 0;
        printf("Digite n: ");
        scanf("%d", &n);

        for (int i = n + 1; count < n; i++)
            if (isPrime(i))
            {
                printf("%d ", i);
                count++;
            }
        puts("\n");
    }

    return 0;
}
