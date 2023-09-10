#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[1001], n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for (int i = k; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    --n;
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    system("pause");
    return 0;
}