// pair diif.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int count=0;
void pair(int numbers[],int end,int diff)
{
	int i=end-1;
	while(i>=0)
	{
		if(numbers[i]-numbers[i-i]==diff)
		{
			printf("first number:%d\nsecond number:%d\n",numbers[i],numbers[i-1]);
		}
	   i--;
	}
	if(numbers[end-1]-numbers[0]==diff)
	{
		printf("first number:%d\nsecond number:%d\n",numbers[end-1],numbers[0]);

	}
}
void q_sort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;
 
  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, left, pivot-1);
  if (right > pivot)
    q_sort(numbers, pivot+1, right);
 
}

void quickSort(int numbers[], int array_size)
{
  q_sort(numbers, 0, array_size - 1);
}
 
 

int _tmain(int argc, _TCHAR* argv[])
{
	int numbers[]={90,80,70,50,20};
	int diff=20;
	quickSort(numbers,5);
	 for(int i=0;i<5;i++)
	  printf("%d\n",numbers[i]);
	 pair(numbers,5,diff);
	return 0;
}

