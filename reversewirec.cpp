// reversewirec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
char *reverse(char str[],int start,int end)
{
		if(end<=start)
			return NULL;
		else
		{
			char temp;
			temp=str[end];
			str[end]=str[start];
			str[start]=temp;
			reverse(str,start+1,end-1);

		}
		return str;

}
int _tmain(int argc, _TCHAR* argv[])
{
	char str[]="vishnu";
	int start=0;
	int end=strlen(str)-1;
	char *rev=reverse(str,start,end);
	for(int i=0;i<strlen(str);i++)
		printf("%c",str[i]);
	return 0;
}

