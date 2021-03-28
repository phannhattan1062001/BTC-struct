#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct nguoi
{
	char hoten[30];
	int namsinh;
};

struct cnp
{
	struct nguoi dulieu;
	struct cnp *trai,*phai;
};

struct cnp* taonut(struct nguoi ng, struct cnp *t, struct cnp *p)
{
	struct cnp *q;
	q=(struct cnp*) malloc(sizeof(struct cnp));
	q->dulieu=ng;
	q->trai=t;
	q->phai=p;
	return q;
}

struct cnp* taocay()
{
	struct nguoi ng1,ng2,ng3,ng4,ng5,ng6;
	struct cnp *n1,*n2,*n3,*n4,*n5,*n6;
	fflush(stdin);
	strcpy(ng1.hoten,"D"); 
	ng1.namsinh=2005;
	n1=taonut(ng1,NULL,NULL);
	
	strcpy(ng2.hoten,"E"); 
	ng2.namsinh=2002;
	n2=taonut(ng2,NULL,NULL);
	
	strcpy(ng3.hoten,"F"); 
	ng3.namsinh=2000;
	n3=taonut(ng3,NULL,NULL);
	
	strcpy(ng4.hoten,"B"); 
	ng4.namsinh=1995;
	n4=taonut(ng4,NULL,n1);
	
	strcpy(ng5.hoten,"C"); 
	ng5.namsinh=1990;
	n5=taonut(ng5,n2,n3);
	
	strcpy(ng6.hoten,"A"); 
	ng6.namsinh=1980;
	n6=taonut(ng6,n4,n5);
	
	return n6;
}

void incay(struct cnp *goc)
{
	if(goc!=NULL)
	{
		printf("%s  %d ",goc->dulieu.hoten,goc->dulieu.namsinh);
		incay(goc->trai);
		incay(goc->phai);
	}
}

int demNS(struct cnp *goc,int n)
{
	int d1,d2;
	if(goc==NULL)
	   return 0;
	else
	{
		if(goc->dulieu.namsinh<n)
		{
			d1=demNS(goc->trai,n);
			d2=demNS(goc->phai,n);
			return d1+d2+1;
		}
		else return 0;
	}		
}

struct cnp* tim(struct cnp *goc, char x[20])
{
	struct cnp *p;
	if(goc==NULL)
	 return NULL;
	else
	{
		if(strcmp(goc->dulieu.hoten,x)==0)
		  return goc;
		else
		{
			p=tim(goc->trai,x);
			if(p!=NULL)
			 return p;
			else
			 return tim(goc->phai,x);
		}		
	}
}

int timthehe(struct cnp *goc, char x[20])
{
	int h1,h2;
	if(goc==NULL)
	 return 0;
	else 
	{
		if(strcmp(goc->dulieu.hoten,x)==0)
		 return 1;
		else 
		{
			h1=timthehe(goc->trai,x);
			h2=timthehe(goc->phai,x);
			if(h1!=NULL)
			 return h1+1;
			else 
			 if(h2!=NULL)
			  return h2+1;
			else 
			return 0;
		
		}
	}
}

void incayTH(struct cnp *goc,int n)
{
	if(goc!=NULL)
	{
		printf("%s  %d  ",goc->dulieu.hoten,goc->dulieu.namsinh);
		if(TH==2)
		{
			printf("\nnhung nguoi the he thu 2 la:");
		    incayTH(goc->trai);
		    incayTH(goc->phai);
		}
		else
		  if(TH==3)
		{
			printf("\nnhung nguoi the he thu 3 la:");
		    incayTH(goc->trai);
		    incayTH(goc->phai);
		}
		 
	}
}

main(void)
{
	struct cnp *goc,*kq;
	int d, d1;
	char ht[20],ht1[20];
	goc=taocay();
	incayeq(goc);
    /*d=demNS(goc,2000);
	printf("\nso nguoi co nam sinh nho hon nam 2000 la: %d",d);
	printf("\nnhap ten nguoi can tim:");
	gets(ht);
	kq=tim(goc,ht);
	if(kq==NULL)
	  printf("\ntrong cay khong co nguoi nay");
	else 
	 printf("\ntrong cay co nguoi nay");
	printf("\nnhap ten nguoi can tim:");
	gets(ht1);
	d1=timthehe(goc,ht1);
	printf("nguoi can tim o the he thu:%d",d1);*/
	
	
	
	
}
