#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct NGAY
{
    int ngay;
    int thang;
    int nam;    
};
struct SANPHAM
{
    char maSP[10];
    char tenSP[255];
    NGAY ngaySX;
    int soNamBH;
};
void swap(SANPHAM &a, SANPHAM &b) {
    SANPHAM temp = a;
    a = b;
    b = temp;
}
// int soSanhChuoi(const char s1[], const char s2[]){
//     int so1 = 0, so2 = 0;

//     for (int i = 0; i < strlen(s1); i++){
//         if(isdigit(s1[i]))
//             so1 = 1;
//         else
//             so1 = 0;
//     }

//     for (int i = 0; i < strlen(s2); i++){
//         if(isdigit(s2[i]))
//             so2 = 1;
//         else
//             so2 = 0;
//     }

//     if(so1 == 1 && so2 == 1){ // cả 2 chuỗi đều là số
//         int a = atoi(s1);
//         int b = atoi(s2);

//         if(a > b)
//             return 1;
//         if(a < b)
//             return -1;
//         else
//             return 0;
//     }else{
//         int i = 0;
//         int len1 = strlen(s1), len2 = strlen(s2);

//         int min_len = (len1 < len2) ? len1 : len2;

//         for (i = 0; i < min_len; i++){
//             if(s1[i] > s2[i])
//                 return 1;
//             else if(s1[i] < s2[i]){
//                 return -1;
//             }
//         }

//         if(len1 > len2)
//             return 1;
//         else if(len1 < len2)
//             return -1;
//         else
//             return 0;
//     }
// }
int partition(SANPHAM x[], int left, int right) {
    const char *pivot = x[right].maSP;
    int i = left - 1;

    for (int j = left; j <= right; j++) {
        int len1 = strlen(x[j].maSP);
        int len2 = strlen(pivot);
        
        if (len1 < len2 || (len1 == len2 && strcmp(x[j].maSP, pivot) < 0)) {
        i++;
        swap(x[i], x[j]);  
        }
    }

    swap(x[i + 1], x[right]);
    return (i + 1);
}
void quickSort(SANPHAM x[], int left, int right) {
    if (left < right) {
        int pivot = partition(x, left, right);

        quickSort(x, left, pivot - 1);
        quickSort(x, pivot + 1, right);
    }
}
void hetHanBaoHanh(SANPHAM x[], int namHienTai){
    int flag = 0;
    for (int i = 0; i < 5; i++) {
        if (x[i].ngaySX.nam + x[i].soNamBH < namHienTai) {
            printf("%s\t%s\t%d %d %d - %d\n", x[i].maSP, x[i].tenSP, x[i].ngaySX.ngay,
                        x[i].ngaySX.thang, x[i].ngaySX.nam, x[i].soNamBH);

            flag = 1;
        }
    }
    if (flag == 0)
        printf("KHONG CO SAN PHAM HET HAN\n");
}

int main(){
    SANPHAM dsSP[5] = {
        {"A99", "San Pham 3", {3, 8, 2011}, 2},
        {"A234", "San Pham 1", {1, 8, 2011}, 3},
        {"A512", "San Pham 5", {5, 8, 1999}, 1},
        {"A2", "San Pham 2", {2, 8, 2022}, 4},
        {"A4", "San Pham 4", {4, 8, 2022}, 5}};

    quickSort(dsSP, 0, 4);

    for (int i = 0; i < 5; ++i)
        printf("%s\t%s\t%d %d %d - %d\n", dsSP[i].maSP, dsSP[i].tenSP, dsSP[i].ngaySX.ngay,
                                            dsSP[i].ngaySX.thang, dsSP[i].ngaySX.nam, dsSP[i].soNamBH);

    printf("HET HAN BH:\n");
    hetHanBaoHanh(dsSP, 2023);

    return 0;
}