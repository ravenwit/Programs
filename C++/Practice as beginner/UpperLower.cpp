#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int main()
{

char ch[100];
int i,l;
gets(ch);
l=strlen(ch);
for(i=0;i<l;i++)
{
if(ch[i]>=65&&ch[i]<=90){
ch[i]=ch[i]+32;
printf("%c",ch[i]);
continue;
}
if(ch[i]>=97&&ch[i]<=122)
{
ch[i]=ch[i]-32;printf("%c",ch[i]);
}
}
getch();
}
