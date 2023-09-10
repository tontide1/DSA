#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct Stack
{
    int top;
    char str[MAX];
}S;
void creatStack(S *stack){
    stack->top = -1;
}
int isEmpty(S *stack){
    return (stack->top == -1);
}
int isFull(S *stack){
    return (stack->top == MAX - 1);
}
void push(S *stack, char c){
    if(isFull(stack)){
        printf("STACK IS FULL \n");
        return; // thoát hàm ngay lập tức
    }
    stack->top++;
    stack->str[stack->top] = c;
}
char pop(S *stack){
    if(isEmpty(stack)){
        printf("STACK IS EMPTY\n");
        return '\0'; // trả về ký tự kết thúc của chuỗi
    }
    char res = stack->str[stack->top];
    stack->top--;
    return res;
}
void deleteSpace(char c[]){
    if(c[strlen(c) - 1] == '\n')
        c[strlen(c) - 1] = '\0';
}
int main()
{
    S reveseString;
    char string[MAX];
    creatStack(&reveseString);
    fgets(string,MAX,stdin);
    deleteSpace(string);

    int len = strlen(string);
    // push từng ký tự vào stack
    for(int i = 0; i < len; i++){
        push(&reveseString, string[i]);
    }
    //pop từng ký tự ra stack
    while(!isEmpty(&reveseString))
        printf("%c", pop(&reveseString));
    return 0;
}