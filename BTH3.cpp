#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct thuebao
{
	char tentb[20];
	char sodt[10][11];
	char diachi[30];
	int  sosodt;
};

struct danhba 
{
	struct thuebao dulieu;
	struct danhba *lktruoc,*lksau;
};

void themcuoi(struct danhba **dau,struct thuebao x)
{
	struct danhba *q,*p;
	q=(struct danhba*) malloc(sizeof(struct danhba));
	q->dulieu=x;
	q->lksau=NULL;
	if(*dau==NULL)
	{
		q->lktruoc=NULL;
		*dau=q;
	}
	else 
	{
		p=*dau;
		while(p->lksau!=NULL) 
		   p=p->lksau;
		q->lktruoc=p;
		p->lksau=q;
	}
}

void nhapTB(struct thuebao *x)
{
	fflush(stdin);
	printf("nhap ten tb:");
	gets(x->tentb);
	printf("nhap dia chi:");
	gets(x->diachi);
	printf("nhap so so dien thoai:");
	scanf("%d",&x->sosodt);
	fflush(stdin);
	for(int i=0;i<x->sosodt;i++)
	{
		printf("nhap so dt thu %d cua thue bao:",i+1);
		gets(x->sodt[i]);
	}
}

void inTB(struct thuebao x)
{
	printf("%s %s   ",x.tentb,x.diachi);
	for(int i=0;i<x.sosodt;i++)
	{
		printf("%s",x.sodt[i]);
	}
}

void nhapDB(struct danhba **dau)
{

	struct thuebao x;
	int i;
	int n;
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
		p=p->lksau;
	}
}

void lietke(struct danhba *dau)
{
	struct danhba *p;
	p=dau;
	while(p!=NULL)
	{
		printf("danh ba gom cac thue bao:%s",p->dulieu.tentb);
		p=p->lksau;
	}
}

void xoa(struct danhba **dau, char x[])
{
	struct danhba *p,*p1,*p2;
	p=*dau;
	while (p!=NULL && strcmp(p->dulieu.tentb,x)!=0)
	   p=p->lksau;
	if(p!=NULL)
	{
		if(p==*dau)
		{
			*dau=(*dau)->lksau;
			(*dau)->lktruoc=NULL;
		}
		else
		{
			p1=p->lktruoc;
			p2=p->lksau;
			p1->lksau=p2;
			if(p2!=NULL) 
			   p2->lktruoc=p1;	
		}
		free(p);
	}
}

struct danhba* ghepDB(struct danhba *dau1, struct danhba *dau2)
{
	struct danhba *p,*q,*db3;
	db3=NULL;
	p=dau1;
	q=dau2;
	
		while(p!=NULL)
		  {
		  	themcuoi(&db3,p->dulieu);
		  	p=p->lksau;
		  }
	
		while(q!=NULL)
		  {
		  	themcuoi(&db3,q->dulieu);
		  	q=q->lksau;
		  }
	
	return db3;
}

void sapxepten(struct danhba *dau)
{
	struct thuebao tg;
	struct danhba  *p,*p1;
	p=dau;
	while(p->lksau!=NULL)
	{
		p1=p->lksau;
		while(p1!=NULL)
		{
		  if(strcmp(p->dulieu.tentb,p1->dulieu.tentb)>0)
		  {
			tg=p->dulieu;
			p->dulieu=p1->dulieu;
			p1->dulieu=tg;
		  }
		  p1=p1->lksau;
	    }
		p=p->lksau;
	}
}

main(void)
{
	struct danhba *db1,*db2,*db3;
	struct thuebao x;
	char ht[20];
	int n;
	
	db1=NULL;
	db2=NULL;
	db3=NULL;
	nhapDB(&db1);
	inDB(db1);
	/*nhapDB(&db2);
	inDB(db2);
	printf("nhap ten can xoa:");
	gets(ht);
	xoa(&db1,ht);
	inDB(db1);
	printf("danh ba sau khi ghep la:\n");
	db3=ghepDB(db1,db2);
	inDB(db3);*/
	printf("danh sach sau khi xep la:\n");
	sapxepten(db1);
	inDB(db1);
}



