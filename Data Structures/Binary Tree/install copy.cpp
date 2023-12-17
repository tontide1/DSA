#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct TNode{
    int data;
    TNode *pLeft;
    TNode *pRight;
};
typedef TNode* Tree;

TNode* createNode(int x){
    TNode *p = new TNode;
    if(p == NULL)
        return NULL;

    p->data = x;
    p->pLeft = p->pRight = NULL;

    return p;
}
void addTNode(Tree &root, int x){
    if(root == NULL){
        TNode *p = createNode(x);
        root = p; // gan' p = node root
    }
    else{
        if(root->data > x)
            addTNode(root->pLeft, x);
        else if(root->data < x)
            addTNode(root->pRight, x);
        else
            return;
    }
}
void NLR(Tree t){
    if(t != NULL){
        printf("%d ", t->data);
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}
void LNR(Tree t){
    if(t != NULL){
        LNR(t->pLeft);
        printf("%d ", t->data);
        LNR(t->pRight);
    }
}
void LRN(Tree t){
    if(t != NULL){
        LRN(t->pLeft);
        LRN(t->pRight);
        printf("%d ", t->data);
    }
    // -3 -5 1 0 -2 6 7 5
}
void RLN(Tree t){
    if(t != NULL){
        RLN(t->pRight);
        RLN(t->pLeft);
        printf("%d ", t->data);
    }
}
void RNL(Tree t){
    if(t!=NULL){
        RNL(t->pRight);
        // if(t->data <= 18 && t->data != 17)
            printf("%d ", t->data);
        RNL(t->pLeft);
    }
}
void input(Tree &t){
    int choose = 1;
    while(choose > 0){
        printf("Nhap gia tri can them: ");
        int temp;
        scanf("%d", &temp);
        addTNode(t, temp);
        printf("Tiep tuc nhap cay: ");
        scanf("%d", &choose);
    }
}
int primeNum(int x){
    if(x <= 1)
        return 0;

    for (int i = 2; i <= sqrt(x); i++){
        if(x % i == 0)
            return 0;
    }
    return 1;
}
int countPrime(Tree t){
    int count = 0;

    if(t == NULL)
        return 0;
    else{
        if(primeNum(t->data))
            count++;

        count += countPrime(t->pLeft); // de quy lai so nut cay trai
        count += countPrime(t->pRight); // de quy lai so nut cay phai
    }

    return count;
}
int countNode(Tree t){
    int count = 0;
    if(t == NULL)
        return 0;
    else{
        count = 1 + countNode(t->pLeft) + countNode(t->pRight);
    }
    return count;
}
int countLeaf(Tree t){
    int count = 0;
    if(t==NULL)
        return 0;
    else if(t->pLeft == NULL && t->pRight ==NULL)
        return 1;
    else{
        count = countLeaf(t->pLeft) + countLeaf(t->pRight);
    }

    return count;
}
int height(Tree root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->pLeft);
    int rightHeight = height(root->pRight);

    // Chiều cao của cây là chiều cao của nhánh lớn nhất + 1
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}
TNode *searchNode(Tree t, int x){
    if(t){
        if(t->data == x)
            return t;
        else if(t->data > x)
            return searchNode(t->pLeft, x);
        else
            return searchNode(t->pRight, x);
    }

    return NULL;
}
int NodeMax(Tree t){
    if(t == NULL)
        return INT_MIN;

    if(t->pRight == NULL)
        return t->data;

    return NodeMax(t->pRight);
}
int NodeMin(Tree t){
    if(t == NULL)
        return INT_MIN;
    
    if (t->pLeft == NULL)
    {
        return t->data;
    }
    return NodeMin(t->pLeft);
}
int insertNode(Tree& t, int x) {
    if (t) {
        if (t->data == x)
            return 0;
        else if (t->data > x)
            return insertNode(t->pLeft, x);
        else
            return insertNode(t->pRight, x);
    }

    t = new TNode;
    if (t == NULL)
        return -1;

    t->data = x;
    t->pLeft = t->pRight = NULL;

    return 1;
}
void searchStandFor(Tree &p, Tree &q){
    if(q->pLeft)
        searchStandFor(p, q->pLeft);
    else{
        p->data = q->data;
        p = q;
        q = q->pRight;
    }
}
int delNode(Tree &t, int x){
    if(t == NULL)
        return 0;
    if(t->data > x)
        return delNode(t->pLeft, x);
    if(t->data < x)
        return delNode(t->pRight, x);

    TNode *p = t; // gan' node thay the
    if(t->pLeft == NULL)
        t = t->pRight;
    else{
        if(t->pRight == NULL)
            t = t->pLeft;
        else{
            TNode *q = t->pRight;
            searchStandFor(p, q);
        }
    }
    delete p;
    return 1;
}
int main(){
    Tree t = NULL;
    addTNode(t,25);
    addTNode(t,10);
    addTNode(t,4);
    addTNode(t,2);
    addTNode(t,7);
    addTNode(t,16);
    addTNode(t,20);
    addTNode(t,45);
    addTNode(t,40);
    addTNode(t,35);
    addTNode(t,50);
    addTNode(t,60);

    LNR(t);

    // insertNode(t, 11);
    // printf("\n");
    // NLR(t);

    // printf("\n");
    // printf("Node max: %d", NodeMin(t));
    return 0;
}
