#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    node *pLeft;
    node *pRight;
};
typedef node* Tree;

node* createNode(int x){
    node *p = new node;
    if(p == NULL)
        return NULL;

    p->pLeft = NULL;
    p->pRight = NULL;
    p->data = x;

    return p;
}
void addNode(node *p, Tree &t){
    if(t == NULL){
        t = p;
    }
    else{  
        if(t->data < p->data)
            addNode(p, t->pRight);
        else if(t->data > p->data)
            addNode(p, t->pLeft);
        else
            return;
    }
}
void inputTree(Tree &t){
    int choose = 0;
    do{
        int tmp;
        printf("Nhap x: ");
        scanf("%d", &tmp);
        node *p = createNode(tmp);
        addNode(p, t);
        printf("Nhap tiep: ");
        scanf("%d", &choose);
    } while (choose);
}
void NLR(Tree t){
    if(t != NULL){
        printf("%d ", t->data);
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

int main(){
    Tree t = NULL;
    inputTree(t);
    NLR(t);
    return 0;
}