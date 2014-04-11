// 1dArrayToBox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void arrayToBox(int a[],int len)
{
	int undcnt=3*len+1;
	for(int i=0;i<=undcnt;i++)
		printf("_");
	printf("\n");
	for(int i=0;i<len;i++)
		printf("|_%d_",a[i]);
	printf("|\n");

}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[10]={1,1,2,0,5,2,5,3,11,10};
	arrayToBox(a,10);
	return 0;
}

