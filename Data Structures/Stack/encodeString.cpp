#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct STACK
{
    int top;
    char string[MAX];
} S;

void createStack(S *stack)
{
    stack->top = -1;
}

int isFull(S *stack)
{    
    return stack->top == MAX - 1;
}

int isEmpty(S *stack)
{
    return stack->top == -1;
}

void push(S *stack, char c)
{
    if (isFull(stack))
    {
        printf("STACK IS FULL\n");
        return;
    }
    stack->top++;
    stack->string[stack->top] = c;
}

char pop(S *stack)
{
    if (isEmpty(stack))
    {
        printf("STACK IS EMPTY\n");
        return '\0'; //kết thúc chuỗi
    }
    char item = stack->string[stack->top];
    stack->top--;
    return item;
}

void deletedSpace(char c[])
{
    if (c[strlen(c) - 1] == '\n')
        c[strlen(c) - 1] = '\0';
}
void Mahoa(char a[], S *encodedString)
{
    int count=0;
    for(int i=0;i <= (int)strlen(a); i++) // ta cần kiểm tra <= len của chuỗi để đảm bảo kết thúc là '\0'
    {
        /*
        cần kt xem stack rỗng hay không.
        Nếu rỗng ta bắt đầu xử lý print và chèn phần tử đầu vào stack
        */ 
        if(isEmpty(encodedString)||a[i] == encodedString->string[encodedString->top])
        {   
            count++;
            if(count==1)
            {
                printf("%c",a[i]);
            }
            push(encodedString, a[i]);
        }
        else 
        {
            printf("%d",count);
            push(encodedString, a[i]);
            count=1;
            if(count==1)
            {
                printf("%c",a[i]);
            }
        }
    }      
}
int main()
{
    S encodedString;
    char string[MAX];
    createStack(&encodedString);
    fgets(string, MAX, stdin);
    deletedSpace(string);
    Mahoa(string, &encodedString);
    return 0;
}
// đếm số ký tự xuất hiện trong chuỗi