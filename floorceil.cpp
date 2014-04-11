// floorceil.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int  floor(int arr[],int data,int start,int end)
{
	if(start>end)
		return NULL;
	int mid=(end-start)/2+start;
	int i=mid-1;
	int j=mid+1;
	if(data==arr[mid])
	{
		while(arr[i]==arr[mid])
				i--;
		while(arr[j]==arr[mid])
			j++;
		printf("the floor of %d is %d and ceil is %d\n",data,arr[i],arr[j]);
	}
	if(data<arr[mid])
	{
		floor(arr,data,start,mid);

	}
	else if(data>arr[mid])
	{
		floor(arr,data,mid+1,end);
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={1,2,3,6,7,7,8,9,11,12};
	int data;
	int j=(sizeof(arr)/sizeof(arr[0]))-1;
	printf("enter the date\n");
	scanf("%d",&data);
	if(data<arr[0])
	{
		printf("floor of %d is %d and ceil is %d\n",data,arr[0],arr[0]);
	}
	if(data>=arr[j])
	{
		printf("the floor of %d is %d\n",data,arr[j]);
		printf("the ceil of %d doesnt exists\n",data);
	}
	else
		floor(arr,data,0,j);
	return 0;
}

