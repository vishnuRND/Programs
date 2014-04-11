// check.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	printf("enter the charecter\n");
	//fflush(stdin);
	scanf("%c",&ch);
	if((int)ch>=97&&(int)ch<=122)
		printf("its a lower case\n");
	else if((int)ch>=65&&(int)ch<=90)
		printf("its a upper case\n");
	return 0;
}

