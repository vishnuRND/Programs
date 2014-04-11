// bitswa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void swap(int v1,int v2)
{
	int temp=v1;
	v1=v2;
	v2=temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int bin;
	printf("enter the binary number\n");
	scanf("%d",&bin);
	printf("%d",bin);
	int k=bin;
	while(k>0)
	{
		swap(k%100,k%10);
		k=k/100;

	}
	printf("%d",k);
	return 0;
}

