#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    long long sum = 0;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (a + i));
        sum += *(a + i);
    }
    printf("%lld", sum);
    return 0;
}