#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int interpolationSearch(int a[], int right, int left, int key){
    while(left != right and key <= a[right] and key >= a[left]){
        int mid = left + (right - left) * (key - a[left]) / (a[right] - a[left]);
        if(key == a[mid])
            return 1;
        if(key < a[mid])
            right = mid - 1;
        if(key > a[mid])
            left = mid + 1;
    }
    return -1;
}

int main(){
    int a[] = {1, 6, 8, 9, 13}, n = 5, x = 9;
    printf("%d", interpolationSearch(a, n - 1, 0, x));
    return 0;
}