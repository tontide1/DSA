#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Tnode
{
    int data;
    Tnode *pLeft;
    Tnode *pRight;
};
typedef Tnode *Tree;

void insertNode(Tree &t, int x){
    if(t == NULL){
        Tnode *p = new Tnode;
        if(p == NULL)
            return;

        p->pLeft = p->pRight = NULL;
        p->data = x;
        t = p;
    }else{
        if(t->data > x)
            return insertNode(t->pLeft, x);
        if(t->data < x)
            return insertNode(t->pRight, x);
        else
            return;
    }
}
void RNL(Tree t){
    if(t){
        RNL(t->pRight);
        // if(t->data <= 18 && t->data != 17)
            printf("%d ", t->data);
        RNL(t->pLeft);
    }
}
int countLeaf(Tree t){
    int count = 0;
    if(t){
        if(t->pLeft == NULL && t->pRight == NULL){
            return 1;
        }else{
            count = countLeaf(t->pLeft) + countLeaf(t->pRight);
        }
    }
    return count;
}
int countNode(Tree t){
    if(t == NULL)
        return 0;

    int count;
    if(t){
        count = countNode(t->pLeft) + countNode(t->pRight) + 1;
    }
    return count;
}
void splitTree(Tree t, Tree &a, Tree &b){
    if(t == NULL)
        return;
    if(t){
        if(t->data % 2 == 0)
            insertNode(a, t->data);
        else
            insertNode(b, t->data);
    }
    splitTree(t->pLeft, a, b);
    splitTree(t->pRight, a, b);
}
int primeNum(int n){
    if(n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return 0;

    return 1;
}
Tree delPrime(Tree t){
    if(t == NULL)
        return NULL;

    t->pLeft = delPrime(t->pLeft);
    t->pRight = delPrime(t->pRight);

    if(primeNum(t->data)){
        delete (t);
        return NULL;
    }
    return t;
}
int main(){
    Tree t = NULL;
    insertNode(t, 10);
    insertNode(t, 6);
    insertNode(t, 2);
    insertNode(t, 8);
    insertNode(t, 15);
    insertNode(t, 12);
    insertNode(t, 14);
    insertNode(t, 18);
    insertNode(t, 17);
    insertNode(t, 19);
    insertNode(t, 23);



    RNL(t);
    printf("\nSo nut la: %d", countLeaf(t));
    printf("\nSo nut : %d\n", countNode(t));

    Tree a = NULL, b = NULL;
    splitTree(t, a, b);
    RNL(a);
    printf("\n");
    RNL(b);
    printf("\nxoa cac so nguyen to: ");
    RNL(delPrime(t));
    return 0;
}