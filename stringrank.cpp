// stringrank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
int fact(int num)
{
   int mul=1;
   while(num>0)
   {
      mul*=num;
  	  num=num-1;
   }

   return mul;

}
int right(char *str,int value)
{
	int count=0;
	for(int i=value+1;i<strlen(str);i++)
	{

		if((int)str[value]>(int)str[i])
			count++;
		else
			continue;

	}
	return count;
}
int findrank(char *str)
{
	int right1,rank=0;;
	for(int i=0;i<strlen(str);i++)
	{
		right1=right(str,i);
		rank+=fact(strlen(str)-(i+1))*right1;
       
	}
	return rank;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int rank=0;
	char str[]="string";
	rank=findrank(str);
	printf("rank is %d\n",rank+1);
	return 0;
}

