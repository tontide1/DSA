#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int linearSearch_caiTien(int a[], int n, int x){
    int i = 0;
    a[n] = x;
    while(a[i] != x)
        i++;
    if(i == n)
        return -1;
    else
        return 1;
}

int main(){
    int a[5] = {1, 7, 8 ,9, 10}, n = 5, x = 9;
    printf("%d", linearSearch_caiTien(a,n,x));
    return 0;
}

/*Gán phần tử a[n]=x, mảng a có thêm phần tử cuối cùng là x. Do đó, khi tìm x trong mảng a thì chắc chắn sẽ tìm thấy. Nhưng nếu tìm thấy x ở vị trí cuối cùng n thì coi như không tìm thấy x. Nếu tìm thấy x ở vị trí khác n (từ 0 đến n-1) thì có nghĩa là tìm thấy x.*/