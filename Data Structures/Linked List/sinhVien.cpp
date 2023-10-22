#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,unroll-loops") // change to O3 to disable fast-math for geometry problems
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Ngay{
    int ngay, thang, nam; 
};
struct sinhVien{
    char mssv[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[12];
};
struct node{
    sinhVien data;
    node *link;
};
struct list{
    node *first;
    node *last;
};
void init(list &l){
    l.first = l.last = NULL;
}
node *getNode(sinhVien x){
    node *p = new node;
    if(p == NULL)
        return NULL;

    p->data = x;
    p->link = NULL;
    return p;
}
void addFirst(list &l, node *newNode){
    if(l.first == NULL)
        l.first = l.last = newNode;
    else{
        newNode->link = l.first;
        l.first = newNode;
    }
}
void addLast(list &l, node *newNode){
    if(l.first == NULL)
        l.first = l.last = newNode;
    else{
        l.last->link = newNode;
        l.last = newNode;
    }
}
void insertFirst(list &l, sinhVien x){
    node *newSinhVien = getNode(x);
    if(newSinhVien == NULL)
        return;
    addFirst(l, newSinhVien);
}
void insertLast(list &l, sinhVien x){
    node *newSinhVien = getNode(x);
    if(newSinhVien == NULL)
        return;
    addLast(l, newSinhVien);
}

int ReadFromFile(list &l, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return 0;
    }

    init(l);
    sinhVien x;
    while (fscanf(file, "%s %s %d %d/%d/%d %s %s %s",
                x.mssv, x.hoTen, &x.gioiTinh,
                &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam,
                x.diaChi, x.lop, x.khoa) != EOF) {
        insertLast(l, x);
    }

    fclose(file);
    return 1;
}
void DocDSSVTuFile(list &l){
	char tenfile[20];
	printf("Nhap ten file: ");
	getchar();
	gets(tenfile);
	FILE *f=fopen(tenfile,"r");
	if(f==NULL) {
	printf("loi mo file");
	return;}
	Init(l);
	// node *p=l.first;
    sinhVien x;
    while (fscanf(file, "%s %s %d %d/%d/%d %s %s %s",
                x.mssv, x.hoTen, &x.gioiTinh,
                &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam,
                x.diaChi, x.lop, x.khoa) != EOF) {
        InsertLast(l, x);
    }
	fclose(f);
}
int WriteToFile(list l, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return 0;
    }

    node *p = l.first;
    while (p != NULL) {
        fprintf(file, "%s %s %d %d/%d/%d %s %s %s\n",
                p->data.mssv, p->data.hoTen, p->data.gioiTinh,
                p->data.ngaySinh.ngay, p->data.ngaySinh.thang, p->data.ngaySinh.nam,
                p->data.diaChi, p->data.lop, p->data.khoa);
        p = p->link;
    }

    fclose(file);
    return 1;
}

void nhapSinhVien(sinhVien &x){
    fflush(stdin);
    printf("Nhap mssv: ");
    gets(x.mssv);


    fflush(stdin);
    printf("Nhap ho ten: ");
    gets(x.hoTen);

    fflush(stdin);
    printf("Nhap gioi tinh(1 = nam || 0 = nu): ");
    scanf("%d", &x.gioiTinh);

    fflush(stdin);
    printf("Ngay thang nam sinh: ");
    scanf("%d %d %d", &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam);

    fflush(stdin);
    printf("Nhap dia chi: ");
    gets(x.diaChi);

    fflush(stdin);
    printf("Nhap lop: ");
    gets(x.lop);

    fflush(stdin);
    printf("Nhap khoa: ");
    gets(x.khoa);
}
void nhapDSSV(list &l){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    sinhVien x;

    for(int i = 0; i < n; i++){
        nhapSinhVien(x);
        insertLast(l,x);
    }
}
int search(list l, const char maSo[8]){
    for(node *p = l.first; p != NULL; p = p->link){
        if(strcmp(l.first->data.mssv, maSo) == 0)
            return 1;
    }
    return 0;
}
void themSV(list &l, sinhVien x){
    if(search(l,x.mssv)){
        printf("Trung mssv !\n");
        return;
    }
    else{
        insertLast(l,x);
    }
    WriteToFile(l,"dssv.txt");
}
void removeFirst(list &l){
    if(l.first == NULL)
        return;
    else{
        node *p = l.first;
        l.first = l.first->link; // tro toi node sau
        delete p;
    }
}
void removeLast(list &l){
    if(l.first == NULL)
        return;
    if(l.first->link == NULL){ // kiem tra danh sach co 1 phan tu
        removeFirst(l);
        return;
    }
    for(node *p = l.first; p != NULL; p = p->link){
        if(p->link == l.last){
            delete l.last;
            p->link = NULL;
            l.last = p;
        }
    }
}
void removeSV(list &l, const char maSo[8]){
    if(l.first == NULL)
        return;
    if(strcmp(l.first->data.mssv, maSo) == 0){
        removeFirst(l);
        return;
    }
    if(strcmp(l.last->data.mssv, maSo) == 0){
        removeLast(l);
        return;
    }
    node *tmp = new node;
    for(node *p = l.first; p != NULL; p = p->link){
        if(strcmp(p->data.mssv, maSo) == 0){
            tmp->link = p->link;
            delete p;
            return;
        }
        tmp = p;
    }
}
void append(list &l, list &l2){
    if(l2.first == NULL)
        return;
    if(l.first == NULL)
        l = l2;
    else{
        l.last->link = l2.first;
        l.last = l2.last;
    }
    init(l2);
}
void quickSort(list &l){
    list l1, l2;
    node *tag, *p;
    if(l.first == l.last)
        return;

    init(l1);
    init(l2);

    tag = l.first;
    l.first = l.first->link; // cap nhat lai first
    tag->link = NULL; // co lap tag

    while(l.first != NULL){
        p = l.first;
        l.first = l.first->link;
        p->link = NULL;
        if(strcmp(p->data.hoTen, tag->data.hoTen) < 0)
            addFirst(l1, p);
        else
            addFirst(l2, p);
    }
    quickSort(l1);
    quickSort(l2);
    append(l, l1);
    addLast(l, tag);
    append(l, l2);
}
void xuatSinhVien(sinhVien x){
    char gioiTinh[5];
    if(x.gioiTinh == 1)
        strcpy(gioiTinh, "Nam");
    else
        strcpy(gioiTinh, "Nu");

    printf("%s\t\t%s\t\t%s\t\t%d/%d/%d\t%s\t\t%s\t%s\n", x.mssv, x.hoTen, gioiTinh, x.ngaySinh.ngay, x.ngaySinh.thang, x.ngaySinh.nam, x.diaChi, x.lop, x.khoa);
}
void xuatDSSV(list l){
    int i = 1;
    for(node *p = l.first; p != NULL; p = p->link){
        printf("%d\t", i);
        xuatSinhVien(p->data);
        ++i;
    }
}

int main(){
    list sv;
    init(sv);

    int choose;
MENU:
    do
    {
        printf("0.Thoat\n");
        printf("1.Nhap DSSV\n");
        printf("2.XuatDSSV\n");
        printf("3.Them sinh vien\n");
        printf("4.Xoa sinh vien\n");
        printf("5.Sap xep sinh vien\n");
        printf("6.Tron 2 danh sach\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            exit(0);
        case 1:{
            nhapDSSV(sv);
            WriteToFile(sv,"dssv.txt");
            system("cls");
            goto MENU;
        }break;
        case 2:{
            xuatDSSV(sv);
            system("pause");
            system("cls");
            goto MENU;
        }break;
        case 3:{
            sinhVien x;
            nhapSinhVien(x);
            themSV(sv,x);
            system("cls");
            goto MENU;
        }break;
        case 4:{
            fflush(stdin);
            char maSo[8];
            printf("Nhap mssv can xoa: ");
            gets(maSo);
            removeSV(sv, maSo);
            WriteToFile(sv, "dssv.txt");
            system("cls");
            goto MENU;
        }break;
        case 5:{
            quickSort(sv);
            WriteToFile(sv, "dssv.txt");
            system("cls");
            goto MENU;
        }break;
        }
    } while (choose != 0);
    
    
    return 0;
}       