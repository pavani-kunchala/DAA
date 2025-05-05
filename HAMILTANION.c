#include<stdio.h>
#include<stdlib.h>
#define V 5
void printSolution(int path[]) ;
int isSafe(int v, int graph[V][V], int path[], int pos) {
	//edge checking between the vertex and the previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    int i;
    //duplicates checking
    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}

int hamCycleUtil(int graph[V][V], int path[], int pos) {
	//edge checking between the last vertex and the starting vertex
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    int v;
    for (v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1) == 1)
                return 1;
            /* If adding vertex v doesn't lead to a solution,
               then remove it */
            path[pos] = -1;
        }
    }
    /* If no vertex can be added to Hamiltonian Cycle constructed so far,then return 0 */
    return 0;
}
 
int hamCycle(int graph[V][V]) {
  int path[10];
    int i;
    for (i = 0; i < V; i++)
      path[i] = -1;
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == 0) {
        printf("\nSolution does not exist");
        return 0;
    }
    printSolution(path);
    return 1;
}

void printSolution(int path[]) {
    printf("Solution Exists:"
	 " Following is one Hamiltonian Cycle \n");
    int i;
    for (i = 0; i < V; i++)
        printf(" %d ", path[i]);
    printf(" %d ", path[0]);
    printf("\n");
}
main() {
	
	int G[V][V],i,j,k,n;
/*   printf("Enter no. of nodes:");
   scanf("%d",&n);
	printf("Enter the matirx:");*/
 	printf("\nEnter matrix (1:if edge exists ; 0:if edge doesnot exist) :\n");
 	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
     hamCycle(G);
    
}
