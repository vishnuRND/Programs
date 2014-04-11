// pairdiff.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int start;
int end;
void sort(int arr[])
{
   for(int i=start;i<end;i++)
   {
		for(int j=start;j<end;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int data=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=data;

			}
			else
				continue;

		}

   }
		


}
void print(int arr[],int last)
{
	for(int i=0;i<last;i++)
		printf("%d\n",arr[i]);

}
void pairdiff(int arr[],int start,int end,int diff)
{
	int i=start,j=end;
	int more=0,less=0;
	while(diff<arr[i])
	{
		more=i;
		i++;
	}
	while(arr[more]-diff>=arr[j])
	{
		less=j;
		j--;
		
	}
if(arr[more]-arr[less]==diff)
 printf("the pair is %d and %d\n",arr[more],arr[less]);
else
 printf("no such pair in the array\n");

}
void findindex(int arr[],int base,int arrsize)
{
	int i=base,j=arrsize-1;
	while(i<j)
	{
		if(arr[i]>arr[i+1])
		{
			start=i;
			break;
		}
		i++;
	}
	while(j>1)
	{
		if(arr[j]<arr[j-1])
		{
			end=j;
			break;
		}
		j--;

	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	int diff;
	/*int arr[]={5,20,3,2,50,80};*/
	int arr[]={4, 7, 10, 14, 27, 24, 20, 19, 17, 31, 37, 39};
	/*printf("enter the diff value\n");
	scanf("%d",&diff);*/
	printf("the elements are\n--------------\n");
	print(arr,(sizeof(arr)/sizeof(arr[0])));
	findindex(arr,0,(sizeof(arr)/sizeof(arr[0])));
	sort(arr);
	printf("after sorting elements are\n---------------------\n");
	print(arr,(sizeof(arr)/sizeof(arr[0])));
	/*pairdiff(arr,0,6,diff);*/
	return 0;
}

