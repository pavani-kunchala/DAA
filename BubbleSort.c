#include<stdio.h>
int main()
{
   int a[100],i,n,j,temp;
   printf("enter array size:");
   scanf("%d",&n);
    printf("enter array elements:");
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     for(i=0;i<n-1;i++)
     {
	     for(j=0;j<n-i-1;j++)
        {
          if(a[j]>a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
            }
        }
      }
      printf("Elements after sorting:\n");
      for(i=0;i<n;i++)
      printf("%d\t",a[i]);
}
