#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int binarySearch(int a[], int n, int key){
    int left = 0, right = n-1, res = -1;
    while(left <= right){
        int m = left + (right-left)/2;
        if(a[m] == key){
            res = m; // trả về index của key tìm đc
            right = m - 1;
        }
        else if(a[m] < key)
            left = m + 1;
        else
            right = m - 1;
    }
    return res;
}
int binarySearch_recursion(int a[], int left, int right, int key){
    if(left > right)
    return -1;
    int mid = left + (right - left)/2;
    if(a[mid] == key)
        return 1;
    if(key < a[mid])
        return binarySearch_recursion(a,left,mid - 1,key);
    if(key > a[mid])
        return binarySearch_recursion(a,mid + 1, right, key);
}
int main(){
    int a[10001], n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &x);

    printf("%d", binarySearch_recursion(a,0,n-1,x));
    return 0;
}