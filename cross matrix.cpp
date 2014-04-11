// cross matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int a[10][10];
int hold[100];
int checkdiagonal(int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				if(a[i][j]!=a[i][(n-1)-j])
					return 0;
				
			}
		}
	}
	return 1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int m,n;
	printf("enter num of rows\n");
	scanf("%d",&m);
	printf("enter num of columns\n");
	scanf("%d",&n);
	hold[m*n]=0;
	printf("enter values in %d range\n",m*n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("enter data\n");
			scanf("%d",&a[i][j]);
		}
	}
	if(checkdiagonal(m,n))
	{

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(hold[a[i][j]]==0||(hold[a[i][j]]==1&&hold[a[i][j]]==hold[a[i][(n-1)-j]]))
						hold[a[i][j]]=1;
				else
				{
					printf("not a cross matrix\n");
				}

			}
		}
	}
	else
	{
		printf("not a cross matrix\n");
	}
	return 0;
}

