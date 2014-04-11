// patternmatching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char source[100]="";
	char word[100]="";
	char hold[10]="";
	printf("enter the source string\n");
	gets(source);
	int n;
	printf("enter how many words you want to search\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter word\n");
		scanf("%s",hold);
		strcat(word,hold);
		if(i!=n-1)
		strcat(word," ");
	}
	//printf("enter the word you want to search\n");
	//scanf("%s",word);
	if(strstr(source,word))
		printf("the word is found\n");
	else
		printf("no similar pattern found in the source\n");

	return 0;
}

