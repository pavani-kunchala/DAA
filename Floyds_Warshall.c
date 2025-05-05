#include<stdio.h>
void Floyds(int D[10][10],int n,int P[10][10])
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
	 printf("\n**** k=%d ****:\n",k); 
		if(k==n)
		printf("\nthese are the final distance and parent matrices::\n");
		printf("\nthe distance matrix is :\n");
			for(i=1;i<=n;i++)
		{ 
			for(j=1;j<=n;j++)
			{
				if(D[i][j]>D[i][k]+D[k][j])
		   	{
				  P[i][j] = P[k][j] ; 
			    D[i][j] = D[i][k]+D[k][j];
				}
				 printf("%d\t",D[i][j]); 
			}
			printf("\n");
		}
		printf("\nThe parent matrix is :\n");
		for(i=1;i<=n;i++)
		 { 
			for(j=1;j<=n;j++)
			{
			 printf("%d\t",P[i][j]);
			}
			printf("\n");
		} 
	}
}
main()
{
	int n,i,j,D[10][10],P[10][10];
	printf("\nEnter the no. of nodes:");
	scanf("%d",&n);
	printf("\nEnter the cost matrix (Enter 100 if edge is not there & Enter 0 if loop is not there) ::\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&D[i][j]);
		}
	}
	printf("\n**** k=0 ****:\n");
	printf("\nthe distance matrix is :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",D[i][j]);
		}
		printf("\n");
	}
	printf("\nthe parent matrix is :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			 if(i==j||D[i][j]==100)
			{
			   P[i][j]=-1;
		   	printf("%d\t",P[i][j]); 
     		}
			 else
			 {
			 	P[i][j]=i;
			 	printf("%d\t",P[i][j]);
			 } 
		}
		printf("\n");
	}
	Floyds(D,n,P);
}
