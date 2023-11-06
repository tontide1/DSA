#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
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
void push(stack &s, char x){
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
char pop(stack &s){
    if(!isEmpty(s)){
        node *p = s.top;
        char x = p->data; // luu lai gia tri cua node truoc khi xao
        s.top = p->link;
        delete(p);
        return x;
    }
}
void deleteSpace(char c[]){
    if(c[strlen(c) - 1] == '\n')
        c[strlen(c) - 1] = '\0';
}
int main(int argc, char const *argv[])
{
    stack s;
    initStack(s);
    char string[100];
    fgets(string,100,stdin);
    deleteSpace(string);
    int len = strlen(string);

    for(int i = 0; i < len; i++){
        push(s,string[i]);
    }
    while(!isEmpty(s))
        printf("%c", pop(s));
    return 0;
}