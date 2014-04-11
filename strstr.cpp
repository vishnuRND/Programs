// strstr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
bool compare(char *a,char *b)
{
	strcat(a,b);
	if(strstr(a,b))
		return 1;
	else
		return 0;


}
int _tmain(int argc, _TCHAR* argv[])
{
   char *a="abcd";
   char *b="acbd";
	bool res=compare(a,b);
	if(res==0)
		printf("%s is not rotation of %s",b,a);
	else
		printf("%s is rotation od %s",b,a);

	return 0;
}

