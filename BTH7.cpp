#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct nguoi
{
	char hoten[20];
	int namsinh;
	
};

struct caytq
{
	struct nguoi dulieu;
	struct caytq *con, *em;
};

struct caytq* taonut(struct nguoi ng, struct caytq *p, struct caytq *q)
{
	struct caytq *a;
	a=(struct caytq*)malloc(sizeof(struct caytq));
	a->dulieu=ng;
	a->con=p;
	a->em=q;
	return a;
}

struct caytq* taocay()
{
	struct nguoi ng1,ng2,ng3,ng4,ng5,ng6,ng7,ng8;
	struct caytq *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8;
	strcpy(ng8.hoten,"H");
	ng8.namsinh=2000;
	n8=taonut(ng8,NULL,NULL);
	
	strcpy(ng7.hoten,"G");
	ng7.namsinh=1999;
	n7=taonut(ng7,NULL,n8);
	
	strcpy(ng6.hoten,"F");
	ng6.namsinh=2001;
	n6=taonut(ng6,NULL,NULL);
	
	strcpy(ng5.hoten,"E");
	ng5.namsinh=1998;
	n5=taonut(ng5,NULL,n6);
	
	strcpy(ng4.hoten,"D");
	ng4.namsinh=2000;
	n4=taonut(ng4,NULL,n5);
	
	strcpy(ng3.hoten,"C");
	ng3.namsinh=1890;
	n3=taonut(ng3,n7,NULL);
	
	strcpy(ng2.hoten,"B");
	ng2.namsinh=1870;
	n2=taonut(ng2,n4,n3);
	
	strcpy(ng1.hoten,"A");
	ng1.namsinh=1850;
	n1=taonut(ng1,n2,NULL);

}

void incay(struct caytq *goc)
{
	struct caytq *q[50],*p;
	int dau, cuoi;
	dau=0; 
	cuoi=0;
	q[0]=goc;
	while(dau<=cuoi)
	{
		p=q[dau];
		dau++;
		printf("%s %d  ",p->dulieu.hoten,p->dulieu.namsinh);
		p=p->con;
		while(p!=NULL)
		{
			cuoi++;
			q[cuoi]=p;
			p=p->em;
		}
	}
}

int dem(struct caytq *goc)
{
	int d1,d2;
	struct caytq *p;
	if(goc!=NULL)
	{
		p=goc;
		while(p!=NULL)
		{
			d1=dem(p->con);
			d2=dem(p->em);
		    return d1+d2+1;	
		}	
   }
}
struct caytq* tim(struct caytq *goc, char x[20])
{
	struct caytq *p,*q;
	if(goc==NULL)
	  return NULL;
	else
	{
		p=goc;
		while(p!=NULL)
		{
			if(strcmp(p->dulieu.hoten,x)==0)
			   return p;
			else 
			  q=tim(p->con,x);
			    if(q!=NULL)
			     return q;
			    else
			     return tim(p->em,x);
		}
	}
}

int tinhchieucao(struct caytq *goc)
{
	int h,max;
	h=0;max=0;
	struct caytq *p;
	if(goc==NULL)
	 return 0;
	else
	 {
	 	p=goc->con;
	 	while(p!=NULL)
	 	{
	 		h=tinhchieucao(p);
	 		if(h>max)
	 		 max=h;
	 		else
	 		 p=p->em;
		}
		return max+1;
	 }
		
	
}

main(void)
{
	struct caytq *cay,*kq;
	char x[20];
	int d;
	cay=taocay();
	incay(cay);
	d=dem(cay);
	printf("\nso nguoi trong cay la:%d\n", d);
	printf("nguoi can tim la:");
	fflush(stdin);
	gets(x);
	kq=tim(cay,x);
	if(kq=NULL)
	 printf("\nkhong co nguoi %s trong cay",x);
	else 
	 printf("nguoi %s co trong cay",x);
	printf("\nchieu cao cua cay la:%d",tinhchieucao(cay));
}
