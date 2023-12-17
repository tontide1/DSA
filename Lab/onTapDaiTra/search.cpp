#include <stdio.h>
#include <stdlib.h>

// binary Search
int binarySearch(int a[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == key)
            return 1;  // Trả về 1 khi tìm thấy
        else if (a[mid] > key)
            right = mid - 1;
        else if (a[mid] < key)
            left = mid + 1;
    }
    return 0;  // Trả về 0 khi không tìm thấy
}
int binarySearch_rec(int a[], int left, int right, int key){
    if(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == key)
            return 1;
        else if(a[mid] > key)
            return binarySearch_rec(a, left, mid - 1, key);
        else if(a[mid] < key)
            return binarySearch_rec(a, mid + 1, right, key);
    }else
        return 0;
}
int main(){
    int a[] = {1, 3, 7, 8, 10, 12, 19, 20};
    printf("%d %d", binarySearch(a, 0, 7, 3), binarySearch_rec(a, 0, 7, 3));
    return 0;
}