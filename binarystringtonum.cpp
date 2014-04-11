// binarystringtonum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
int _tmain(int argc, _TCHAR* argv[])
{
	char s[10]="";
	printf("enter the binary string\n");
	scanf("%s",s);
	int size=strlen(s)-1;
	int a=1,n=0,num=0;
	while(size>=0)
	{
		num+=(s[size]-48)*(a<<n);	
		n++;
		size--;
		
	}
	printf("%d",num);
	return 0;
}

