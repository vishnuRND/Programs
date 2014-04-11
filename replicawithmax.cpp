// replicawithmax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
int max=0;
void replica(int arr[],int length)
{
	for(int i=length-1;i>=0;i--)
	{
		if(i==length-1)
		{
			max=arr[i];
			arr[i]=-1;
		}
			
		else
		{
			int temp=arr[i];
			arr[i]=max;
			if(max<temp)
			{
                max=temp;
				

			}
		}
		
	}

	for(int i=0;i<=length-1;i++)
		printf("%d\n",arr[i]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={16,17,4,3,5,2};
	replica(arr,6);
	return 0;
}

