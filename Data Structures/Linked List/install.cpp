#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    node *link;
};

struct list {
    node *first, *last;
};

void init(list &l) {
    l.first = l.last = NULL;
}

node *getNode(int data) {
    node *p = new node;
    if (p == NULL)
        return NULL;

    p->data = data;
    p->link = NULL;
    return p;
}

void addFirst(list &l, node *p) {
    if (l.first == NULL) {
        l.first = l.last = p;
    } else {
        p->link = l.first;
        l.first = p;
    }
}

void addLast(list &l, node *p) {
    if (l.first == NULL) {
        l.first = l.last = p;
    } else {
        l.last->link = p;
        l.last = p;
    }
}

void insertFirst(list &l, int x) {
    node *p = getNode(x);
    if (p == NULL)
        return;

    addFirst(l, p);
}

void insertLast(list &l, int x) {
    node *p = getNode(x);
    if (p == NULL)
        return;

    addLast(l, p);
}

node *search(list l, int x) {
    for (node *p = l.first; p != NULL; p = p->link) {
        if (p->data == x)
            return p;
    }
    return NULL;
}

long sumEvenNum(list l) {
    long sum = 0;
    for (node *p = l.first; p != NULL; p = p->link) {
        if (p->data % 2 == 0) {
            sum += p->data;
        }
    }
    return sum;
}

void insertAfterQ(list &l, node *p, node *q) {

    if (q->data == l.last->data) {
        addLast(l, p);
        return;
    }
    else{
        //1 2 99 2 5
        // Them 1 lan node p sau node q
        // for (node *k = l.first; k != NULL; k = k->link) {
        //     if (q->data == k->data) {
        //         p->link = k->link;
        //         k->link = p;
        //         return;
        //     }
    }
        //1 2 99 2 99 5
    for(node *k = l.first; k != NULL; k = k->link){
            if(q->data == k->data){
                node *tmp = getNode(p->data);
                node *tmp1 = k->link; // cho node tmp1 tro den node nam sau q
                tmp->link = tmp1; // B1: tao moi lien ket cac node tu p den cac node sau q
                k->link = tmp; //B2: tao moi lien ket voi noi q va p (k == q)
            }
        } 
    
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
void printList(list l) {
    for (node *p = l.first; p != NULL; p = p->link)
        printf("%d ", p->data);
    printf("\n");
}

int main() {
    list newList;
    init(newList);

    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertLast(newList, x);
    }
    printList(newList);

    // int a;
    // printf("Nhap gia tri node p: ");
    // scanf("%d", &a);
    node *p = getNode(99);

    // int b;
    // printf("Nhap gia tri node q: ");
    // scanf("%d", &b);
    node *q = getNode(2);

    insertAfterQ(newList, p, q);
    printList(newList);

    return 0;
}
