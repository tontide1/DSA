#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct STACK {
    int arr[MAX_SIZE];
    int top;
} S;

int isEmpty(S *stack) {
    return (stack->top == -1);
}

void push(S *stack, int n) {
    stack->top++;
    stack->arr[stack->top] = n;
}

int pop(S *stack) {
    int tmp = stack->arr[stack->top];
    stack->top--;
    return tmp;
}

int main() {
    int n, s;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &s);
    int maxLength = -1; // Độ dài đoạn con liên tiếp dài nhất có tổng bằng S
    int currentIndex = 0; // Vị trí bắt đầu của đoạn con liên tiếp
    int currentSum = 0; // Tổng của đoạn con liên tiếp hiện tại

    for (int i = 0; i < n; ++i)
    {
        currentSum += a[i];

        while(currentSum > s){
            currentSum -= a[currentIndex];
            currentIndex++;
            // pop(&myStack);
        }

        if (currentSum == s) {
            int currentLength = i - currentIndex + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
    }
    printf("%d", maxLength);
    free(a);
    return 0;
}
/*/
Cho số nguyên dương n, tiếp theo là n số nguyên dương của một dãy a, cuối cùng là một số s. (! các phần tử con chưa được sắp xếp nên không thử sử dụng thuật toán binarySearch)

Hãy đưa ra dãy con liên tiếp đầu tiên của dãy a sao cho tổng của dãy đó bằng s. In dãy đó ra màn hình,
sau mỗi phần tử có một khoảng trắng. Nếu không tồn tại dãy đó thì in ra "-1".
Input:[1,2,3,4,5],5
Expected output:"2 3 "

Dãy a: [1, 2, 3, 4, 5]
Mảng sum: [1, 3, 6, 10, 15]
/*/  