#include <stdio.h>

int main(){
    int a[1001], n, k ,x;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) scanf("%d", &a[i]);

    scanf("%d %d", &k, &x);
    for(int i = n - 1; i >= k; i--){
        a[i+1]= a[i];
    }
    ++n;
    a[k] = x;
    for(int i = 0; i<n; i++) printf("%d ", a[i]);    
    return 0;
}