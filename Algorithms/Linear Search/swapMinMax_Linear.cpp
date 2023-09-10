#include <stdio.h>

int search_Min(int a[], int n){
    int Min = 0; // gán index số nhỏ nhất là phần tử đầu tiên
    for (int i = 1; i < n; ++i)
    {
        if(a[i] < a[Min]){
            Min = i;
        }
    }
    return Min;
}
int search_Max(int a[], int n){
    int Max = 0; // gán index số nhỏ nhất là phần tử đầu tiên
    for (int i = 1; i < n; ++i)
    {
        if(a[i] >= a[Max]){
            Max = i;
        }
    }
    return Max;
}
int main(int argc, char const *argv[])
{
    int a[10001], n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int temp;
    temp = a[search_Max(a,n)];
    a[search_Max(a,n)] = a[search_Min(a,n)];
    a[search_Min(a,n)] = temp;
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    return 0;
}