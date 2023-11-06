#include <stdio.h>
#include <stdlib.h>

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
    if(p!=NULL){
        p->data = x;
        p->link = NULL;

        if(isEmpty(s))
            s.top = p;
        else{
            p->link = s.top;
            s.top = p;
        }
    }
}
int pop(stack &s){
    if(!isEmpty(s)){
        node *p = s.top;
        int x = p->data; // luu lai gia tri cua node truoc khi xao
        s.top = p->link;
        delete(p);
        return x;
    }
}

int main(int argc, char const *argv[])
{
    stack s;
    initStack(s);

    int n, a[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        push(s,a[i]);
    }

    while(!isEmpty(s)){
        printf("%d ", pop(s));
    }
    return 0;
}