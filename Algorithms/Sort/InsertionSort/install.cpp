#include <stdio.h>

void insertionSort(int a[], int n){
    int index, tmp;
    for(int i = 1; i < n; i++){
        index = i;
        tmp = a[i];
        while(index > 0 && a[index - 1] > tmp){
            a[index] = a[index -1]; 
            --index;
        }
        a[index] = tmp;
    }
}

int main(){
    int a[10001], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    insertionSort(a,n);

    for(int i = 0; i < n; i++) printf("%d ",a[i]);
    
    return 0;
}