#include<stdio.h>
#include<string.h>
void string_matching(int,int);
int isPalindrome(char);
int n;
main()
{  
   int i;
	char str[10];
	printf("Enter the string:");
	scanf("%s",&str);
	printf("enter size of the string:");
	scanf("%d",&n);
	int shift=0;
	for(i=0;i<n;i++)
	{
		if(isPalindrome(str))
		
		 printf("given string itself is palindrome");
		
		else{
			if(compare(str[shift],str[i]))
			string_matching(i,shift);
			else
			string_matching(i+1,shift+1);		
			}
	}
}
	int isPalindrome(char str[10])
	{ int i;
	  char str1[10];
       if(compare(str,reverse(str)))
	        { 
	      	 return 1;	         
			  }
			return 0; 
	      	
	}
	
	int string_matching(int i,int shift)
	{  int i,cuts;
		for(i=0;i<n;i++)
		cuts=cuts+1;
		string_matching(i+1,shift+1);
	}
