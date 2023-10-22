#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Node{
    float heSo;
    int soMu;
    Node *next;
};
struct List{
    Node *head;
    Node *tail;
};
void init_list(List &l){
    l.head = l.tail = NULL;
}
Node *getNode(float a, int x){
    Node *newNode = new Node();
    if(newNode == NULL)
        return NULL;

    newNode->heSo = a;
    newNode->soMu = x;
    newNode->next = NULL;

    return newNode;
}
void add_tail(List &L, Node *newNode){
    if(L.head == NULL)
        L.head = L.tail = newNode;
    else{
        L.tail->next = newNode;
        L.tail = newNode;
    }
}
void insert_last(List &L, float a ,int x){
    Node *newNode = getNode(a,x);
    if(newNode == NULL)
        return;

    add_tail(L, newNode);
}
void nhap_da_thuc(List &l){
    float heSo;
    int soMu;

    printf("Nhap da thuc (nhap he so 0 de end)\n");
    do{
        printf("Nhap he so: ");
        scanf("%f", &heSo);

        if(heSo == 0)
            break;

        printf("Nhap so mu: ");
        scanf("%d", &soMu);
        insert_last(l,heSo,soMu);
    }while(heSo != 0);
    printf("\n");
}
void xuat_da_thuc(List l){
    for(Node *i = l.head; i != NULL; i = i->next){
        printf("(%0.f  %d)\t", i->heSo, i->soMu);
    }
    printf("\n");
}
void cong_da_thuc(List &l, List l1, List l2){
    Node *p = l1.head, *q = l2.head;

    float tongHeSo;

    while(p&&q){
        if(q->soMu == p->soMu){
            tongHeSo = q->heSo + p->heSo;
            if(tongHeSo != 0)
                insert_last(l,tongHeSo,p->soMu);

            p = p->next;
            q = q->next;
        }
        else{
            if(p->soMu > q->soMu){
                insert_last(l, p->heSo,p->soMu);
                p = p->next;
            }
            else{
                insert_last(l,q->heSo,q->soMu);
                q = q->next;
            }
        }
    }

    while(q){
        insert_last(l, q->heSo, q->soMu);
        q = q->next;
    }
    while(p){
        insert_last(l, p->heSo, p->soMu);
        p = p->next;
    }
}
void inter_change_sort(List &l){
    for(Node *p = l.head; p != l.tail; p = p->next){
        for(Node *q = p->next; q != NULL; q = q->next){
            if(p->soMu < q->soMu){
                swap(p->heSo, q->heSo);
                swap(p->soMu, q->soMu);
            }
        }
    }
}
void Printftheodang(List l){
    Node *p=l.head;
    printf(" \nxuat danh sach theo dang nguyen mau: \n");
    while(p!=NULL){
        if(p==l.head) {
            if(p->heSo>0)
        printf("%.0f*x^%d ",p->heSo,p->soMu);
        else printf("%.0f*x^%d ",p->heSo,p->soMu);
        }
        else {
        
        if(p->heSo>0)
                printf("+%.0f*x^%d ",p->heSo,p->soMu);
        else printf("%.0f*x^%d ",p->heSo,p->soMu);
    }
        p=p->next;
    }
}
int main(){
    List l, l1, l2;
    init_list(l1);
    init_list(l2);
    init_list(l);

    nhap_da_thuc(l1);
    printf("Nhap da thuc 2\n");
    nhap_da_thuc(l2);

    inter_change_sort(l1);
    inter_change_sort(l2);

    xuat_da_thuc(l1);
    xuat_da_thuc(l2);



    cong_da_thuc(l,l1,l2);
    printf("2 Da thuc da cong :\n");
    xuat_da_thuc(l);

    printf("\n");
    Printftheodang(l);
    return 0;
}