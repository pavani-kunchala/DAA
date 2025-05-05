#include<stdio.h>
void mergesort(int low,int high,float ratio[],float weight[],float profit[] );
void merge(int low,int mid,int high,float ratio[],float weight[],float profit[]);
void knapsack(int n,float weight[],float profit[],float capacity)
{  int i;
	float x[20],usedwt=0,tp=0 ;
	for(i=0;i<n;i++)
	 x[i]=0.0;
 for(i=0;i<n;i++)
 { 
 if(weight[i]+usedwt > capacity)
 {
 	x[i]=(capacity-usedwt)/weight[i];
 	usedwt=capacity;
   break;
 }
 else
 {
 	x[i]=1.0;
 	usedwt=usedwt+weight[i];
 }
}
printf("\nthe x[i] values :\n");
  for(i=0;i<n;i++)
  printf("%f  ",x[i]);
  for(i=0;i<n;i++)
  tp=tp+(x[i]*profit[i]);
 printf("\nMaximum profit :%f",tp);
}
main()
{
	float weight[20],profit[20],capacity;
	int num ,i,j;
	float ratio[20],temp;
	printf("enter the capacity of the knapsack:");
   scanf("%f",&capacity);
	printf("enter the no. of objects:");
	scanf("%d",&num);
	printf("enter the weights and profits of the each objects:\n");
	for(i=0;i<num;i++)
	{scanf("%f%f",&weight[i],&profit[i]);
	}
  for(i=0;i<num;i++)
  ratio[i]=profit[i]/weight[i];
  
  mergesort(0,num-1,ratio,weight,profit);
  
   for(i=0;i<num;i++)
  {
  	printf("%f  ",ratio[i]);
  }
  printf("\n");
  knapsack(num,weight,profit,capacity);
}
void mergesort(int low,int high,float a[],float weight[],float profit[])
{
 int mid;
 if(low!=high)
 {
 mid=((low+high)/2);
 mergesort(low,mid,a,weight,profit);
 mergesort(mid+1,high,a,weight,profit);
 merge(low,mid,high,a,weight,profit);
 }
}
void merge(int low,int mid,int high,float a[],float weight[],float profit[])
{
 int n,i,j,k;
 float temp[30],temp2[30],temp3[30];
 i=low;
 j=mid+1;
 k=low;
 while((i<=mid) && (j<=high))
 {
 if(a[i]>=a[j])
 {
 temp[k]=a[i];
 temp2[k]=profit[i];
 temp3[k]=weight[i];
 k++;i++;
 }
 else
 {
 temp[k]=a[j];
 temp2[k]=profit[j];
 temp3[k]=weight[j];
 k++;j++;
 }
}
 while(i<=mid)
 {
    temp[k]=a[i];
    temp2[k]=profit[i];
    temp3[k]=weight[i];
    k++;i++;
 }
 while(j<=high)
 {
 temp[k]=a[j];  
 temp2[k]=profit[j];
 temp3[k]=weight[j];
 k++;j++;
 }
 for(i=low;i<=high;i++)
 {
 a[i]=temp[i];
 profit[i]=temp2[i];
 weight[i]=temp3[i];
 }
}

