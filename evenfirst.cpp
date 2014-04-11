// evenfirst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={1,2,3,4,5,6,7,9};
	int length=sizeof(arr)/sizeof(arr[0])-1;
	/*for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if((arr[j]%2==0&&arr[j+1]%2==0)||(arr[j]%2!=0&&arr[j+1]%2!=0)||(arr[j]%2==0&&arr[j+1]%2!=0))
					continue;
			else
			{
				int data=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=data;
			}
			
		}

	}*/
	for(int k=0;k<=length;k++)
		printf("%d\n",arr[k]);
	int i=0,j=length;
	while(i<=j)
	{
		if(arr[i]%2==0)
			i++;
		else
		{
			if(arr[j]%2==0)
			{
				int data=arr[i];
				arr[i]=arr[j];
				arr[j]=data;
			}
			j--;
		}
	}
	printf("-----------------------------------\n");
	for(int k=0;k<=length;k++)
		printf("%d\n",arr[k]);
	return 0;
}

