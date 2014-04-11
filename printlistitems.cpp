// printlistitems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
int count=0;
struct table
{
	char ch;
	int isvisited;
	int reference;
	table()
	{
       isvisited=0;
	   reference=0;
	}

}map[30];

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[]="sun";
	char str2[]="sunday";
	for(int i=0;i<strlen(str1);i++)
	{
		int value=(int)str1[i];
		if(map[value%97].isvisited==0)
		{
			map[value%97].ch=str1[i];
			map[value%97].isvisited=1;

		}

	}
	for(int i=0;i<strlen(str2);i++)
	{
		int value=(int)str2[i];
		if(map[value%97].isvisited==1&&map[value%97].reference==0)
		{
			count++;
			map[value%97].reference=1;
		}

	}
	if(count==strlen(str1))
		printf("%s contains all the charecters of %s\n",str2,str1);
	else
		printf("sorry\n");
	return 0;
}

