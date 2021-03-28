#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct SV
{
	char hoten[20]; 
	double dtb;
	int namsinh;
};

struct DSSV 
{
	struct SV dulieu;
	struct DSSV *lienket;
};

void themcuoi(struct DSSV **dau, struct SV x)
{
	struct DSSV *p,*q;
	q=(struct DSSV*)malloc(sizeof(struct DSSV));
	q->dulieu=x;
	q->lienket=NULL;
	if(*dau==NULL)
	{
		*dau=q;
	}
	else 
	{
		p=*dau;
		while (p->lienket!=NULL)
		{
			p=p->lienket;
		}
		p->lienket=q;
	}
}

void nhapsv(struct SV *dau)
{
	fflush(stdin);
	printf("nhap ho va ten:");
	gets(dau->hoten);
	printf("nhap dtb:");
	scanf("%lf",&dau->dtb);
	fflush(stdin);
	printf("nhap nam sinh:");
	scanf("%d",&dau->namsinh);
}


void insv(struct SV dau)
{
	printf("%s %0.1lf %d",dau.hoten,dau.dtb,dau.namsinh);
}

void nhapDSSV(struct DSSV **dau)
{
	struct SV x;
	int i,n;
	printf("nhap so sv:");
	scanf("%d",&n);
	*dau=NULL;
	for(i=0 ;i<n;i++)
	{
		nhapsv(&x);
		themcuoi(dau,x);
	}	
}

void inDSSV(struct DSSV *dau)
{
	struct DSSV *p;
	p=dau;
	while(p!=NULL)
	{
		insv(p->dulieu);
		printf("\n");
		p=p->lienket;
	}
	
}

int dem(struct DSSV *dau)
{
	struct DSSV *p;
	int d=0;
	p=dau;
	while(p!=NULL)
	{
		d++;
		p=p->lienket;
		
	}
	return d;
}

struct DSSV* taoDSSV(struct DSSV *dau)
{
	struct DSSV *p,*q;
	q=(struct DSSV*)malloc(sizeof(struct DSSV));
	q=NULL;
	p=dau;
	while(p!=NULL)
	{
		if(p->dulieu.dtb>=8)
		{
			themcuoi(&q,p->dulieu);
		
		}
		p=p->lienket;
	}
	return q;
}

void xoaSV(struct DSSV **dau, char *x)
{
	struct DSSV *p,*p1;
	p=*dau;
	while (p!=NULL)
	{
		if(strcmp(p->dulieu.hoten,x)==0)
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
			p1=p->lienket;
			
		}
		free(p);
	}
}

void themSV(struct DSSV **dau, struct SV x, int k)
{
	int i;
	struct DSSV *p,*q;
	q=(struct DSSV*)malloc(sizeof(struct DSSV));
	q->dulieu=x;
	if(k==0)
	{
		q->lienket=*dau;
		*dau=q;
	}
	else
	{
		p=*dau;
			for(i=1;i<=k-1;i++)
			   p=p->lienket;
			q->lienket=p->lienket;
			p->lienket=q;
	}
}

void xoaSV(struct DSSV **dau,int k)
{
	struct DSSV *p,*q;
	int i;
	if(k==0)
	{
		*dau==NULL;
	}
	else 
	{
		p=*dau;
		for(i=1;i<=k-1;i++)
		   p=p->lienket;
		q=p->lienket;
		p->lienket=q->lienket;
		free(q);
	}
}

main(void)
{
	struct DSSV *ds1,*ds2;
	struct SV x;
	int d;
	char ht[20];
	ds1=NULL;
	ds2=NULL;
	nhapDSSV(&ds1);
	inDSSV(ds1);
	d=dem(ds1);
	printf("\nso sinh vien la: %d",d);
	ds2=taoDSSV(ds1);
	inDSSV(ds2);
	printf("\nnhap sinh vien can xoa:");
	fflush(stdin);
	gets(ht);
	xoaSV(&ds1,ht);
	inDSSV(ds1);*/
	printf("\nnhap SV can them:\n");
	nhapsv(&x);
	themSV(&ds1,x,0);
	inDSSV(ds1);
	printf("\ndanh sach sau khi xoa la:\n");
	xoaSV(&ds1,1);
	inDSSV(ds1);
}
