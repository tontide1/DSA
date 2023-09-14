#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct WORD{
	char Name[256];
	char Meaning[512];
}W;
void delete_enter(char s[]){
    size_t len = strlen(s);
    if(s[len - 1] == '\n')
        s[len - 1] = '\0';
}
void nhap_Word(int &so_luong, W tu[]){
    printf("Nhap so luong tu: ");
    scanf("%d", &so_luong);
    if (so_luong < 0) {
        printf("So luong khong hop le!\n");
        return;
    }
    getchar();
    for(int i = 0; i < so_luong; i++){
        printf("Tu so %d\n", i+1);

        printf("Name: ");
        fgets(tu[i].Name, sizeof(tu[i].Name), stdin);
        delete_enter(tu[i].Name);

        printf("Meaning: ");
        fgets(tu[i].Meaning, sizeof(tu[i].Meaning), stdin);
        delete_enter(tu[i].Meaning);
    }
}

void xuat_Word(int so_luong, W tu[]){
	for(int i = 0; i < so_luong; i++){
		printf("Tu so %d: ", i+1);
		printf("%s %s\n", tu[i].Name, tu[i].Meaning);
	}
}
void sap_Xep(int so_luong, W tu[]){
	char tmp[256];
	int i, j;
  	for(i=1;i<so_luong;i++){
    	for(j=1;j<so_luong;j++){
      		if(strcmp(tu[j-1].Name, tu[j].Name)>0){
        		strcpy(tmp, tu[j-1].Name);
        		strcpy(tu[j-1].Name, tu[j].Name);
        		strcpy(tu[j].Name, tmp);
      }
    }
  }
  printf("Tu vung da duoc sap xep tang dan\n");
}
int tim_kiem(int so_luong, W tu[], const char x[256]){
	int left = 0, right = so_luong - 1;
	while(right >= left){
		int mid = left + (right - left)/2;
		int ket_qua1 = strcmp(tu[mid].Name,x);
		int ket_qua2 = strcmp(tu[mid].Meaning,x);
		if(ket_qua1==0 || ket_qua2==0)
			return mid;
		if(ket_qua1 > 0 || ket_qua2 > 0)
			right = mid - 1;
		if(ket_qua1  < 0 || ket_qua2 > 0)
			left = mid + 1;
	}
	return -1;
}
int main(){
	int n, so_luong;
	W a[1001];
MENU:
	do{
		printf("0.Thoat\n");
		printf("1.Nhap chu\n");
		printf("2.Xuat chu\n");
		printf("3.Sap xep chu\n");
		printf("4.Tim kiem chu\n");
		printf("Chon chuc nang: ");
		scanf("%d", &n);
		if(n < 0 || n > 4)
			printf("Nhap sai ! Hay nhap lai\n");
			
		switch(n){
		case 0: exit(0);
		case 1:{
			nhap_Word(so_luong,a);
			goto MENU;
		}break;
		case 2:{
			xuat_Word(so_luong,a);
			goto MENU;
		}break;
		case 3:{
			sap_Xep(so_luong,a);
			goto MENU;
		}break;
		case 4:{
			char x[256];
			printf("Nhap tu can tim kiem(anh hoac viet): ");
			getchar();
			fgets(x,sizeof(x),stdin);
			delete_enter(x);

			if(tim_kiem(so_luong,a,x) == -1)
				printf("Khong tim thay tu can tim kiem!\n");
			else
				printf("Tu can tim: %s - %s\n", a[tim_kiem(so_luong,a,x)].Name,a[tim_kiem(so_luong,a,x)].Meaning);
			
			goto MENU;
		}break;
		default:
			printf("Chuc nang khong co !\n");
			break;
	}	
	}while(n < 0 || n > 4);
	return 0;
}