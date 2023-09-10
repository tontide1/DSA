#include <stdio.h>


int main()
{
    int a[50], n;   
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int increase = 1, reduce = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
            reduce = 0;
        else if (a[i] <= a[i - 1])
            increase = 0;
    }
    
    if (reduce == 1 || increase == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}