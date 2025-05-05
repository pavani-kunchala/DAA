#include <stdio.h>     
void heapify(int a[], int n, int i)  
{  
    int smallest = i; 
    int left = 2 * i + 1;   
    int right = 2 * i + 2;     
    if (left < n && a[left] < a[smallest])  
        smallest = left;    
    if (right < n && a[right] < a[smallest])  
        smallest = right;    
    if (smallest!= i) 
	 {  
        int temp = a[i];  
        a[i] = a[ smallest];  
        a[smallest] = temp;     
        heapify(a, n, smallest);  
    }  
    
}   
void heapSort(int a[], int n)  
{   
    int i;
    for (i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);    
    for (i = n - 1; i >= 0; i--)
	 {   
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;   
        heapify(a, i, 0);  
    }  
}    
int main()  
{  
int i,n ;
printf("Enter array size:");
scanf("%d",&n);
int a[n];
printf("Enter array elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]); 
heapSort(a, n);  
printf("Elements after sorting:\n");    
 for (i = 0; i < n; ++i)   
   printf("%d\t", a[i]);  
return 0;  	  
}   
