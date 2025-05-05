#include<stdio.h>
void Hamiltanian(int G[10][10],int k,int n)
{ int x[n],i;
	NextValue(k,x,G,n);
	if(x[k]==0) 
	if(k==n)
	{
		for(i=1;i<=n;i++)
			printf("%d -->",x[i]);
	}
   else
   Hamiltanion(G,k+1,n);
}
int NextValue(int k,int x[10],int G[10][10],int n)
{  int j;
	x[k]=(x[k]+1)%(n+1);
	if(x[k]==0) 
	if(G[k-1],x[k]!=0)
	{
		for(j=1;j<=k-1;j++)
		{
			if(x[j]==x[k]) break;
			if(j==k)
			{
				if((k<n)||((k==n)&& G[x[n]][x[1]]!=0))
				 return 0;
			}
		}
	}
}
main()
{  int G[10][10],i,j,k,n;
   printf("Enter no. of nodes:");
   scanf("%d",&n);
	printf("Enter the matirx:");
 	printf("\nthe distance matrix is :\n");
 	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	Hamiltanian(G,1,n);
}
