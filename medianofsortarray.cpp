// medianofsortarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int med1;
int count=0;
int res[100];
int *merge(int *a,int *b,int n1,int n2)
{
	
	int i=0,j=0,k=0;
	while(i<n1&&j<n2)
	{
		if(a[i]>b[j])
		{
			res[k]=b[j];
			j++;
			k++;

		}
		if(a[i]<b[j])
		{
           res[k]=a[i];
		   i++;
		   k++;

		}
	}
	while(i<n1)
	{
		res[k]=a[i];
		i++;
		k++;

	}
	while(j<n2)
	{

		res[k]=b[j];
		j++;
		k++;

	}
	return res;
	}
int sortboth(int *a,int mid,int *b,int n1,int n2)
{
	for(int i=0;i<n2;i++)
	{
		int present=0;
		if(a[i]<a[mid])
		{
			int k=mid-1;
			while(k>=0)
			{
				if(a[k]==a[i])
					present=1;
				k--;
			}
			if(present==0)
				count++;


		}
		else if(a[i]>a[mid])
		{
			int k=mid;
			while(k<=n1)
			{
				if(a[k]==a[i])
					present=1;
				k++;
			}
			if(present==0)
				count++;

		}
		else if(a[i]==a[mid])
			continue;

	}
	return res[n1+count-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int med1;
	int n1, n2;
	int a[10],b[10];
	printf("enter the size of first sorted array\n");
	scanf("%d",&n1);
	printf("enter the size of second sorterd array\n");
	scanf("%d",&n2);
	printf("enter data of 1st array\n");
	for(int i=0;i<n1;i++)
		scanf("%d",&a[i]);
	printf("enter data of 2nd array\n");
	for(int i=0;i<n2;i++)
		scanf("%d",&b[i]);
	printf("\n\n first array\n---------------\n");
	for(int i=0;i<n1;i++)
	{
		printf("%d",a[i]);
		printf("\t");
	}
	printf("\n\n second array\n---------------\n");
	for(int i=0;i<n2;i++)
	{
		printf("%d",b[i]);
		printf("\t");
	}
	printf("\n");

	med1=n1/2;
	int *result=merge(a,b,n1,n2);
	int median=sortboth(a,med1,b,n1,n2);
	printf("median of both arrays is %d\n\n",median);
	return 0;
}

