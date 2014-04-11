// maxprod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int maxprod=0;
int prod=1;
void max(int arr[],int len)
{
	for(int i=0;i<len-1;i++)
	{
		prod=prod*arr[i];
		if(maxprod<prod)
			maxprod=prod;
		else
		   continue;
	}
  printf("%d",maxprod);
   
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={-2,-3,0,-2,-40};
	max(arr,5);
	return 0;
}

