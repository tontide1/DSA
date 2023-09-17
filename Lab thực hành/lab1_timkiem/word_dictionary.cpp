/* 
DHKHDL - Phan Tan Tai - 22684181
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct WORD {
    char Name[256];
    char Meaning[512];
} W;

void delete_enter(char s[]) {
    size_t len = strlen(s);
    if (s[len - 1] == '\n')
        s[len - 1] = '\0';
}

void nhap_Word(int &so_luong, W tu[]) {
    printf("Nhap so luong tu: ");
    scanf("%d", &so_luong);

    if (so_luong < 0) {
        printf("So luong khong hop le!\n");
        return;
    }
    getchar();

    for (int i = 0; i < so_luong; i++) {
        printf("Tu so %d\n", i + 1);

        printf("Name: ");
        fgets(tu[i].Name, sizeof(tu[i].Name), stdin);
        delete_enter(tu[i].Name);

        printf("Meaning: ");
        fgets(tu[i].Meaning, sizeof(tu[i].Meaning), stdin);
        delete_enter(tu[i].Meaning);
    }
}

void xuat_Word(int so_luong, W tu[]) {
    for (int i = 0; i < so_luong; i++) {
        printf("Tu so %d: %s %s\n", i + 1, tu[i].Name, tu[i].Meaning);
    }
}

void sap_Xep(int so_luong, W tu[]) {
    int i, j;
    for (i = 1; i < so_luong; i++) {
        for (j = 1; j < so_luong; j++) {
            if (strcmp(tu[j - 1].Name, tu[j].Name) > 0) {
                W temp = tu[j - 1];
                tu[j - 1] = tu[j];
                tu[j] = temp;
            }
        }
    }
    printf("Tu vung da duoc sap xep tang dan\n");
}


int tim_kiem(int so_luong, W tu[], const char x[256]) {
    int left = 0, right = so_luong - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        int ket_qua = strcmp(tu[mid].Name, x);
        if (ket_qua == 0)
            return mid;
        if (ket_qua > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}


void ghi_tu_vung(int so_luong, W tu[]) {
    FILE *ghi = fopen("tu_vung.txt", "w");
    if (ghi == NULL) {
        printf("Khong the mo tep de ghi!\n");
        return;
    }

    for (int i = 0; i < so_luong; i++) {
        fprintf(ghi, "%s\n%s\n", tu[i].Name, tu[i].Meaning);
    }

    fclose(ghi);
    printf("Danh sach tu vung da duoc ghi vao tep 'tu_vung.txt'\n");
}

void doc_tu_vung(int &so_luong, W tu[]) {
    FILE *doc = fopen("tu_vung.txt", "r");
    if (doc == NULL) {
        printf("Khong the mo tep de doc!\n");
        return;
    }

    so_luong = 0;
    while (fgets(tu[so_luong].Name, sizeof(tu[so_luong].Name), doc)) {
        fgets(tu[so_luong].Meaning, sizeof(tu[so_luong].Meaning), doc);
        delete_enter(tu[so_luong].Name);
        delete_enter(tu[so_luong].Meaning);
        so_luong++;
    }

    fclose(doc);
    printf("Danh sach tu vung da duoc doc tu tep 'tu_vung.txt'\n");
}

void xoa_tu(int &so_luong, W tu[], const char x[256]) {
    int vi_tri = tim_kiem(so_luong, tu, x);
    if (vi_tri == -1) {
        printf("Khong tim thay tu can xoa!\n");
        return;
    }

    // dich chuyen cac tu phim sau ve truoc
    for (int i = vi_tri; i < so_luong - 1; i++) {
        tu[i] = tu[i + 1];
    }

    so_luong--;
    printf("Tu '%s' da duoc xoa khoi danh sach tu vung.\n", x);

    ghi_tu_vung(so_luong, tu);
}

void them_tu(int &so_luong, W tu[], const char x[256], const char y[512]) {
    if (so_luong >= 1001) {
        printf("Danh sach tu vung da day, khong the them!\n");
        return;
    }

    // tao 1 temp
    W tu_moi[1001];
    for (int i = 0; i < so_luong; i++) {
        tu_moi[i] = tu[i];
    }

    int vi_tri = 0;
    while (vi_tri < so_luong && strcmp(tu[vi_tri].Name, x) < 0) {
        vi_tri++;
    }

    for (int i = so_luong; i > vi_tri; i--) {
        tu[i] = tu_moi[i - 1];
    }


    strcpy(tu[vi_tri].Name, x);
    strcpy(tu[vi_tri].Meaning, y);

    so_luong++;
    printf("Tu '%s' da duoc them vao danh sach tu vung.\n", x);

    ghi_tu_vung(so_luong, tu);
}


int main() {
    int n, so_luong;
    W a[1001];

    FILE *ghi, *doc;

    MENU:
    do {
        printf("0.Thoat\n");
        printf("1.Nhap tu vung\n");
        printf("2.Xuat danh sach tu vung\n");
        printf("3.Sap xep danh sach tu vung\n");
        printf("4.Tim kiem tu vung\n");
        printf("5.Xoa tu vung\n");
        printf("6.Them tu vung\n");
        printf("Chon chuc nang: ");
        scanf("%d", &n);

        if (n < 0 || n > 8)
            printf("Nhap sai ! Hay nhap lai\n");

        switch (n) {
            case 0:
                exit(0);
            case 1: {
                nhap_Word(so_luong, a);
                ghi_tu_vung(so_luong, a);
                goto MENU;
            } break;
            case 2: {
                xuat_Word(so_luong, a);
                goto MENU;
            } break;
            case 3: {
                sap_Xep(so_luong, a);
                goto MENU;
            } break;
            case 4: {
                char x[256];
                printf("Nhap tu can tim kiem(anh hoac viet): ");
                getchar();
                fgets(x, sizeof(x), stdin);
                delete_enter(x);

                int result = tim_kiem(so_luong, a, x);
                if (result == -1)
                    printf("Khong tim thay tu can tim kiem!\n");
                else
                    printf("Tu can tim: %s - %s\n", a[result].Name, a[result].Meaning);

                goto MENU;
            } break;
            case 5: {
                char x[256];
                printf("Nhap tu can xoa: ");
                getchar();
                fgets(x, sizeof(x), stdin);
                delete_enter(x);
                xoa_tu(so_luong, a, x);
                goto MENU;
            } break;
            case 6: {
                char x[256], y[512];
                printf("Nhap tu can them: ");
                getchar();
                fgets(x, sizeof(x), stdin);
                delete_enter(x);

                printf("Nhap nghia cua tu: ");
                fgets(y, sizeof(y), stdin);
                delete_enter(y);

                them_tu(so_luong, a, x, y);
                goto MENU;
            } break;
            default:
                printf("Chuc nang khong co !\n");
                break;
        }
    } while (n >= 0 && n <= 8);

    return 0;
}