#include<stdio.h>
#include<stdlib.h>
struct node{
	float heSo;
	int soMu;
	node *next;
};
struct list{
	node *first,*last;
};
void Init(list &l){
	l.first=l.last=NULL;
}
node *getNode(float heSo,int soMu){
	node *p;
	p=new node;
	if(p==NULL) return  NULL;
	p->heSo=heSo;
	p->soMu=soMu;
	p->next=NULL;
	return p;
}
void AddLast(list &l, node *new_ele){
	if(l.first==NULL) l.first=l.last=new_ele;
	else {
		l.last->next=new_ele=
		l.last=new_ele;
	}
}
void InsertLast(list &l,float heSO,int soMu){
	node *new_ele=getNode(heSO,soMu);
	if(new_ele==NULL) return ;
	AddLast(l,new_ele);
}

void nhapDaThuc(list &l){
	float heSo;
	int soMu;
	printf("\nBat dau nhap da thuc(nhap he so 0 de ket thuc:\n");
	do{
		printf("nhap he so: ");
		scanf("%f",&heSo);
		if(heSo==-0) break;
		printf("Nhap so mu: ");
		scanf("%d",&soMu);
		InsertLast(l,heSo,soMu);
	
	}while(heSo!=0);
	printf("\nDa nhap da thuc xong:\n");
}
void xuatDanhSach(list l){
	node *p;
	p=l.first;
	while(p!=NULL){
		printf("%.0f, %d   ",p->heSo,p->soMu);
		p=p->next;
	}
}
void CongDaThuc(list l1, list l2, list &l3){
	Init(l3);
	node *p=l1.first,*q=l2.first;
	float tongHeSo;
	while(p&&q){
		if(p->soMu==q->soMu){
			tongHeSo=p->heSo+q->heSo;
			if(tongHeSo!=0) 
					InsertLast(l3,tongHeSo,p->soMu);
			p=p->next;
			q=q->next;
		}
		else {
			if(p->soMu>q->soMu){
			
			InsertLast(l3,p->heSo,p->soMu);
			p=p->next;}
		
		else {
			if(p->soMu<q->soMu){
			
				InsertLast(l3,q->heSo,q->soMu);
				q=q->next;
			}
		}
		} 
	}
	while(q){
		
			InsertLast(l3,q->heSo,q->soMu);
			
			q=q->next;
		
	}
	while(p){
		InsertLast(l3,p->heSo,p->soMu);
		p=p->next;
	}
}
void Swap1(float &p, float &q){
	int m;
//	if(p!=NULL&&q!=NULL){
	
	m=p;
	p=q;
	q=m;
}
void Swap2(int &p, int &q){
	int m;
//	if(p!=NULL&&q!=NULL){
	
	m=p;
	p=q;
	q=m;
}
void InterchangeSort(list &l){
	for(node *p=l.first;p!=l.last;p=p->next)
	for(node *q=p->next;q!=NULL;q=q->next)
		if(p->soMu>q->soMu){
			Swap1(p->heSo,q->heSo);
			Swap2(p->soMu,q->soMu);
		}
}
void Printftheodang(list l){
	node *p=l.first;
	printf(" \nxuat danh sach theo dang nguyen mau: \n");
	while(p!=NULL){
		if(p==l.first) {
			if(p->heSo>0)
		printf("%.0f*x^%d ",p->heSo,p->soMu);
		else printf("%.0f*x^%d ",p->heSo,p->soMu);
		}
		else {
		
		if(p->heSo>0)
				printf("+%.0f*x^%d ",p->heSo,p->soMu);
		else printf("%.0f*x^%d ",p->heSo,p->soMu);
	}
		p=p->next;
	}
}
int main()
{
	list l1,l2,l3;

	Init(l1);	
	Init(l2);
	Init(l3);
	nhapDaThuc(l1);
	printf("\nDanh sach bieu dien da thuc l1: ");
	InterchangeSort(l1);
	xuatDanhSach(l1);
	Printftheodang(l1);
	nhapDaThuc(l2);
	printf("\nDanh sach bieu dien da thuc l2: ");
	InterchangeSort(l2);
	xuatDanhSach(l2);
	Printftheodang(l2);
	CongDaThuc(l1,l2,l3);
	printf("\nDanh sach bieu din da thuc tong: ");
	xuatDanhSach(l3);
	Printftheodang(l3);
}

