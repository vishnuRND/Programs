// rotatedsortedarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
//int exist=0;
int index(int arr[],int start,int end)
{
	int pivot=0;
	while(start<end)
	{
		if(arr[start]>arr[start+1])
		{
			pivot=start;
			//exist=1;
			return pivot;
		}
		start++;
	}
	return pivot;
}
int prevpivot=0;
inline int find(int arr[],int start,int end,int ele)
{
	if(start>end)
		return NULL;
	int pivot=index(arr,start,end);
	if(ele==arr[start])
		return (start);
	if(pivot==0)
		start++;
	else
		prevpivot=pivot;
	if(ele>=arr[start])
		find(arr,start,prevpivot-1,ele);
	else
		find(arr,prevpivot+1,end,ele);
	//return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={3,4,5,6,1,2};
	int ele;
	printf("enter element to search\n");
	scanf("%d",&ele);
	int pos=find(arr,0,(sizeof(arr)/sizeof(arr[0])-1),ele);
	if(pos!=-1)
	printf("%d",pos);
	else
		printf("element not found\n");
	return 0;
}

