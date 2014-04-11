// totalsetbits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#define max 10
int process[max];
int start;
int end;
void tobinary(int num)
{ int j=max-1;
  while(num>0)
  {
	process[j]=num%2;
	j--;
	num=num/2;
  }
  start=j+1;
}
void swap(int end)
{
	int i=start;
	if(((end-1)-start+1)%2==0)
	{
	while(i<end-1)
	{
		int data=process[i];
		process[i]=process[i+1];
		process[i+1]=data;
		i+=2;
	}
	}
	else
	{
		while(i<end-2)
		{
			int data=process[i];
		process[i]=process[i+1];
		process[i+1]=data;
		i+=2;
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	printf("enter the number\n");
	scanf("%d",&num);
	tobinary(num);
	printf("the binary number is\n");
	for(int i=start;i<max;i++)
		printf("%d",process[i]);
	swap(10);
	printf("after swapping\n");
	for(int i=start;i<max;i++)
		printf("%d",process[i]);
	return 0;
}

