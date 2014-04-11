// compress.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	
	char string1[]="abcd";
	int k=strlen(string1);
	int *a=(int *)malloc(k*sizeof(int));
	int start=0,i=0,j=0,count=1;
	while(string1[i+1]!='\0')
	{
		if(string1[i]==string1[i+1])
		{
			count++;
			if(start==0)
			{
				a[j]=string1[i];
				a[++j]=count;
				start=1;
			}
			else
				a[j]=count;
		}
		else
		{
			j=j++;
			count=1;
			a[j]=string1[i+1];
			a[++j]=count;
		}
		i++;
	}
	for(int start=0;start<=j;start++)
	{
		if(a[start]>=97)
			printf("%c",a[start]);
		else
			printf("%d",a[start]);
	}
	return 0;
}

