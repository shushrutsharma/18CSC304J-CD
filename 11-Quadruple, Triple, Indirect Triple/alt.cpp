#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
using namespace std;
void forswitch(char,int);
void conv(int);
char arg[10][10],op[5][2],ch[10],go[3][3],c[10];
void main()
{
int i=-1,m=0,k=10;
cout<<"\t\t\tTHREE ADDRESS CODE";
goto(15,7);
cout<<"OPERATOR";
goto(30,7);
cout<<"ARGUMENT-1";
goto(45,7);
cout<<"ARGUMENT-2";
goto(60,7);
cout<<"GOTO";
goto(15,8);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~";
do
{
i++;
goto(2,k);
printf("[%d]",i);
goto(18,k);
scanf("%s",&op[i]);
forswitch(op[i][0],i);
goto(33,k);
scanf("%s",&arg[m+i]);
goto(48,k);
scanf("%s",&arg[m+1+i]);
goto(61,k);
scanf("%s",&go[i]);
conv(m+i);
conv(m+1+i);
k++;
m++;
}while(i!=3);
printf("ASSEMBLY LANGUAGE CODE");
printf("\n\n100\tMOV %s,RO",arg[0]);
printf("\n101\tMOV %s,R1",arg[1]);
printf("\n102\tCMP R0,R1");
printf("\n103\t%s 107",ch);
printf("\n104\tMOV%s,R2",arg[3]);
printf("\n105\tMOV R2,%s",arg[2]);
printf("\n106\tJUMP 109");
printf("\n107\tMOV %s,R2",arg[5]);
printf("\n109\tend");
}
void conv(int x)
{
if(isdigit(arg[x][0]))
{
strcpy(c,"#");
strcat(c,arg[x]);
strcpy(arg[x],c);
}
}
void forswitch(char sh,int t)
{
if(t<1)
switch(sh)
{
case '<':
strcpy(ch,"JC");
break;
case '>':
strcpy(ch,"JNC");
break;
case '=':
strcpy(ch,"JZ");
break;
case '-':
break;
default:
goto(8,40);
cout<<"\n\t\tINVALID ENTRY";
exit(0);
break;
}
}