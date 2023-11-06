#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    node *link;
};
struct stack{
    node *top;
};
void initStack(stack &s){
    s.top = NULL;
}
int isEmpty(stack s){
    return s.top == NULL ? 1 : 0;
}
void push(stack &s, int x){
    node *p = new node;
    if(p != NULL){
        p->data = x;
        p->link = NULL;

        if(isEmpty(s)){
            s.top = p;
        }else{
            p->link = s.top;
            s.top = p;
        }
    }
}
int pop(stack &s){
    int temp;
    if(!isEmpty(s)){
        node *p = s.top;
        temp = p->data;
        s.top = p->link;
        delete(p);
    }
    return temp;
}

int main(){
    stack s;
    initStack(s);
    int n;
    scanf("%d", &n);

    while(n!=0){
        int tmp = n % 2;
        push(s, tmp);
        n = n / 2;
    }
    while(!isEmpty(s)){
        printf("%d", pop(s));
    }

    return 0;
}