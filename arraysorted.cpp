// arraysorted.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int max,min;
int start=0;
int end=0;
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int j=sizeof(arr)/sizeof(arr[0])-1;
	max=arr[0];
	min=arr[j];
	int i=0;
	while(i<j)
	{
		if(arr[i]<max)
			end=i;
		else
			max=arr[i];
	i++;
	}
	int k=j;
	while(k>=0)
	{
		if(arr[k]<=min)
			min=arr[k];
		else
			start=k;
		k--;
	}
	printf("the sorting must start from %d to %d\n",start,end);
	return 0;
}

