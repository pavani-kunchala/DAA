#include<stdio.h>
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w,j;
   int K[n+1][W+1];
   printf("\n");
   for (i = 0; i <= n; i++) //1st obj but wt[] starts from 0
   {
       for (w = 0; w <= W; w++)//i can be filled only if the capacity of the bag is w
       {
           if (i==0 || w==0)//no object is included /even the capacity of bag is 0
            {
            	K[i][w] = 0;
               printf("%d \t",K[i][w]);
				}    
           else if (wt[i-1] <= w) // wt of obj<=col w
               {
					  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],K[i-1][w]);
                 printf("%d \t",K[i][w]);
              }
           else //getting negative values
             {
					  K[i][w] = K[i-1][w];
                 printf("%d \t",K[i][w]);
             }
       }
       printf("\n");
   }
    i=n;j=W;	
 while(i>0&&j>=0)//no need to see 0th object	 
{
	if(K[i][j]==K[i-1][j])
	{
		printf("\nnot included object : %d\n",i);		 
	}
	else
	{
	 printf("\nincluded object : %d\n",i);
	  j=j-wt[i-1]; 	 
   }
    i--;
}
   return K[n][W];
}
main()
{
    int i, n, val[20], wt[20], W;
    
    printf("Enter number of items:");
    scanf("%d", &n);
    
    printf("Enter size of knapsack:");
    scanf("%d", &W);
    
    printf("Enter weight and value of items:\n");
    for(i = 0;i < n; ++i)
	 {
     scanf("%d%d", &wt[i], &val[i]);
    }
    
    printf("\nThe maximum profit = %d", knapSack(W, wt, val, n));
}
