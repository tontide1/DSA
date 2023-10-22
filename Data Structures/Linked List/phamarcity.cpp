#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct thuoc
{
    char maThuoc[50];
    char tenThuoc[100];
    int nhomThuoc;
    int soLuong;
    float donGia;
    float thanhTien;
};
struct node
{
    thuoc data;
    node *link;
};
struct list
{
    node *first;
    node *last;
};
void init(list &l){
    l.first = l.last = NULL;
}
node *getNode(thuoc x){
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
void insertFirst(list &l, thuoc x){
    node *newNode = getNode(x);
    if(newNode == NULL)
        return;

    addFirst(l, newNode);
}
void insertLast(list &l, thuoc x){
    node *newNode = getNode(x);
    if(newNode == NULL)
        return;

    addLast(l, newNode);
}
void nhapThuoc(thuoc &x){
    fflush(stdin);
    printf("Nhap ma thuoc: ");
    gets(x.maThuoc);
    fflush(stdin);

    printf("Nhap ten thuoc: ");
    gets(x.tenThuoc);
    fflush(stdin);

    printf("Nhap nhom thuoc: ");
    scanf("%d", &x.nhomThuoc);
    fflush(stdin);

    printf("Nhap so luong: ");
    scanf("%d", &x.soLuong);
    fflush(stdin);

    printf("Nhap don gia: ");
    scanf("%f", &x.donGia);
    fflush(stdin);
}
void nhapDSThuoc(list &l){
    int n;
    printf("Nhap so luong loai thuoc: ");
    scanf("%d", &n);
    
    thuoc x;

    for (int i = 0; i < n; i++){
        nhapThuoc(x);
        insertLast(l, x);
    }
}
void xuatThuoc(thuoc x) {
    char nhomThuoc[30];
    if (x.nhomThuoc == 1)
        strcpy(nhomThuoc, "Vitamin");
    else if (x.nhomThuoc == 2)
        strcpy(nhomThuoc, "Khang sinh");
    else
        strcpy(nhomThuoc, "Thuc pham chuc nang");

    printf("%s\t%s\t%s\t%d\t%f\n", x.maThuoc, x.tenThuoc, nhomThuoc, x.soLuong, x.donGia);
}
void xuatDSThuoc(list l){
    int i = 1;
    for (node *p = l.first; p != NULL; p = p->link){
        printf("%d ", i);
        xuatThuoc(p->data);
        ++i;
    }
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
void xoaThuocTheoNhom(list &l, int nhomThuoc){
    node *p = l.first;
    node *prev = NULL;
    while (p != NULL) {
        // So sánh mã nhóm thuốc với nhomThuoc
        if (p->data.nhomThuoc == nhomThuoc) {
            if (prev == NULL) {
                // Nếu nhóm thuốc cần xóa nằm ở phần tử đầu danh sách
                removeFirst(l);
                p = l.first;
            } else if (p->link == NULL) {
                // Nếu nhóm thuốc cần xóa nằm ở phần tử cuối danh sách
                removeLast(l);
                break;
            } else {
                // Nếu nhóm thuốc cần xóa nằm ở phần tử giữa danh sách
                prev->link = p->link;
                delete p;
                p = prev->link;
            }
        } else {
            prev = p;
            p = p->link;
        }
    }
}
// int compareTenThuoc(const void *a, const void *b) {
//     const node *nodeA = *((const node **)a);
//     const node *nodeB = *((const node **)b);
//     return strcmp(nodeA->data.tenThuoc, nodeB->data.tenThuoc);
// }
// void sapXepTheoTenThuoc(list &l) {
//     
//     int n = 0;
//     for (node *p = l.first; p != NULL; p = p->link) {
//         n++;
//     }

//     
//     node *arr[n];
//     int i = 0;
//     for (node *p = l.first; p != NULL; p = p->link) {
//         arr[i++] = p;
//     }

//     
//     qsort(arr, n, sizeof(node *), compareTenThuoc);

//     // Cập nhật lại danh sách đã sắp xếp
//     l.first = arr[0];
//     l.last = arr[n - 1];
//     for (int i = 0; i < n - 1; i++) {
//         arr[i]->link = arr[i + 1];
//     }
//     arr[n - 1]->link = NULL;
// }
void interchangeSortTheoTenThuoc(list &l) {
    node *p, *q;
    for (p = l.first; p != NULL; p = p->link) {
        for (q = p->link; q != NULL; q = q->link) {
            if (strcmp(p->data.tenThuoc, q->data.tenThuoc) > 0) {
                // Hoán đổi thông tin của hai node
                thuoc temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}
void thongKeTheoNhomThuoc(list l) {
    FILE *outputFile = fopen("thong_ke_nhom_thuoc.txt", "w");
    if (outputFile == NULL) {
        printf("Khong the mo tep de ghi ket qua.\n");
        return;
    }


    int tongSoLuong[3] = {0, 0, 0}; 

    // duyet danh sach
    for (node *p = l.first; p != NULL; p = p->link) {
        int nhom = p->data.nhomThuoc;
        tongSoLuong[nhom - 1] += p->data.soLuong;
    }


    fprintf(outputFile, "Ket qua thong ke theo nhom thuoc:\n");
    fprintf(outputFile, "Nhom 1 (Vitamin): %d\n", tongSoLuong[0]);
    fprintf(outputFile, "Nhom 2 (Khang sinh): %d\n", tongSoLuong[1]);
    fprintf(outputFile, "Nhom 3 (Thuc pham chuc nang): %d\n", tongSoLuong[2]);

    fclose(outputFile);
    printf("Da ghi ket qua vao tep thong_ke_nhom_thuoc.txt.\n");
}
void docVaXuatKetQua() {
    FILE *inputFile = fopen("thong_ke_nhom_thuoc.txt", "r");
    if (inputFile == NULL) {
        printf("Khong the mo tep de doc ket qua.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        printf("%s", line);
    }

    fclose(inputFile);
}
int main(){
    list dsThuoc;
    init(dsThuoc);

    int option;
MENU:    do{
        printf("\n1. Nhap danh sach thuoc\n");
        printf("2. Xuat danh sach thuoc\n");
        printf("3. Tinh thanh tien\n");
        printf("4. Xoa thuoc theo mo ta\n");
        printf("5. Sap xep thuoc tang dan\n");
        printf("6. Xuat file text theo tuong nhom thuoc\n");
        printf("7. Doc fil va xuat ket qua ra man hinh\n");
        printf("Chon chuc nang: ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 1:{
            nhapDSThuoc(dsThuoc);
            goto MENU;
        }break;
        case 2:{
            xuatDSThuoc(dsThuoc);
            goto MENU;
        }break;
        case 4:{
            int nhomThuoc;
            printf("Nhap ma nhom thuoc can xoa: ");
            scanf("%d", &nhomThuoc);
            xoaThuocTheoNhom(dsThuoc, nhomThuoc);
            printf("Danh sach sau khi xoa:\n");
            xuatDSThuoc(dsThuoc);
            goto MENU;
        }break;
        case 5: {
            interchangeSortTheoTenThuoc(dsThuoc);
            printf("Danh sach sau khi sap xep theo ten thuoc:\n");
            xuatDSThuoc(dsThuoc);
            goto MENU;
        } break;
        case 6: {
            thongKeTheoNhomThuoc(dsThuoc);
            goto MENU;
        } break;
        case 7: {
            docVaXuatKetQua();
            goto MENU;
        } break;
        }
    } while (option < 0 || option > 7);
    return 0;
}