#include <stdio.h>
//mảng tổng tích lũy kết hợp với binary search
int binarySearch(int a[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, s;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &s);

    int sum[n];
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 0; i < n; i++) {
        int target = s + (i == 0 ? 0 : sum[i - 1]);
        /*
        target  = 5 + 0 = 5 => idx = -1
                = 5 + 1 = 6 => idx = 2
        */
        int idx = binarySearch(sum, i, n - 1, target);
        // printf("%d\n", idx);
        if (idx != -1) {
            for (int j = i; j <= idx; j++) {
                printf("%d ", a[j]);
            }
            return 0;
        }
    }

    printf("-1");

    return 0;
}
/*/
Cho số nguyên dương n, tiếp theo là n số nguyên dương của một dãy a, cuối cùng là một số s.

Hãy đưa ra dãy con liên tiếp đầu tiên của dãy a sao cho tổng của dãy đó bằng s. In dãy đó ra màn hình,
sau mỗi phần tử có một khoảng trắng. Nếu không tồn tại dãy đó thì in ra "-1".
Input:[1,2,3,4,5],5
Expected output:"2 3 "

Dãy a: [1, 2, 3, 4, 5]
Mảng sum: [1, 3, 6, 10, 15]
/*/  