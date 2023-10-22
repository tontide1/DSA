#include<stdio.h>
#include<string.h>

struct Ngay{
	int ngay,thang,nam;
};
struct SinhVien{
	char maSV[8];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
};
struct node{
	SinhVien data;
	node *next;
};
struct list{
	node *first,*last;
};
void Init(list &l){
	l.first=l.last=NULL;
}
node *getNode(SinhVien x){
	node *p=new node;
	if(p==NULL) return NULL;
	else {
		p->data=x;
		p->next=NULL;
	}
	return p;
}
void Addlast(list &l, node *new_ele){
	if(l.first==NULL) l.first=l.last=new_ele;
	else {
		l.last->next=new_ele;
		l.last=new_ele;
	}
}
int SearchSV(list l,char *x){
	node *p=l.first;
	while(p){
		if(strcmp(p->data.maSV,x)==0) return 1;
		p=p->next;
	}
	return 0;
}
void InsertLast(list &l,SinhVien x){
		node *p=getNode(x);
		if(p==NULL) return;
		if(SearchSV(l,p->data.maSV)==1) return;
		else {
			Addlast(l,p);
		}
}
int ReadFromFile(list &l, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return 0;
    }

    Init(l);
    SinhVien x;
    while (fscanf(file, "%s %s %d %d/%d/%d %s %s %s",
                x.maSV, x.hoTen, &x.gioiTinh,
                &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam,
                x.diaChi, x.lop, x.khoa) != EOF) {
        InsertLast(l, x);
    }

    fclose(file);
    return 1;
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
                p->data.maSV, p->data.hoTen, p->data.gioiTinh,
                p->data.ngaySinh.ngay, p->data.ngaySinh.thang, p->data.ngaySinh.nam,
                p->data.diaChi, p->data.lop, p->data.khoa);
        p = p->next;
    }

    fclose(file);
    return 1;
}
int NhapSinhVien(SinhVien &x){
	printf("Nhap ma sinh vien: ");
	fflush(stdin);
	gets(x.maSV);
	if(strcmp(x.maSV,"0")==0) return 0;
		printf("Nhap ho ten: ");
	fflush(stdin);
	gets(x.hoTen);
		printf("Nhap gioi tinh: ");
		scanf("%d",&x.gioiTinh);
		printf("Nhap ngay thang nam sinh: ");
	scanf("%d %d %d",&x.ngaySinh.ngay,&x.ngaySinh.thang,&x.ngaySinh.nam);
		printf("Nhap dia chi: ");
	fflush(stdin);
	gets(x.diaChi);
		printf("Nhap lop: ");
	fflush(stdin);
	gets(x.lop);
		printf("Nhap khoa: ");
	fflush(stdin);
	gets(x.khoa);
	return 1;
}
void NhapDSSV(list &l){
//	node *p=l.first;
printf("Bat dau nhap danh sach sinh vien: \n");
	SinhVien x;
	int flag=NhapSinhVien(x);
	while(flag){
		InsertLast(l,x);
		flag=NhapSinhVien(x);
	}
	printf("\n Ket thuc nhap danh sach sinh vien!");
}
void XuatDSSV(list l){
	node *p=l.first;
	char gt[10];
	while(p){
		if(p->data.gioiTinh==0) strcpy(gt,"Nam");
		else strcpy(gt,"Nu"); 
		printf("\n%8s %30s %10s %d/%d/%d %10s %12s %7s",p->data.maSV,p->data.hoTen,gt,p->data.ngaySinh.ngay,p->data.ngaySinh.thang,p->data.ngaySinh.nam,p->data.diaChi,p->data.lop,p->data.khoa);
	p=p->next;
	}
}
void RemoveAfter(list &l,node *p){
	node *q=p->next;
	p->next=q->next;
	delete q;
}
void RemoveFirst(list &l){
	node *p=l.first;
	l.first=p->next;
	delete p;
}
node *TimXoa(list l,char *msv){
	node *p=l.first;
	while(p){
		if(strcmp(p->next->data.maSV,msv)==0) return p;
		p=p->next;
	}
return NULL;	
}
void DeleteSV(list &l){
	printf("\nNhap ma sinh vien can xoa: ");
	char msv[8];
	fflush(stdin);
	gets(msv);
	if(strcmp(msv,l.first->data.maSV)==0) RemoveFirst(l);
	else if(TimXoa(l,msv)==NULL) printf("Khong tim thay sinh vien");
	else {
		node *p=TimXoa(l,msv);
		RemoveAfter(l,p);
	}
	WriteToFile(l, "dssv.txt");
}
void SortDSSv(list &l){
	for(node *i=l.first;i!=l.last;i=i->next)
		for(node *j=i->next;j!=NULL;j=j->next){
			if(strcmp(i->data.hoTen,j->data.hoTen)>0){
				SinhVien x=i->data;
				i->data=j->data;
				j->data=x;
			}
		}
}
node *TimViTriPhanTu(list l,char *hoTen){
	node *p=l.first;
	while(p!=NULL){
		if(strcmp(p->data.hoTen,hoTen)<0&&strcmp(p->next->data.hoTen,hoTen)>0) return p;
		p=p->next;
	}
	return NULL;
}
void ThemPhanTuKhongTrung(list &l){
	SinhVien x;
	NhapSinhVien(x);
	node *p=getNode(x);
	if(SearchSV(l,p->data.maSV)==1) {
	printf("Trung ma sv");return;}
	else if (strcmp(l.first->data.hoTen,p->data.hoTen)>0)
	{
		p->next=l.first;
		l.first=p;
	}
	else {
		node *q=TimViTriPhanTu(l,p->data.hoTen);
		if(q!=NULL){
		
		p->next=q->next;
		q->next=p;}
		else {
			l.last->next=p;
			l.last=p;
		}
	}
	WriteToFile(l, "dssv.txt");
}


int main() {
    list l;
    Init(l);
    int option;

    do {
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Sap xep danh sach sinh vien theo ten\n");
        printf("5. Them phan tu khong trung\n");
        printf("6. Doc danh sach sinh vien tu file\n");
        printf("7. Ghi danh sach sinh vien vao file\n");
        printf("0. Thoat\n");

        printf("Chon mot chuc nang: ");
        scanf("%d", &option);

        switch (option) {
            case 1:{
                NhapDSSV(l);
                WriteToFile(l, "dssv.txt");
            }break;
            case 2:
                XuatDSSV(l);
                break;
            case 3:
                DeleteSV(l);
                break;
            case 4:
                SortDSSv(l);
                printf("\nDanh sach sau khi sap xep\n");
                XuatDSSV(l);
                break;
            case 5:
                ThemPhanTuKhongTrung(l);
                printf("\nDanh sach sau khi them\n");
                XuatDSSV(l);
                break;
            case 6:
                if (ReadFromFile(l, "dssv.txt"))
                    printf("Doc file thanh cong!\n");
                break;
            case 7:
                if (WriteToFile(l, "dssv.txt"))
                    printf("Ghi file thanh cong!\n");
                break;
            case 0:
                break;
            default:
                printf("Chuc nang khong hop le.\n");
                break;
        }
    } while (option != 0);

    return 0;
}


