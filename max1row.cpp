// max1row.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int rowmax;
int maxcount=0;
void maxrow(int (*max)[5])
{
	for(int i=0;i<3;i++)
	{
		int count=0;
		for(int j=0;j<5;j++)
		{
             if(max[i][j]==1)
				 count++;
			 else
				 continue;

		}
		if(maxcount<count)
		{
			maxcount=count;
			rowmax=i;
		}
	}
    printf("%d\n%d\n",rowmax,maxcount);

}
int _tmain(int argc, _TCHAR* argv[])
{
	int max[3][5]={{0,0,1,0,1},{1,0,1,1,0},{1,1,1,1,0}};
	maxrow(max);
	return 0;
}

