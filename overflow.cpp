// overflow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int a,int b;
	printf("enter the value of a &b\n");
	scanf("%d %d",&a,&b);
	if(a>INT_MAX-b)
	return 0;
}

