// anagrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct hash
{

	char v;
	int isvisited;
	int count;
	hash()
	{

		isvisited=0;
		count=0;

	}

}hash[100];

int _tmain(int argc, _TCHAR* argv[])
{
	char *str="vvishnu";
	char *str1="vvishnu";
	while(*str!='\0')
	{
       int value=(int)*str;
	   hash[value%97].v=*str;
	   if(hash[value%97].v==1)
		   hash[value%97].count++;
	   else
		   hash[value%97].count=1;
	}
	while(*str1!='\0')
	{
       int value=(int)*str1;
	    if(hash[value%97].isvisited==1)
			 hash[value%97].count--;
		else
		{
			printf("these are not anagrams\n");
			exit(0);
		}


	}
	for(int i=0;i<27;i++)
	{

		if(hash[i].count==0)


	}
	return 0;
}

