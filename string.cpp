// string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
int nextpos=0;
char *hold[10];
int search(char source[],char hold[])
{
	int i=0;
	int j=0;
	int got=0;
	while(source[i]!='.')
	{
		if(source[i]==hold[j])
		{
			while(j<strlen(hold))
			{
				if(source[i]!=hold[j])
					return 0;
				i++;
				j++;
			}
			return 1;
		
		}

		i++;
	}
	nextpos=i-1;
}
int hold1(char source[],char hold[])
{



}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	char source[100000];
	char hold[10];
	printf("enter the number of words\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",hold[i]);	
	}
	int j=0;
	while(j<strlen(source))
	{
		for(int i=0;i<n;i++)
		{
			if(!search(source,hold))
					break;
		}
	}
	return 0;
}

