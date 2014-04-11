// timesrotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={5,6,1,2,3,4};
	int i=0;
	while(i<=(sizeof(arr)/sizeof(arr[0])))
	{
		if(arr[i]>arr[i+1])
		{
			printf("%d",((sizeof(arr)/sizeof(arr[0]))-(i+1)));
			exit(0);
		}
		i++;
	}
	return 0;
}

