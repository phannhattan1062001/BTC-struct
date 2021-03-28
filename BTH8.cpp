#include<stdio.h>
struct dothi
{
	int sodinh;
	int mtk[10][10];
};

int datham[10];
int d=0;


void doctep(char *tentep,struct dothi *g )
{
	FILE *f;
	f=fopen(tentep,"r");
	fscanf(f,"%d",&g->sodinh);
	for(int i=0;i<g->sodinh;i++)
	    {
	    	for(int j=0;j<g->sodinh;j++)
	    	{
	    		fscanf(f,"%d",&g->mtk[i][j]);
			}
		
		}
	fclose(f);
}

void inDT(struct dothi g)
{
	printf("%d\n",g.sodinh);
	for(int i=0;i<g.sodinh;i++)
	   {for(int j=0;j<g.sodinh;j++)
	      printf("%d   ",g.mtk[i][j]);
	    printf("\n");
       }
}

void duyetsau(struct dothi g, int v)
{
	printf("%d  ", v);
	datham[v]=1;
	for(int w=0;w<g.sodinh;w++)
	{
		if(datham[w]==0&&g.mtk[v][w]==1)
		   duyetsau(g,w);
	}
}

void duyetrong( struct dothi g, int v)
{
	int q[20], dau, cuoi;
	dau=0; cuoi =0;
	q[0]=v;
	datham[v]=1;
	while(dau<=cuoi)
	{
		v=q[dau]; dau++;
		printf("%d ",v);
		for (int w=0;w<g.sodinh;w++)
		{
			if(g.mtk[v][w]==1&&datham[w]==0)
			{
				cuoi++;
			    q[cuoi]=w;
			    datham[w]==1;
			}
		}
	}
}

int kt(struct dothi g,int v)
{
	datham[v]=1;
	for(int w=0;w<g.sodinh;w++)
	{
		if(datham[w]==0&&g.mtk[v][w]==1)
		    {
		    	duyetsau(g,w);  
			}
	}
	
	for(int i=0;i<g.sodinh;i++)
	{
		if(datham[i]==1)
		  d++;
		else return 0;
	}
	return d;
	
}

main(void)
{
	struct dothi g;
	int tt;
	doctep("td1.txt",&g);
	/*inDT(g);
	duyetsau(g,2);
	duyetrong(g,1);*/
	tt=kt(g,0);
	if(tt!=g.sodinh)
	 printf("\nday ko phai la do thi lien thong");
	else 
	 printf("\nday la do thi lien thong");
}
