// srstr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	char str[]="bcdfbcdebcdefdef";
	char *str1="bcdef";
	int count=0;
	int k=sizeof(str)/sizeof(str[0])-1;
	int visit=0,index=0,start=0;
	int j=0;
	for(int i=0;i<=k;i++)
	{
		if(str[i]==str1[j])
		{
			if(start==0)
			{
				index=i;
				start=1;
			}
			visit=1;
			j++;
			count++;
		}
		else if(visit==1)
		{
				i--;
				j=0;
				count=0;
				start=0;
				visit=0;
		}
		if(count==_mbstrlen(str1)+1||count==_mbstrlen(str1))
		{
				printf("found at %d\n",index);
				exit(0);
		}
	}
	return 0;
}

