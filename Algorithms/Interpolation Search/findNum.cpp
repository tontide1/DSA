#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int interpolationSearch(int a[], int n, int x){
    int left = 0, right = n - 1;
    while(a[right] != a[left] && x >= a[left] && x <= a[right]){
        int mid = left + (right-left)*(x-a[left])/(a[right]-a[left]);
        if(a[mid] == x)
            return mid;
        else if(a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main(){
    int a[10001], n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &x);
    if(interpolationSearch(a,n,x) > -1)
        printf("%d", interpolationSearch(a,n,x));
    else
        printf("-1");
    return 0;
}