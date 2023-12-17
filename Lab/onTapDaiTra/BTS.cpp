#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct CHARACTER
{
    char KiTu;
    int SoLuong;
};
struct TNode
{
    CHARACTER data;
    TNode *pLeft;
    TNode *pRight;
};
typedef TNode *Tree;

void insertNode(Tree &root, char x) {
    if (root) {
        if (root->data.KiTu == x) {
            root->data.SoLuong++;
        } else if (root->data.KiTu > x) {
            insertNode(root->pLeft, x);
        } else {
            insertNode(root->pRight, x);
        }
    } else {
        // Cây rỗng, tạo một node mới
        root = new TNode;
        if (root == NULL) {
            return;
        }

        root->data.KiTu = x;
        root->data.SoLuong = 1; 
        root->pLeft = root->pRight = NULL;
    }
}
int countChar(Tree root, char X) {
    if (root == NULL) {
        return 0;
    }

    if (root->data.KiTu == X) {
        return root->data.SoLuong;
    } else if (root->data.KiTu > X) {
        return countChar(root->pLeft, X);
    } else {
        return countChar(root->pRight, X);
    }
}
int main() {
    Tree root = NULL;

    insertNode(root, 'A');
    insertNode(root, 'B');
    insertNode(root, 'A');
    insertNode(root, 'C');
    insertNode(root, 'B');
    insertNode(root, 'D');

    char X = 'A';
    int count = countChar(root, X);
    printf("%d", count);

    return 0;
}

