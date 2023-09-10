#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

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
    int T;
    scanf("%d", &T);

    int *input = (int *)malloc(T * sizeof(int));
    for (int t = 0; t < T; t++) {
        scanf("%d", &input[t]);
    }

    for (int t = 0; t < T; t++) {
        S myStack;
        myStack.top = -1;

        int n = input[t];

        if (n == 0) {
            printf("0\n");
            continue;
        }

        while (n > 0) {
            push(&myStack, n % 2);
            n /= 2;
        }

        while (!isEmpty(&myStack)) {
            printf("%d", pop(&myStack));
        }

        printf("\n");
    }

    free(input);
    return 0;
}
