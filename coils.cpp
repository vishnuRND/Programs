// coils.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int a[10][10];

int _tmain(int argc, _TCHAR* argv[])
{
	int n,count=1;
	printf("before you start the coils are formed in the marix which is a square matrix and is a order of multiples of 4\n");
	printf("enter the value of n\n");
	scanf("%d",&n);
	int k=1;
	for(int i=0;i<(4*n);i++)
	{
		for(int j=0;j<(4*n);j++)
		{
			a[i][j]=k++;

		}

	}
	printf("the matrix is\n");
	for(int i=0;i<(4*n);i++)
	{
		for(int j=0;j<(4*n);j++)
		{
			printf("%d",a[i][j]);
			printf("\t");

		}
		printf("\n");

	}
	int var=3;
	int base1=(4*n)/2;
	int base2=(4*n)/2-1;
	int i1=base1;
	int j=base2;
	int nextrow,nextcolumn;
	printf("coil 1 is given below\n");
	while(var<=(4*n))
	{
		int base=0;
		if(i1>j&&base==0)
		{
			nextrow=i1-(var-1);
			nextcolumn=j+(var-1);
			int hold=i1;
			int hold1=j+1;
			while(hold>=nextrow)
			{
				printf("%d",a[hold][j]);
				hold--;
			}
			while(hold1<=nextcolumn)
			{
				printf("%d",a[hold+1][hold1]);
				hold1++;
			}
			base=1;
			i1=nextrow;
			j=nextcolumn;

		}
		if(i1<j&&base==0)
		{

			nextrow=i1+(var-1);
			nextcolumn=j-(var-1);
			int hold=i1;
			int hold1=j;
			while(hold<=nextrow)
			{
				printf("%d",a[hold][j]);
				hold++;
			}
			while(hold1>=nextcolumn)
			{
				printf("%d",a[hold-1][hold1]);
				hold1--;
			}
			
			base=1;
			i1=nextrow;
			j=nextcolumn;


		}
		if(var==(4*n)-1)
		{
			if(i1==7)
			{
				i1--;
				while(i1>=0)
				{
					printf("%d",a[i1][j]);
					i1--;
				}
			}
			if(j==7)
			{
				i1++;
				while(i1<(4*n))
				{
					printf("%d",a[i1][j]);
					i1++;
				}

			}
			printf("\n");
			if(count<2)
			{
				printf("coil 2 is given below");
				i1=base2;
				j=base1;
				var=1;
				printf("\n\n");
				count++;
			}
		}
		var+=2;
	}

	return 0;
}

