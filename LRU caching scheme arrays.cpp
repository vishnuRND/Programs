// LRU caching scheme arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define maxmemory 100
#define maxcache 10
int memory[maxmemory];
int cache[maxcache];
int time[maxcache];
int findmin(int end)
{
	int min=time[0],pos=0;
	for(int i=0;i<end;i++)
	{
		if(time[i]<min)
			pos=i;

	}

	return pos;
}
int elementfound(int end,int data)
{
	for(int i=0;i<end;i++)
	{
		if(cache[i]==data)
			return i;
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int numframesinmem,numframesincache;
	printf("enter the number of frame values\n");
	scanf("%d",&numframesinmem);
	if(numframesinmem>maxmemory)
	{
		printf("memory has a max limit of %d\n",maxmemory);
		exit(0);
	}
	printf("enter max storage of frames in a cache\n");
	scanf("%d",&numframesincache);
	if(numframesincache>maxcache)
	{
		printf("cache has a max limit of %d\n",maxcache);
		exit(0);
	}
	for(int i=0;i<numframesinmem;i++)
	{
		printf("enter the frame value\n");
		scanf("%d",&memory[i]);
	}
	for(int j=0;j<numframesinmem;j++)
	{
		if((j>numframesincache-1)?1:0)
		{
			int pos=0;
			if(pos=elementfound(numframesincache,memory[j]))
			{
				time[pos]=j+1;

			}
			else
			{
				int index=findmin(numframesincache);
				cache[index]=memory[j];
				time[index]=j+1;
			}
		}
		else
		{
			cache[j]=memory[j];
			time[j]=j+1;
		}

		printf("the frames in a cache are\n");
		for(int i=0;i<numframesincache;i++)
			printf("%d\n",cache[i]);
	}
	
	return 0;
}

