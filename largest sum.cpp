// largest sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int maxsum=0;
int sum=0;
int start=0;
int end=0;

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={2,-8,3,-2,4,-10};
	for(int i=0;i<6;i++)
	{
		sum=sum+arr[i];
		if(arr[i]>maxsum)
		{
			maxsum=arr[i];
		}
		
			else
			{
                sum=0;

			}

	}
	return 0;
}

