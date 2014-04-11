// rotatethearray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int  reverse(int arr[],int start,int end)
{
	if(start>end)
		return NULL;
	int temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
	reverse(arr,start+1,end-1);
}
int hold=0;
int getindex(int arr[],int i,int iterator,int end,int left,int right)
{

	if(iterator==end)
		return NULL;
	if(iterator==i)
	{
		getindex(arr,i,iterator+1,end,left,right);
	}
	if(iterator<i)
	{
		getindex(arr,i,iterator+1,end,left+arr[i],right);
	}
	else if(iterator>i)
	{

		getindex(arr,i,iterator+1,end,left,right+arr[i]);
	}
	if(left==right)
		hold=1;
	return hold;	
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={-7, 1, 5, 2, -4, 3, 0};
	int rotatenum;
	printf("enter the number of times t be rotated\n");
	scanf("%d",&rotatenum);
	for(int i=0;i<rotatenum;i++)
	{
		int temp=arr[0];
		int j;
		for(j=1;j<=sizeof(arr)/sizeof(arr[0])-1;j++)
			arr[j-1]=arr[j];
		arr[j-1]=temp;
	}
	printf("reversal of a array\n");
	reverse(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	int iterator=0,leftsum=0,rightsum=0;
	for(int i=0;i<=sizeof(arr)/sizeof(arr[0])-1;i++)
	{
		if(getindex(arr,i,iterator,sizeof(arr)/sizeof(arr[0])-1,leftsum,rightsum))
		{
			printf("the first eqilibrium index is %d\n",i);
			exit(0);
		}
	}
	return 0;
}

