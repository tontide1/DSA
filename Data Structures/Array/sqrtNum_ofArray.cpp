#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (a + i));
    }
    for (int i = 0; i < n; i++)
        printf("%d ", pow(*(a + i), 2));
    free(a);
    return 0;
}