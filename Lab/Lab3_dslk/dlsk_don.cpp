#include <stdio.h>
#include <stdlib.h>
struct NODE{
    int data;
    NODE *next;
};
struct LIST{
    NODE *head;
    NODE *tail;
};

void init_list(LIST &L){
    L.head = L.tail = NULL;
}
NODE *getNode(int x){
    // NODE *newNode = (NODE*)malloc(sizeof(NODE)); // C
    NODE *newNode = new NODE(); //c++
    if(newNode == NULL)
        return NULL;

    newNode->data = x; // gan du lieu cho node
    newNode->next = NULL;

    return newNode;
}
void add_head(LIST &L, NODE *newNode){
    if(L.head == NULL)
        L.head = L.tail = newNode;
    else{
        newNode->next = L.head; // con trỏ node liên kết newNode đến node đầu HEAD
        L.head = newNode; // cập nhập lại head chính là newNode
    }
}
void insert_first(LIST &L, int x){
    NODE *newNode = getNode(x);
    if(newNode == NULL)
        return;

    add_head(L, newNode);
}
void add_tail(LIST &L, NODE *newNode){
    if(L.head == NULL)
        L.head = L.tail = newNode;
    else{
        L.tail->next =newNode;
        L.tail = newNode;
    }
}
void insert_last(LIST &L, int x){
    NODE *newNode = getNode(x);
    if(newNode == NULL)
        return;

    add_tail(L, newNode);
}
// void insert(LIST )
void print_list(LIST L){
    for(NODE *i = L.head; i != NULL; i = i ->next){
        printf("%d ", i->data);
    }
}
int main(){
    LIST l;
    init_list(l);

    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        insert_first(l, x);
    }
    print_list(l);
    return 0;
}