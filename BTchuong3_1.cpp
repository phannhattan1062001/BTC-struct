#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct nguoi
{
    char hoten[30];
	int namsinh;	
};

struct cnp
{
	struct nguoi dulieu;
	struct cnp *trai, *phai;
};

struct cnp* taonut(struct nguoi ng, struct cnp *tr, struct cnp *ph)
{
	struct cnp *p;
	p=(struct cnp*) malloc(sizeof(struct cnp));
	p->dulieu=ng;
	p->trai=tr;
	p->phai=ph;
	return p;
}

struct cnp* taocay()
{
	struct nguoi ng1,ng2,ng3,ng4,ng5,ng6;
	struct cnp *n1,*n2,*n3,*n4,*n5,*n6;
	strcpy(ng1.hoten,"D");
	ng1.namsinh=1999;
	n1=taonut(ng1,NULL,NULL);
	
	strcpy(ng2.hoten,"E");
	ng2.namsinh=1998;
	n2=taonut(ng2,NULL,NULL);
	
	strcpy(ng3.hoten,"F");
	ng3.namsinh=1997;
	n3=taonut(ng3,NULL,NULL);
	
	strcpy(ng4.hoten,"C");
	ng4.namsinh=1980;
	n4=taonut(ng4,n2,n3);
	
	strcpy(ng5.hoten,"B");
	ng5.namsinh=1970;
	n5=taonut(ng5,NULL,n1);
	
	strcpy(ng6.hoten,"A");
	ng6.namsinh=1950;
	n6=taonut(ng6,n5,n4);
	return n6;
}

void incay(struct cnp *goc)
{
	if(goc!=NULL)
	{
		printf("%s %d  ",goc->dulieu.hoten,goc->dulieu.namsinh);
		incay(goc->trai);
		incay(goc->phai);
	}
}

int demnguoi(struct cnp *goc)
{
	
		if(goc==NULL)
		   return 0;
		else
		{
			int d1,d2;
		    d1=demnguoi(goc->trai) ; 
	        d2=demnguoi(goc->phai)  ; 
	        return d1+d2+1;
	    }
	
}

int demthehe(struct cnp *goc)
{
	int h,h1,h2;
	if(goc==NULL)
	  return 0;
	else 
	{
		h1=demthehe(goc->trai);
		h2=demthehe(goc->phai);
   }
   if(h1>h2) h=h1+1;
   else h=h2+1;
   return h;
}

struct cnp* timhoten(struct cnp *goc, char t[20])
{
	struct cnp *p;
	if(goc!=NULL)
	{
		if(strcmp(goc->dulieu.hoten,t)==0)
		   return goc;
	    else 
	    {
		p=timhoten(goc->trai,t);
		if(p!=NULL)
		  return p;
	    else 
		  return timhoten(goc->phai,t);
	    }
	}
	else 
	return NULL;
}

int kiemtracon(struct cnp *goc, char x[], char y[])
{
	struct cnp *p;
	p=timhoten(goc,x);
	if(p==NULL)
	  return 0;
	else 
	{
		if(((p->trai!=NULL)&&(strcmp(p->trai->dulieu.hoten,y)==0))||((p->phai!=NULL)&&(strcmp(p->phai->dulieu.hoten,y)==0)))
		  return 1;
		else 
		  return 0;
	}
}

int demtuoi(struct cnp *goc, int x)
{
	
	if(goc==NULL)
	  return 0;
	else
	{
		if(goc->dulieu.namsinh>x)
		  return 1;
		else
		{
			int d1,d2;
			d1=demtuoi(goc->trai,)
			
		}
		
	
	}
}

main(void)
{
	struct cnp *goc,*kq;
	char ht[20],nf[20],ns[20];
	int d,d1,q,t,p;
	goc=NULL;
	goc=taocay();
	incay(goc);
	/*d=demnguoi(goc);
	printf("\nso nguoi co trong cay la: %d",d);
	d1=demthehe(goc);
	printf("\nso the he trong cay la:%d",d1);
	fflush(stdin);
	printf("\nnhap ho ten can tim:");
	gets(ht);
	kq=timhoten(goc,ht);
	if(kq==NULL)
	  printf("khong co nguoi ten %s trong cay",ht);
	else 
	 printf("co nguoi ten %s trong cay",ht);
	printf("\nnhap ten hai nguoi can kiem tra:");
	fflush(stdin);
	gets(nf);
	gets(ns);
	q=kiemtracon(goc,nf,ns);
	if(q==1)
	 printf("nguoi %s la con cua nguoi %s",ns,nf);
	else 
	 printf("hai nguoi nay khong phai cha con");*/
	printf("\nnhap moc tuoi can dem:");
	scanf("%d",&t);
	p=demtuoi(goc,t);
	printf("\nso nguoi co nam sinh nho hon %d la: %d ",t,p);
	
	
	
}
