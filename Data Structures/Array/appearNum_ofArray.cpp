#include <stdio.h>
#include <math.h>

void bubbleSort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int a[1001], n;
    int cnt[1001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    for (int i = 0; i < 1001; i++)
    {
        if (cnt[i] > 0)
            printf("%d - %d; ", i, cnt[i]);
    }
    return 0;
}
