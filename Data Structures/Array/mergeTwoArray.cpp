#include <stdio.h>

int main()
{
    int a[50], b[50], c[101];
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int j = 0; j < m; j++)
        scanf("%d", &b[j]);

    int e = n + m;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] >= b[j])
        {
            c[k++] = b[j++];
        }
        else
        {
            c[k++] = a[i++];
        }
    }
    while (i < n)
    {
        c[k++] = a[i++];
    }
    while (j < m)
    {
        c[k++] = b[j++];
    }
    for (int k = 0; k < e; k++)
        printf("%d ", c[k]);
    return 0;
}