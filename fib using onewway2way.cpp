// fib using onewway2way.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int fib(int a,int b,int n)
{
	int c =a+b;
	if(c==n)
	{
		printf("%d\n",c);
		return NULL;
	}
	printf("%d\n",c);
	fib(b,c,n);
}
int fib(int *n)
{
	static int i=0;
	if(i!=0)
		return NULL;
	if(*n<0)
		return NULL;
	if(*n==0)
		return 0;
	if(*n==1)
		return 1;
	int k=*n-1;
	int l=*n-2;
	int c=fib(&k)+fib(&l);
	printf("%d",c);
	i=1;
	 
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	printf("enter the max limit u want to get\n");
	scanf("%d",&n);
	int a=0;
	int b=1;
	printf("%d\n%d\n",a,b);
	fib(a,b,n);
	fib(&n);
	return 0;
}

