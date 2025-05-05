#include<stdio.h>
void queen(int row,int n); 
int board[20],count; 
//function for printing the solution
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count); 
 
 for(i=1;i<=n;++i)
  printf("\t%d",i); 
  
 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  
  for(j=1;j<=n;++j)  
  {
   if(board[i]==j)
    printf("\tQ");  
   else
    printf("\t-");  
   } 
 }
} 
/*funtion to check conflicts If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i) 
 {
 //checking column and diagonal conflicts
  if(board[i]==column)//board[i] stores placed queen position
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0; 
 } 
 return 1; 
} 
//function to check for proper positioning of queen
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column) 
 {
  if(place(row,column))  
  {
   board[row]=column;  
   
   if(row==n)  
    print(n);  
   else  
    queen(row+1,n);  
  }
 }
}    
int main()
{
 int n,i,j;
 printf(" - N Queens Problem Using Backtracking -");
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 queen(1,n);
 return 0;
} 
