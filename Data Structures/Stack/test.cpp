#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initStack(Stack *stack) {
    stack->top = NULL;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int index) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->index = index;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    Node *node = stack->top;
    stack->top = node->next;
    int index = node->index;
    free(node);
    return index;
}

int main() {
    int n, s;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &s);

    int maxLength = -1; // Độ dài đoạn con liên tiếp dài nhất có tổng bằng S
    int left = 0; // Vị trí bắt đầu của đoạn con liên tiếp
    int currentSum = 0; // Tổng của đoạn con liên tiếp hiện tại

    Stack myStack;
    initStack(&myStack);

    for (int right = 0; right < n; right++) {
        currentSum += a[right];
        push(&myStack, right);

        while (currentSum > s) {
            currentSum -= a[left];
            left++;
            // pop(&myStack);
        }

        if (currentSum == s) {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
    }

    printf("%d", maxLength);

    return 0;
}
