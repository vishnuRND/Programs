// smallestseq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
int startseq=0;
int endseq=0;
int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,2,4,7,10,11,7,12,6,8,16,18,19};
    int start=0,end=12;
	int m=(start+end)/2;
	int k=m,j=m;
	while(k>0&&j<end)
	{
		if(a[k]<=a[m]&&a[j]>
			a[m])		
		{}
		else
		{
		   startseq=k;
		   endseq=j;
		}
		k=k-1;
		j=j+1;
	}
	printf("startseq:%d\n",startseq);
	printf("endseq:%d\n",endseq);
	return 0;
}

