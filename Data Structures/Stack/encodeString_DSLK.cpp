#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct node
{
    char data;
    node *next;
};
struct stack
{
    node *top;
};
void initStack(stack &s){
    s.top = NULL;
}
int isEmpty(stack s){
    return s.top == NULL ? 1 : 0;
}
char top(stack s){
    return s.top->data;
}
int sizeStack(stack s){
    int count = 0;
    node* current = s.top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void push(stack &s, char c){
    node *p = new node;
    if(p != NULL){
        p->data = c;
        p->next = NULL;

        if(isEmpty(s)){
            s.top = p;
        }else{
            p->next = s.top;
            s.top = p;
        }
    }
}
char pop(stack &s){
    char tmp;
    if(!isEmpty(s)){
        node *p = s.top;
        tmp = p->data;
        s.top = p->next;
        delete (p);
    }
    return tmp;
}
void encodeString(const char s[]){
    char res[1000] = "";
    stack st;
    initStack(st);

    for (int i = 0; i < (int)strlen(s); i++){
        if(isEmpty(st) || top(st) == s[i]){
            push(st, s[i]);
        }else{
            char temp[2];
            temp[0] = top(st);
            temp[1] = '\0';
            strcat(res, temp);
            char sizeStr[5];
            sprintf(sizeStr, "%d", sizeStack(st));
            strcat(res, sizeStr);
            while(!isEmpty(st)){
                pop(st);
            }
            push(st, s[i]);
        }
    }
    if(!isEmpty(st)){
            char temp[2];
            temp[0] = top(st);
            temp[1] = '\0';
            strcat(res, temp);
            char sizeStr[5];
            sprintf(sizeStr, "%d", sizeStack(st));
            strcat(res, sizeStr);
    }

    puts(res);
}
// string encodeString(const string& s) {
//     string result = "";
//     stack<char> st;

//     for (char c : s) {
//         if (st.empty() || st.top() == c) {
//             st.push(c);
//         } else {
//             result += st.top() + to_string(st.size());
//             while (!st.empty()) {
//                 st.pop();
//             }
//             st.push(c);
//         }
//     }

//     if (!st.empty()) {
//         result += st.top() + to_string(st.size());
//     }

//     return result;
// }
int main(int argc, char const *argv[])
{
    char s[100];
    gets(s);
    encodeString(s);
    return 0;
}
