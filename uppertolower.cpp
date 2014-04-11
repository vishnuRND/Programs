// uppertolower.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
int res=0;
int convert(int num)
{
	if(num==0)
		return 0;
	convert(num/10);
	printf("%c",48+num%10);
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*char str[]="vIsHnU";
	int i=0;
	while(i<strlen(str))
	{
		if((int)str[i]>=65&&str[i]<=90)
		{
			str[i]=(int)str[i]-65+97;
		}
		else
		{
			str[i]=(int)str[i]-97+65;
		}
		i++;
	}
	printf("%s",str);*/
	int num;
	printf("enter the number\n");
	scanf("%d",&num);
	int res=convert(num);
	return 0;
}

