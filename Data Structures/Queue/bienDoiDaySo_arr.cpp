#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
using namespace std;


int main(){
    int n;
    // queue<int>q;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        b[i] = 0;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    // int temp;
    b[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        b[i] = a[i];
        if(i > 2){
            swap()
        }
    }
    for(int i = 0; i < n; ++i){
        // printf("%d ", a[i]);
        printf("%d ", b[i]);
    }
    return 0;
}