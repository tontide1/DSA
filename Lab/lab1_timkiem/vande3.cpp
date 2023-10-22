#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch_recursion(int a[], int l, int r, int x) {
    if (l > r)
        return -1;
    int m = l + (r - l) / 2;
    if (a[m] == x)
        return 1;
    else if (x < a[m])
        return binarySearch_recursion(a, l, m - 1, x);
    else
        return binarySearch_recursion(a, m + 1, r, x);
}

void phatSinhMangTang(int a[], int n) {
    srand(time(NULL));
    a[0] = rand() % 50 + 1;
    for (int i = 1; i < n; i++) {
        a[i] = rand() % 10 + a[i - 1];
    }
}

int main() {
    int n, x;
    scanf("%d", &n);
    int a[n];
    phatSinhMangTang(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    scanf("%d", &x);
    printf("%d", binarySearch_recursion(a, 0, n - 1, x));
    return 0;
}
