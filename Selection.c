#include<stdio.h>
main()
{ int n ,a[100],i,j,temp,min;
printf("enter array size:");
scanf("%d",&n); 
printf("enter array elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
{ 
min=i;
for(j=i+1;j<n;j++)
{
if(a[min]>a[j])
{
min=j;
}
}
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
printf("\narray elements after sorting:\n");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}  
