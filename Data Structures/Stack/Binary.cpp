#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct STACK
{
    int top;
    int arr[MAX];
}S;
void createStack(S *stack){
    stack->top = -1;
}
int isEmpty(S *stack){
    return (stack->top == -1);
}
int isFull(S *stack){
    return (stack->top == MAX - 1);
}
void push(S *stack, int n){
    if(isFull(stack)){
        printf("STACK IS FULL");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = n;
}
int pop(S *stack){
    if(isEmpty(stack)){
        printf("STACK IS EMPTY");
        return -1;
    }
    int item = stack->arr[stack->top];
    stack->top--;
    return item;
}
int main()
{
    S binary;
    createStack(&binary);
    int n, temp;
    scanf("%d", &n);
    while(n != 0){
        temp = n % 2;
        push(&binary, temp);
        n = n / 2;
    }
    while(!isEmpty(&binary)){
        printf("%d", pop(&binary));
    }
    return 0;
}