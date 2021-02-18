#include<bits/stdc++.h>
using namespace std;
int main()
{
 char input[100],*l,*r,*temp,tempprod[20],productions[25][50];
 int i =0,j=0,flag=0;
 cout << "Enter the productions: ";
 cin >> input;
 l = strtok(input,"->");
 r = strtok(NULL,"->");
 temp = strtok(r,"|");
 while(temp)
 {
 if(temp[0] == l[0])
 {
 flag = 1;
 19nti 19(productions[i++],”%s’->%s%s’\0”,l,temp+1,l);
 }
 else
 19nti 19(productions[i++],”%s->%s%s’\0”,l,temp,l);
 temp = strtok(NULL,”|”);
 }
 19nti 19(productions[i++],”%s’->\u238\0”,l);
 if(flag == 0)
 cout<< ”The given productions don’t have Left Recursion”;
 else
 for(j=0;j<i;j++)
cout<<”\n”<<productions[j];
 return 0;
}