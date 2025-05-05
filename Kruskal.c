//kruskal's algorithm implementation 
 #include<stdio.h>
 int i,j,k,a,b,u,v,nv,ne=1;
 int min,mincost=0,adj[25][25],parent[25];
 
 int find(int i)
 {
 	while(parent[i])
 	i=parent[i];
 	return i;
 }
 
 int uni(int i,int j)
 {
 	if(i!=j)
 	{
 		parent[j]=i;
 		return i;
	 }
	 //if i==j
	 return 0;
 }
 
 main()
 {
 	printf("\nEnter the no. of vertices:");
 	scanf("%d",&nv);
 	printf("\nEnter the cost adjacency matrix:\n");
 	for(i=1;i<=nv;i++)
 	{
 		for(j=1;j<=nv;j++)
 		{
 			scanf("%d",&adj[i][j]);
 			if(adj[i][j]==0)
 			  adj[i][j]=999;
		 }
	 }
	 printf("the edges of Minimum Cost Spanning Tree are\n");
	 //runs v-1 times e=v-1 
	 while(ne<nv)
	 { //  select the minimal cost edge 
	 	for(i=1,min=999;i<=nv;i++)
	 	{
	 		for(j=i;j<=nv;j++)
	 		{
	 			if(adj[i][j]<min)
	 		   {
	 		   		min=adj[i][j];
	 		   		a=u=i;
	 		   		b=v=j;
				 }
	 			
			 }
		 }
		 u=find(u);
		 v=find(v);
		 if(uni(u,v))
		 {
		 	printf("%d edge (%d,%d) = %d\n",ne++,a,b,min);
		 	mincost+=min;
		 }
		 //for not select that edge multiple times 
		adj[a][b]=adj[b][a]=999;
	 }
	 printf("\n minimum cost = %d\n",mincost);
 }
 
