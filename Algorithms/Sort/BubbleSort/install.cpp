#undef _GLIBCXX_DEBUG
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
void phatSinhMang(long long a[], long long n)
{
    srand(time(NULL));
    for (long long i = 0; i < n; i++)
    {
        a[i] = rand();
    }
}
void BubbleSort(long long a[], long long n)
{
    for (long long i = 0; i < n - 1; i++)
    {
        for (long long j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}
int main()
{
    long long a[100001], n = 100000;
    // scanf("%d", &n);
    // for(int i = 0; i<n; i++) scanf("%d", &a[i]);
    phatSinhMang(a, n);
    BubbleSort(a, n);

    for (long long i = 0; i < n; i++)
        printf("%lld ", a[i]);

    return 0;
}