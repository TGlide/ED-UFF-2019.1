#include <stdio.h>
#include <stdlib.h>

void reverseArray(char *array, int size)
{
    for (int idx = 0; idx < size / 2; idx++)
    {
        char temp = array[idx];
        array[idx] = array[size - idx - 1];
        array[size - idx - 1] = temp;
    }
}

char *binary(int n)
{
    int aux = n; // Holds result of successive divisions
    int init_cap = 128;
    char *res = malloc(init_cap * sizeof(char));
    int res_idx = 0;

    while (aux > 0)
    {
        res[res_idx] = (char)(aux % 2);
        aux /= 2;
        res_idx++;
    }

    reverseArray(res, res_idx);

    for (int i = 0; i < res_idx; i++)
    {
        printf("%d", res[i]);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    while (1){
        printf("Digite n: ");
        scanf("%d", &n);

        binary(n);
        puts("\n");
        
    }
    return 0;
}
