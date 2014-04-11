// lengthlongest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
int maxstart=0;
int maxend=0;
int maxlen=0;
int start=0;
int end=0,len=0;
struct table
{
	char ch;
	int visited;
	table()
	{

		visited=0;

	}


}map[30];
void lengthlong(char *str1)
{
	for(int i=0;i<strlen(str1);i++)
	{
         int value=(int)str1[i];
		 if(map[value%97].visited==0)
		 {
			 map[value%97].ch=str1[i];
			 map[value%97].visited=1;
			 maxstart=start;
			 end++;
			 len++;

		 }
		 else
		 {
			  
			 if(len>maxlen)
			 {
				 start=i;
				 maxend=end;
				 maxlen=len;

			 }
			 
               
		 }

	}
	for(int i=maxstart;i<=maxend;i++)
	{
		printf("%c",str1[i]);
		len++;

	}
	printf("\n");
	printf("%d",maxlen);

}

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[]="geeksforgeeks";
	lengthlong(str1);
	return 0;
}

