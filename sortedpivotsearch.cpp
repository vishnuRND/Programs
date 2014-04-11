// sortedpivotsearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int getindex(int arr[],int start,int end)
{
	for(int i=start;i<=end;i++)
	{
		if(arr[i]>arr[i+1])
			return i;
	}
}
int search(int arr[],int start,int end,int ele)
{
	if(start>=end)
		return NULL;
	if(ele==arr[start])
		return start;
	int pivot=getindex(arr,start,end);
	if(ele<arr[start])
		search(arr,pivot+1,end,ele);
	else
		search(arr,start,pivot,ele);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={3,4,5,1,2};
	int data;
	int length=sizeof(arr)/sizeof(arr[0])-1;
	printf("enter the element you want to find out\n");
	scanf("%d",&data);
	int pos=search(arr,0,length,data);
	printf("the pos is %d\n",pos);
	return 0;

}

