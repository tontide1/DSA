#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    node* link;
};
struct list {
    node* first;
    node* last;
};

void init(list& l) {
    l.first = l.last = NULL;
}
node* getNode(int x) {
    node* p = new node;
    if (p == NULL)
        return NULL;

    p->data = x;
    p->link = NULL;

    return p;
}
void addFirst(list &l, node *p){ 
    if(l.first == NULL){ // Kiem tra phan dau co rong
        l.first = l.last = p;
    }
    else{
        p->link = l.first;
        l.first = p;
    }
}
void addLast(list& l, node* p) {
    if (l.first == NULL) {
        l.first = p;
        l.last = p;
    } else {
        l.last->link = p;
        l.last = p;
    }
}
void insertFirst(list &l, int x){
    node *p = getNode(x); // khoi tao node X
    if(p == NULL)
        return;
    
    addFirst(l,p);
}
void insertLast(list& l, int x) {
    node* p = getNode(x);
    if (p == NULL)
        return;

    addLast(l, p);
}
void insertAt(list &l, int k, int x){
    if (k < 0) 
        return;
    
    if (k == 0) {
        insertFirst(l, x);
        return;
    }

    node *p = l.first;
    for (int i = 0; i < k - 1; i++) {
        if (p == NULL) {
            // printf("Vi tri chen khong hop le.\n");
            return;
        }
        p = p->link;
    }

    if (p == NULL) {
        // printf("Vi tri chen khong hop le.\n");
        return;
    }

    node *temp = new node;
    temp->data = x;
    temp->link = p->link;
    p->link = temp;

    if (p == l.last) {
        l.last = temp;
    }
}
void removeFirst(list &l, int &x){
    if(l.first == NULL)
        return;
    else{
        node *p = l.first;
        x = p->data;
        l.first = p->link;
        delete(p);
        if(l.first == NULL){
            l.last = NULL;
        }
        return;
    }
}
void printList(list l) {
    for (node* p = l.first; p != NULL; p = p->link)
        printf("%d ", p->data);
}

int main() {
    list l;
    init(l);
    int n, k, x;
    scanf("%d", &n);

    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        insertLast(l, tmp);
    }
    scanf("%d %d", &k, &x);
    insertAt(l, k, x);
    printList(l);
    
    removeFirst(l,x);
    printList(l);

    return 0;
}
