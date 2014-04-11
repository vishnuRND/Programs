// base2tobase4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <math.h>
int num(int a[],int n)
{
	int number;
	if(n==0)
	{
		if(a[n]==0)
			number=0;
		else
		number=1;
	}
	else
	{
		number=a[n]*1+a[n-1]*2;
	}
	return number;

}
int base4(int a[],int n)
{
	int r=0,k=0,number=0;
	while(n>=0)
	{
		 r=num(a,n);
		 number+=r*(int)pow(10.00,k);
		k++;
		n-=2;
	}
	return number;

}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,0,1,0,1,1};
	//printf("enter th binary num\n");
	int res=base4(a,5);
	printf("%d",res);
	//scanf("%d",a);
	return 0;
}

