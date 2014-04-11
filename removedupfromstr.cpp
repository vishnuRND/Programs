// removedupfromstr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
struct hash
{
	char ch;
	bool isvisited;
	hash()
	{
       isvisited=0;
	}

}table[100];

void remdup(char str1[],char str2[])
{
	for(int i=0;i<strlen(str2);i++)
	{
		int value=(int)str2[i];
		table[value%97].ch=str2[i];
		if(table[value%97].isvisited==0)
			table[value%97].isvisited=1;
		else
			continue;
	}

	for(int i=0;i<strlen(str1);i++)
	{
		int value=(int)str1[i];
		if(!table[value%97].isvisited)
			continue;
		else
		        str1[i]=' ';

	}
	for(int i=0;i<strlen(str1);i++)
	{
		if(str1[i]!=' ')
		printf("%c",str1[i]);
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[]="heelu";
	char str2[]="vishnu";
	remdup(str1,str2);
	return 0;
}

