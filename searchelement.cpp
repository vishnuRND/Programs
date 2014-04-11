// searchelement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int a[10][10];

int _tmain(int argc, _TCHAR* argv[])
{
	int row,column;
	printf("enter the row\n");
	scanf("%d",&row);
	printf("entre the column\n");
	scanf("%d",&column);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			printf("enter data\n");
			scanf("%d",&a[i][j]);

		}
	}
	printf("the elements are\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			printf("%d",a[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	int num;
	printf("enter the num you want to search\n");
	scanf("%d",&num);
	int j=3,i=0;
	while(i<row)
	{
		if(a[i][j]==num)
			printf("element found");
		if(a[i][j]<num)
			j++;
		if(a[i][j]>num)
		{
			while(j>=0)
			{
				if(a[i][j]==num)
					printf("element found\n");
				j--;
			}

		}

	}
	printf("element not found\n");
	return 0;
}

