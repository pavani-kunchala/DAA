#include<stdio.h>
int V;
int isSafe(int v,int graph[V][V],int color[],int c) 
{ int i;
   for (i=0;i<V;i++) 
     if (graph[v][i] && c == color[i]) 
         return 0; 
   return 1; 
} 
int colour(int graph[V][V],int m,int color[],int v) 
{ 
  int c;
  if (v == V) 
    return 1; 
   for (c = 1;c <= m;c++) 
    { 
     if (isSafe(v,graph,color,c)) 
	  {
	    color[v] = c; 
       if ( colour(graph, m,color,v+1)==1) 
         return 1; 
       else
		 //if assigning color c doesn't lead to solution then remove it:backtracking step
       color[v] = 0; 
     } 
    } 
  //if no color is assigned to this vertex
  return 0; 
} 

int graphColoring(int graph[V][V],int m) 
{ int i;
  int color[V]; 
  for(i=0;i<V;i++) 
      color[i]=0; 
   if (colour(graph,m,color,0)== 0) 
   { 
       printf("using %d color(s) , coloring of given graph not possible\n",m);
       return 0; 
   }
   printf("colors possible>>>\n"); 
   for(i=0;i<V;i++)
   {
     printf("%d ",color[i]);
	}
 return 1; 
} 
main() 
    {  
       
     int e,i,j; 
     printf("enter total no. of vertices & edges :\n");
     scanf("%d %d",&V,&e);
     int graph[V][V];
      for(i=0;i<V;i++)
          {
            for(j=0;j<V;j++)
             graph[i][j]=0;
          }
     while(e--)
      {
            int u,v;
            printf("enter u,v :");
            scanf("%d %d",&u,&v);
            graph[u][v]=1;
            graph[v][u]=1;
      }
          int m; // Number of colors
		    printf("Enter the maximum no. of colors to use:"); 
          scanf("%d",&m);
         // printf("%d\n\n",graphColoring(graph, m)); 
          graphColoring(graph, m);
} 
 
