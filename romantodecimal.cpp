// roamntonum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>
int num=0;
int hold=0;
int great;
struct table
{
	int value;
	
}tab[25];
void init()
{
	
	tab['I'-'A'].value=1;
	tab['V'-'A'].value=5;
	tab['X'-'A'].value=10;
	tab['L'-'A'].value=50;
	tab['C'-'A'].value=100;
	tab['D'-'A'].value=500;
	tab['M'-'A'].value=1000;
}
void decimal(char s[],int end)
{
	if(end==1)
		num=tab[s[end]-'A'].value;
	else
	{
	num=tab[s[end-1]-'A'].value;
	int i=end-2;
	while(i>=0)
	{
		if(tab[s[i]-'A'].value<great)
		{
			hold=tab[s[i]-'A'].value;
		//	num=hold-num;
		}
		if(tab[s[i]-'A'].value>=great)
		{
			num+=tab[s[i]-'A'].value;
			num-=hold;
			great=tab[s[i]-'A'].value;
			hold=0;
		}
		i--;

	}
	}

		

}
int _tmain(int argc, _TCHAR* argv[])
{
	char s[10];
	init();
	printf("the initialization of standard values completed\n");
	printf("now enter the roman value\n");
	scanf("%s",s);
	int len=strlen(s);
	//s.length;
	great=tab[s[len-1]-'A'].value;
	decimal(s,len);
	printf("the decimal value is\n");
	printf("%d",num);
	return 0;
}

