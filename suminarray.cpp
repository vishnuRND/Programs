// suminarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define MAX 50
void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
int present=0;
int check(int arr[],int sum,int start,int end)
{
	if(start>end)
		return NULL;
	if(arr[start]+arr[end]==sum)
		present=1;
	if(arr[start]+arr[end]<sum)
		check(arr,sum,start+1,end);
	else if(arr[start]+arr[end]>sum)
		check(arr,sum,start,end-1);
	return present;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={1,15,8,12,3,9,20};
	int j=(sizeof(arr)/sizeof(arr[0]))-1;
	partition(arr,0,j);
	int data;
	printf("enter sum value");
	scanf("%d",&data);
	if(arr[j-1]+arr[j]<data)
		printf("no such sum exists\n");
	else
	{
		if(check(arr,data,0,j))
			printf("sum exists\n");
		else
			printf("doesnt exists\n");
	}
	return 0;
}

