// roamntonum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
int num=0;
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
void decimal(char s[])
{
	int got=0;
	int hold=0;
	for(int i=0;i<4;i++)
	{
		int start;
		if(i==0)
			num+=tab[s[i]-'A'].value;
		else
		{	
			if(tab[s[i]-'A'].value==tab[s[i-1]-'A'].value)
				num+=tab[s[i]-'A'].value;
			if(tab[s[i]-'A'].value<tab[s[i-1]-'A'].value)
			{
				start=i;
				while(tab[s[start]-'A'].value<=tab[s[start+1]-'A'].value&&start<3)
				{
					hold+=tab[s[start]-'A'].value;
					start++;
				}
				if(tab[s[start]-'A'].value>tab[s[start+1]-'A'].value)
					got=1;
			}
				i=start-1;
				if(got==1)
					num+=tab[s[i]-'A'].value-hold;
				else
				num+=hold;
				
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
	//s.length;
	decimal(s);
	printf("the decimal value is\n");
	printf("%d",num);
	return 0;
}

