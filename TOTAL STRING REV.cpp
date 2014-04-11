// TOTAL STRING REV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
void rev(char str[],int start,int end)
{
	int i=start;
	int j=end;
	while(i<=j)
	{
		char data=str[i];
		str[i]=str[j];
		str[j]=data;
		i++;
		j--;
	}

}
void print(char str[],int end)
{
	for(int i=0;i<end;i++)
		printf("%c",str[i]);
 printf("\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	char str[]="hello uma and sreenivasulu";
	print(str,26);
	rev(str,0,25);
	int start=0,i=0,end=0;
	while(str[i]!='\0')
	{
		if(str[i]==' ')
		{	
			rev(str,start,end-1);
			start=i+1;
		}
		end++;
		i++;

	}
	rev(str,start,end-1);
	printf("reverse of the complete string is\n");
	print(str,26);
	return 0;
}

