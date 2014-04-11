// transposeinplace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# define max 100
int a[max];
int top=-1;
int ele;
void push(int element)
{
	if(top==max-1)
		printf("stack is full\n");
	else
	{
		top++;
		a[top]=element;


	}

}
int pop()
{
	if(top==-1)
		printf("no more elements in stack\n");
	else
	{
		ele=a[top];
			top--;


	}
	return ele;

}
int _tmain(int argc, _TCHAR* argv[])
{
	int m,n,arr1[10][10];
	printf("enter the rows of the matrix\n");
	scanf("%d",&m);
	printf("enter the columns of the matrix\n");
	scanf("%d",&n);
	int data;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("enter data\n");
			scanf("%d",&arr1[i][j]);
			push(arr1[i][j]);
		}

	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d",arr1[i][j]);
			printf("\t");

		}
		printf("\n");

	}
	printf("the transpose of a matrix is\n");
    int k=m-1;
	while(k<0)
	{
	 for(int j=n-1;j<=0;j--)
	{
		if(k<0)
			break;
		int ele1=pop();
		arr1[k][j]=ele1;

	}
	 k--;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d",arr1[i][j]);
			printf("\t");

		}
		printf("\n");

	}
	return 0;
}

