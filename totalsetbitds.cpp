// totalsetbitds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	int count=0;
	printf("enter the number\n");
	scanf("%d",&num);
	printf("the number of set numbers in the given num is\n");
	while(num>0)
	{
		if(num%2==1)
			count++;
		num=num/2;
	}
	printf("%d\n",count);
	return 0;
}

