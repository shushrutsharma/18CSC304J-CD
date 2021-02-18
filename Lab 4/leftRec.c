#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int n=1,i=0,j=0,k=0;
char a[10][10],f[10];
 int main(){
   int i=0,z;
   char c,ch;
   
     printf("Enter the production:\n");
     for(i=0;i<n;i++)
        scanf("%s%c",a[i],&ch);
    
     c=a[0][0];
     if(a[0][2] == c)
     { 
       printf("Left recursion found: \n");
       printf("%c' -> ",c);
       for(k=3;k<strlen(a[0]) && a[0][k] != '|';k++)
       { 
	     printf("%c",a[0][k]);
	   } 
	   printf("%c' | e",c);
	   n=k; i=0;
	   printf("\n%c ->",c);
	   for(k=n+1; k<strlen(a[0]) && a[0][k]!='\0'; k++)
	   {
	   	printf("%c",a[0][k]);
	   }
	   printf("%c'",c);
     }
     else{
     	printf("No left recursion!!");
	 } 
      return 0;
   }