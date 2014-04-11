// base4tobase2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
char str[100];
int direct=0;
int build(int n)
{
	static int i=0;
	if(n==0)
	{
		str[i]=char(48+0);
		i++;
		return 0;
	}
	if(n==1)
	{
		if(direct==1)
		{
			str[i++]='0';
			str[i++]='1';
		}
		else
			str[i++]='1';
		return 0;
	}
	build(n/2);
	str[i]=char(48+n%2);
	i++;
	//direct=0;
}
int convert(int n)
{
	if(n==0)
		return 0;
	convert(n/10);
	direct=0;
	if(n%10==1)
		direct=1;
	build(n%10);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	printf("enter the value of n\n");
	scanf("%d",&n);
	convert(n);
	printf("%s",str);
	return 0;
}

