// charmatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int rows;
	int coms;
	char a[10][10];
	printf("enter number of rows\n");
	scanf("%d",&rows);
	printf("enter number of columns\n");
	scanf("%d",&coms);
	int mid=coms/2;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < coms; j++) 
		{
			if(j==mid-i)
			{
				for(int k=mid-i+1;k<=mid+i-1;k++)
					printf("\t");
			}
			else
				a[i][j]=j+'A';
		}
	}
	printf("the matrix is\n");
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<coms;j++)
		{
			printf("%c",a[i][j]);
			printf("\t");

		}
		printf("\n");
	}


	return 0;
}

