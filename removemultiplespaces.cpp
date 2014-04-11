// removemultiplespaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
int removedup(char str[],int size,int max)
{
	int j=max,i=size;
	while(i>=0)
	{
		if(str[i]!=' ')
		{
			str[j]=str[i];
			i--;
			j--;
		}
		else
			i--;
	}
	return j;
}
int removechar(char str[],int hold,int max,int start,int end)
{
	int j=hold;
	int i=max;
	while(j>=0)
	{
		if(j==end&&end>=start)
		{
			j--;
			end--;
		}
		else
		{
			str[i]=str[j];
			i--;
			j--;
		}

	}
	return i;

}
char *toupper(char str[],int size)
{
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]!=' ')
			str[i]=str[i]-'a'+'A';
		i++;
	}
	return str;

}
int _tmain(int argc, _TCHAR* argv[])
{
	char str[25];
	printf("enter the string\n");
	gets(str);
	int size=strlen(str);
	int start=removedup(str,size-1,24);
	printf("the string is\n");
	for(int i=start+1;i<25;i++)
		printf("%c",str[i]);
	printf("\n"); 
	int start1=removechar(str,size-1,24,2,3);
	for(int i=start1+1;i<25;i++)
		printf("%c",str[i]);
	toupper(str,size);
	return 0;
}

