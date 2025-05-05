//Purpose:C Program to implement Quick sort 
#include<stdio.h>
int partition(int array[],int lb,int ub)
{  
int pivot=array[lb],start=lb,last=ub,temp;
while(start<=last)
{
	while(array[start]<=pivot )
	{
		start++;
	}//after completion of this loop gives start contains greater element than pivot
	while(array[last]>pivot)
	{
		last--;
	}//after completion of this loop gives last contains small element than pivot
	if(start<=last)
	{
		temp=array[start];
      array[start]=array[last];
      array[last]=temp;
	}	
}
//swaping pivot and last i.e setting the pivot in correct place
 temp=array[lb];
 array[lb]=array[last];
 array[last]=temp;
 return last;
}
int quicksort(int array[],int lb,int ub)
{   
if(lb<=ub)
{
	int pos=partition(array,lb,ub);
	quicksort(array,lb,pos-1);
	quicksort(array,pos+1,ub);
}
}
int main()
{
int i, n, a[25];
printf("Enter array size:");
scanf("%d",&n);
printf("\nEnter array elements:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quicksort(a,0,n-1);
printf("\nElements after sorting:\n ");
 for(i=0;i<n;i++)
printf(" %d",a[i]);
}
 
