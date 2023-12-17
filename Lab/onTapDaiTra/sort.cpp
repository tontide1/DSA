#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
//interchange sort
void interchangeSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
//bubble sort
void bubbleSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = n-1; j > i; j--){
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
        }
    }
}
//insertSort
void insertSort(int a[], int n){
    int pos, x;
    for (int i = 1; i < n; i++){
        x = a[i];
        pos = i - 1;
        while (pos >= 0 && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}
int main() {
    // Thiết lập seed cho hàm rand()
    srand(time(NULL));

    // Khai báo mảng và kích thước
    const int size = 20;
    int arr[size];

    // Điền mảng với giá trị ngẫu nhiên
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 51;
    }

    // In giá trị mảng
    // interchangeSort(arr, size);
insertSort(arr, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}