#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    node *link;
};
struct list{
    node *first, *last;
};

void init (list &l){
    l.first = l.last = NULL; 
}
node *getNode(int data){
    node *p = new node;
    if(p == NULL) // khong du bo nho cap phat thi se tra ve NULL
        return NULL; 

    p->data = data;
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
void addLast(list &l, node *p){
    if(l.first == NULL){
        l.first = l.last = p;
    }
    else{
        l.last->link = p; // cho con tro cua last lien ket voi node p
        l.last = p; // cap nhat p la node cua last
    }
}
void insertFirst(list &l, int x){
    node *p = getNode(x); // khoi tao node X
    if(p == NULL)
        return;
    
    addFirst(l,p);
}
void insertLast(list &l, int x){
    node *p = getNode(x);
    if(p == NULL)
        return;
    
    addLast(l,p);
}
node *search(list l, int x){
    for(node *p = l.first; p != NULL; p = p->link){
        if(p->data == x)
            return p;
    }
    return NULL;
}
long sumEvenNum(list l){ // tinh tong cac so chan trong DSLK
    long sum = 0;
    for(node *p = l.first; p != NULL; p=p->link){
        if(p->data % 2 == 0){
            sum += p->data;
        }
    }
    return sum;
}
void insertAfterQ(list &l, node *p){
    int x;
    printf("Nhap gia tri node q: ");
    scanf("%d", &x);
    node *q = getNode(x);

    if (q->data == l.last->data) {
        addLast(l, p);
        return;
    }
    else{
        // Them 1 lan node p sau node q
        for (node *k = l.first; k != NULL; k = k->link) {
            if (q->data == k->data) {
                p->link = k->link;
                k->link = p;
                return;
            }
    }
/*    for(node *k = l.first; k != NULL; k = k->link){
            if(q->data == k->data){
                node *tmp = getNode(p->data);
                node *tmp1 = k->link; // cho node tmp1 tro den node nam sau q
                tmp->link = tmp1; // B1: tao moi lien ket cac node tu p den cac node sau q
                k->link = tmp; //B2: tao moi lien ket voi noi q va p (k == q)
            }
        } */
    } 
}
void printList(list l){
    for(node *p = l.first; p != NULL; p = p->link)
        printf("%d ", p->data);
}

int main(){
    list newList;
    init(newList);

    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        insertLast(newList,x);
    }
    printList(newList);
    printf("\n");

    int a;
    printf("Nhap gia tri node p: ");
    scanf("%d", &a);
    node *p = getNode(a);


    insertAfterQ(newList,p);
    printList(newList);
    return 0;
}
