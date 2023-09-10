#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10001], n, cnt = 0, k;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &k);
    for(int i = 0; i < n; ++i){
        if(a[i] == k)
            cnt++;
    }
    printf("%d", cnt);    
    return 0;
}