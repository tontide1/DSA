#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
//  khởi tạo cấu trúc Stack
typedef struct Stack
{
    int top = -1;
    int arr[MAX];
}S;

// void createStack(S *stack){
//     stack->top = -1;
// }
int isFull(S *stack){
    return stack->top == MAX - 1; // mảng đi từ 0 -> n-1
}
int isEmpty(S *stack){
    return stack->top == -1;
}
void push(S *stack, int item){
    if(isFull(stack)){
        printf("STACK IS FULL \n");
        return;
    }
    stack->top++; // tăng kích cỡ của stack
    stack->arr[stack->top] = item; // chèn phần từ  vào vị trí mới tăng của stack 
}
int pop(S *stack){
    if(isEmpty(stack)){
        printf("STACK IS EMPTY\n");
        return -1; // giá trị thể hiện stack đang rỗng
    }
    int item = stack->arr[stack->top];
    stack->top--;
    return item;
}
int peek(S *stack){
    if(isEmpty(stack)){
        printf("STACK IS EMPTY\n");
        return -1;
    }
    int item = stack->arr[stack->top];
    return item;
}
int main()
{
    S myStack;
    // createStack(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top of the stack: %d\n", peek(&myStack));

    printf("Popped item: %d\n", pop(&myStack));
    printf("Popped item: %d\n", pop(&myStack));

    printf("Top of the stack after popping: %d\n", peek(&myStack));
    printf("Popped item: %d\n", pop(&myStack));


    return 0;
}