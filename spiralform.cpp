// spiralform.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int a[10][10];
void spiral(int row,int column)
{

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(!(i==j||j==((column-1)-i)))
				printf("%d",a[i][j]);
			printf("\t");
		}
		printf("\n");
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	int row,column;
	printf("enter num of rows\n");
	scanf("%d",&row);
	printf("enter num of columns\n");
	scanf("%d",&column);
	if(row!=column)
	{
		printf("enter same row and column value\n");
		exit(0);
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
				printf("enter value\n");
				scanf("%d",&a[i][j]);
		}

	}
	printf("the matrix is\n");
		for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			
				printf("%d",a[i][j]);
				printf("\t");
		}
		printf("\n");
	}
	spiral(row,column);
	return 0;
}

