#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct thuebao
{
	char tentb[30];
	char diachi[30];
	char sodt[10][11];
	int sosodt;
};

struct danhba
{
	struct thuebao dulieu;
	struct danhba *lienket;
};

void themcuoi(struct danhba **dau, struct thuebao x)
{
	struct danhba *p,*q;
	q=(struct danhba*)malloc(sizeof(struct danhba));
	q->dulieu=x;
	q->lienket=NULL;
	if(*dau==NULL)
	{
		*dau=q;
	}
	else 
	{
		p=*dau;
		while(p->lienket!=NULL)
		   p=p->lienket;
		p->lienket=q;
	}	
}

void nhapTB(struct thuebao *dau)
{
	int i;
	fflush(stdin);
	printf("nhap ten thue bao:");
	gets(dau->tentb);
	printf("nhap dia chi thue bao:");
	gets(dau->diachi);
	printf("nhap so so dien thoai:");
	scanf("%d",&dau->sosodt);
	fflush(stdin);
	for(i=0;i<dau->sosodt;i++)
	{
		printf("nhap so dt thu %d cua thue bao:",i);
		gets(dau->sodt[i]);
	}
}

void inTB(struct thuebao dau)
{
	int i;
	printf("%s %s ",dau.tentb,dau.diachi);
	for(i=0;i<dau.sosodt;i++)
	{
		printf("%s",dau.sodt[i]);
	}
}

void nhapDB(struct danhba **dau)
{
	struct thuebao x;
	int i,n;
	printf("nhap so thue bao:");
	scanf("%d",&n);
	*dau=NULL;
	for(i=0;i<n;i++)
	{
		nhapTB(&x);
		themcuoi(dau,x);
	}
}

void inDB(struct danhba *dau)
{
	struct danhba *p;
	p=dau;
	while(p!=NULL)
	{
		inTB(p->dulieu);
		printf("\n");
		p=p->lienket;
	}
}

void themdau(struct danhba **dau,struct thuebao x)
{
	struct danhba *q;
	q=(struct danhba*)malloc(sizeof(struct danhba));
	q->dulieu=x;
	q->lienket=*dau;
	*dau=q;
}

void themvaosau(struct danhba **dau, struct thuebao x, char ht[])
{
	int i;
	struct danhba *p,*q;
	q=(struct danhba*)malloc(sizeof(struct danhba));
	q->dulieu=x;
	q->lienket=NULL;
	p=*dau;
	while(p!=NULL)
	{
	    if(strcmp(p->dulieu.tentb,ht)==0)
	    break;
	    else p=p->lienket;
    }
    if(p!=NULL)
	{
       	   q->lienket=p->lienket;
       	   p->lienket= q;
	}
}

int dem(struct danhba *dau)
{
	int d=0;
	struct danhba *p;
	p=dau;
	while (p!=NULL)
	{
		d++;
		p=p->lienket;
	}
	return d;
}

void lietke(struct danhba *dau)
{
	struct danhba *p;
	p=dau;
	while(p!=NULL)
	{
		printf("%s",p->dulieu.tentb);
		p=p->lienket;
	}
}

void xoaTB(struct danhba **dau, char x[])
{
	struct danhba *p,*p1;
	p=*dau;
	while(p!=NULL)
	{
		if(strcmp(p->dulieu.tentb,x)==0)
		break;
		else 
		{
			p1=p;
			p=p->lienket;
		}
	}
		if(p!=NULL)
		{
			if(p==*dau)
			{
				*dau=p->lienket;
			}
			else 
			{
				p1->lienket=p->lienket;
			}
			free(p);
		}
	
}

struct danhba* timSDT(struct danhba *dau, char sdt[])
{
	int i;
	struct danhba *p;
	p=dau;
	while (p!=NULL)
	{
		for(i=0;i<p->dulieu.sosodt;i++)
		{
		    if(strcmp(p->dulieu.sodt[i],sdt)==0)
		    return p;
	    }
	    p=p->lienket;
	}
	return NULL;
}

void themSDT(struct danhba **dau, char ten[], char sdt[])
{
	struct danhba *p;
	p=*dau;
	while(p!=NULL)
	{
		if(strcmp(p->dulieu.tentb,ten)==0)
		    {
			   strcpy(p->dulieu.sodt[p->dulieu.sosodt],sdt);
		       p->dulieu.sosodt++;
		       return ;
		    }
		else
		  p=p->lienket;	 	   
	}
}

void xoaSDT(struct danhba **dau, char sdt[])
{
	int i,j;
	struct danhba *p;
	p=*dau;
	while(p!=NULL)
	{
		for(i=0;i<p->dulieu.sosodt;i++)
		{
			if(strcmp(p->dulieu.sodt[i],sdt)==0)
			  {
			    for(j=i;j<p->dulieu.sosodt-1;j++)
			    {
			    	strcpy(p->dulieu.sodt[j],p->dulieu.sodt[j+1]);
				}
				p->dulieu.sosodt--;
			    return;
		      }
		   
	   }
	   p=p->lienket;
	}
}

main(void)
{
	int d;
	struct danhba *db,*kq;
	struct thuebao x;
	char ten1[30], ten2[30], sdt1[10], sdt2[10],ht[20];
	nhapDB(&db);
	inDB(db);
	d=dem(db);
	printf("so thue bao la:%d",d);
	printf("\nnhap thue bao can them:\n");
	nhapTB(&x);
    fflush(stdin);
    printf("\nnhap ho ten can them sau:");
    gets(ht);
	themvaosau(&db,x,ht);
	inDB(db);
	/*printf("\nnhap ten can xoa:");
	fflush(stdin);
	gets(ten1);
	xoaTB(&db,ten1);
	inDB(db);
	printf("\nnhap so dien thoai can tim :");
	fflush(stdin);
	gets(sdt1);
	kq=timSDT(db,sdt1);
	if(kq==NULL)
		printf("khong tim  thay");
	else 
	   {
	   printf("thong tin so dien thoai can tim la:\n");
	   inTB(db->dulieu);
       }
	printf("\nnhap ten thue bao can them:");
	fflush(stdin);
	gets(ten2);
	printf("\nnhap so dien thoai can them :");
	fflush(stdin);
	gets(sdt2);
	themSDT(&db,ten2,sdt2);
	inDB(db);
	printf("\nnhap so dien thoai can them :");
	fflush(stdin);
	gets(sdt2);
	xoaSDT(&db,sdt2);
	inDB(db);*/
	
}
