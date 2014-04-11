// preswordgivword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
struct table
{
	int map;
	int isvisited;
	table()
	{
       map=0;
	   isvisited=0;
	}

}map1[30];
void printcontaining(char *list[],char *given)
{
    for(int i=0;i<strlen(list);i++)


}
void init(char *given)
{
	for(int i=0;i<strlen(given);i++)
	{
		int value=(int)given[i];
		if(map1[value%97].map==0)
			map1[value%97].map==1;
		else
			continue;

	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	char given[]="sun";
	char *list[]={"sunrise","nobel","utensil"};
	init(given);
	printcontaining(list,given);
	return 0;
}

