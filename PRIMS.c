//Prims algorithm implementation
#include<stdio.h>
void Prims(int n,int cost[10][10])
{
	int i,j,u,v,min,mincost=0,visited[10],ne=1;
	for(i=1;i<=n;i++)
	  visited[i]=0;
	printf("The edges considered for MST are \n");
	visited[1]=1; //selected edge making visited
	while(ne<n)
	{ //adjacent minimal edge and unvisited(visited visited forms cycle)
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{ 
				  if(visited[i]!=0)
				  {
				  	min=cost[i][j];
					u=i;
					v=j;
				  }
				  else
				  continue;
				}
			}
		}
	if( visited[u]==0 || visited[v]==0 )
	{
		printf("%d Edge(%d,%d) = %d\n",ne++,u,v,min);
		mincost=mincost+min;
		visited[v]=1;
	}
	cost[u][v]=cost[v][u]=999;
	}
	printf("\nminimal cost = %d",mincost);
}

main()
{
	int i , j, nv,cost[10][10];
	printf("\n enter the no. of vertices:");
	scanf("%d",&nv);
	printf("\n enter the cost matrix:\n");
	for(i=1;i<=nv;i++)
	{
		for(j=1;j<=nv;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=999;
		}
	}
	Prims(nv,cost);
}
 
