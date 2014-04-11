// product.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int prod=1;
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={1,2,3,4,5};
	int size=(sizeof(arr)/sizeof(arr[0]));
	for(int i=0;i<size;i++)
		prod*=arr[i];
	for(int i=0;i<size;i++)
	{
		printf("%d\n",(prod/arr[i]));

	}
	return 0;
}

