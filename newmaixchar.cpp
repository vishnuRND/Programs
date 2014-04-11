// charmatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	int k,i=0,n,j=0;
	printf("enter the length of the figure\n");
	scanf("%d",&n);
	int mid=n/2;
	int visited=0;
	for(int i=0;i<n;i++)
	{
		int k=mid-i,j,l,m;
		for(j=0;j<=k;j++)
			printf("%c\t",'A'+j);
		for(l=mid-i+1;l<=mid+i-1;l++)
		{
			visited=1;
			printf("\t");
		}
		for(m=l;l<n;l++)
		{
			if(visited==1)
			printf("%c\t",('A'+j)-(l-j));
			else
			printf("%c\t",('A'+j-1)-(l-(j-1)));	

		}
		visited=0;
		printf("\n");
	}
}

