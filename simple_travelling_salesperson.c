#include<stdio.h>
int ary[10][10],completed[10],n,cost=0;
void takingInput()
{
int i,j;
printf("Enter the number of villages: ");
scanf("%d",&n);

printf("\nEnter the Cost Matrix\n");
for(i=0;i < n;i++)
{
printf("\nEnter Elements of Row: %d\n",i+1);
for( j=0;j < n;j++)
scanf("%d",&ary[i][j]);
completed[i]=0;
}
printf("\n\nThe cost list is:");
for( i=0;i < n;i++)
{
printf("\n");
for(j=0;j < n;j++)
printf("\t%d",ary[i][j]);
}
}

void mincost(int city)
{
int i,nextcity;
completed[city]=1;
printf("%d--->",city+1);
nextcity=least(city);
if(nextcity==999)
{
nextcity=0;
printf("%d",nextcity+1);
cost+=ary[city][nextcity];
return;
}
mincost(nextcity);
}

int least(int c)
{
int i,nc=999;
int min=999,kmin;
for(i=0;i < n;i++)
{ //adjacent and unvisited
if((ary[c][i]!=0)&&(completed[i]==0))
//min from that
if(ary[c][i]< min)
{
min=ary[i][0]+ary[c][i];
kmin=ary[c][i];
nc=i;
}
}
if(min!=999)
cost+=kmin;
return nc;
}

main()
{   
   int start;
	takingInput();
	printf("\nenter start node:\n");
	scanf("%d",&start);
	printf("\nThe path is:\n");
	mincost(start);
	printf("\nminimum cost is %d\n",cost);
}
