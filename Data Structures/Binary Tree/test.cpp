#include <stdio.h>
#include <stdlib.h>

struct maytinh {
    char soMay[50];
    char tenMay[100];
    int namSX;
    int giaTriMay;
    int timeTruyCap;
    int tienTruyCap;
};

struct node {
    maytinh data;
    node* left;
    node* right;
};

typedef node* tree;

node* TaoNode(maytinh x) {
    node* p = new node;
    if (p == NULL) return NULL;
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

node* KiemTra(tree c, char* somay) {
    node* p = c;
    while (p != NULL) {
        if (atoi(p->data.soMay) == atoi(somay)) return p;
        else if (atoi(p->data.soMay) > atoi(somay))
            p = p->left;
        else p = p->right;
    }
    return NULL;
}

int ThemNodeVaocay(tree& c, node* p) {
    if (c) {
        if (atoi(c->data.soMay) == atoi(p->data.soMay)) return 0;
        else if (atoi(c->data.soMay) > atoi(p->data.soMay)) return ThemNodeVaocay(c->left, p);
        else return ThemNodeVaocay(c->right, p);
    }
    c = new node;
    if (c == NULL) return -1;
    c->data = p->data;
    return 1;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void NhapThongTin(tree& c) {
    maytinh x;
    clearBuffer();
    printf("Nhap so may:");
    gets(x.soMay);
    while (KiemTra(c, x.soMay) != NULL) {
        printf("Trung so may! Vui long nhap lai: ");
        gets(x.soMay);
    }
    printf("Nhap ten may: ");
    gets(x.tenMay);
    printf("Nhap nam san xuat: ");
    scanf("%d", &x.namSX);
    printf("Nhap gia tri may: ");
    scanf("%d", &x.giaTriMay);
    printf("Nhap thoi gian truy cap: ");
    scanf("%d", &x.timeTruyCap);
    printf("Nhap tien truy cap: ");
    scanf("%d", &x.tienTruyCap);
    node* p = TaoNode(x);
    ThemNodeVaocay(c, p);
}

void NhapDanhSachMay(tree& c, int n) {
    printf("Bat dau nhap danh sach:\n");
    for (int i = 0; i < n; i++) {
        NhapThongTin(c);
    }
    printf("Ket thuc nhap danh sach\n");
}

int main() {
    tree c = NULL;
    int chon;
    int n;

    do {
        printf("\n1. Nhap danh sach may");
        printf("\n0. Thoat");
        printf("\nLua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: {
                printf("Nhap so luong may: ");
                scanf("%d", &n);
                NhapDanhSachMay(c, n);
                break;
            }
        }
    } while (chon != 0);

    return 0;
}
