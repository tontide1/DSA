#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

void nhapMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void phatSinhMang(int a[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand();
    }
}
void xuatMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
int ghiFile(const char* filename, int a[], int n){
    FILE* f = fopen(filename, "w");
    if(!f)
        return 0;

    for(int i = 0; i < n; i++)
        fprintf(f, "%d\n", a[i]);

    fclose(f);
    return 1;
}
int docFile(const char* filename, int a[], int n){
    FILE* f = fopen(filename, "r");
    if(!f)
        return 0;
    for (int i = 0; i < n; ++i)
    {
        fscanf(f, "%d ", &a[i]);
    }
    fclose(f);
    return 1;
}
int main(){
    int n = 10, a[10001];
    // phatSinhMang(a,n);
    nhapMang(a,n);
    ghiFile("ghi.txt", a, n);
    return 0;
}