// tuples.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int tuples(int arr[],int start,int end,int data)
{
	if(start>end)
		return NULL;
	int mid=(end-start)/2;
	if(data==arr[start]+arr[end])
		printf("%d,%d\n",start,end);
	if(data>arr[mid+start-1]+arr[mid+start])
		tuples(arr,mid+start,end,data);
	else if(data<arr[mid+start]+arr[mid+start+1])
		tuples(arr,start,mid+start,data);
	return NULL;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int sum;
	int arr[]={1,2,3,4,5,6};
	printf("enter the sum value\n");
	scanf("%d",&sum);
	if(sum<arr[0])
	{
		printf("no tuples are in the list\n");
		exit(0);
	}
	tuples(arr,0,5,sum);
	return 0;
}

