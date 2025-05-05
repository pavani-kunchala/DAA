#include<stdio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int cost[MAX][MAX],int n, int startnode)
{
	int distance[MAX],path[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];//infinity 
		path[i]=startnode;//-1 or 0
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	//till n-1 edges have been inserted in the tree
	while(count<n-1)
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)
		{
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
   	}
		visited[nextnode]=1;
		for(i=0;i<n;i++)
	   {
			if(!visited[i])
			{
			   if(mindistance+cost[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					path[i]=nextnode;
				}
		   }
	   }
	   count++; 
	}
	for(i=0;i<n;i++)
	{
	//	if(i!=startnode)
	//	{
			printf("\nDistance of %d = %d",i,distance[i]);
			printf("\nPath = %d",i);
			j=i;
			do{
				j=path[j];
				printf(" <- %d",j);
			  }while(j!=startnode);
		//}
	}
	
}

main()
{
 int G[MAX][MAX],i,j,n,u;
 printf("\nEnter the no. of vertices:");
 scanf("%d",&n);
 printf("Enter the adjacency matrix:\n");
 for(i=0;i<n;i++)
 {
 	for(j=0;j<n;j++)
 	{
 		scanf("%d",&G[i][j]);
 		  if(G[i][j]==0)
 		     G[i][j]=INFINITY;
	 }
 } 
	 printf("\nEnter the starting node:");
	 scanf("%d",&u);
	 dijkstra(G,n,u);
}
