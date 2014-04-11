// binarytreetobinarysearchtreeconvert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int end;
struct node
{
	int data;
	node *left;
	node *right;
};
node *root=(node *)malloc(sizeof(struct node));
int numbers[10];
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node *inorder(node *root)
{
	static int i=0;
	node *temp=root;
	if(temp==NULL)
		return NULL;
	inorder(temp->left);
	printf("%d\n",temp->data);
	numbers[i++]=temp->data;
	inorder(temp->right);
	end=i;
}
node* copyvaluesin(node *root)
{
	static int i=0;
	node *temp=root;
	if(temp==NULL)
		return NULL;
	copyvaluesin(temp->left);
	temp->data=numbers[i++];
	copyvaluesin(temp->right);
	return temp;
}
////void merge(int numbers[], int temp[], int left, int mid, int right)
////{
////  int i, left_end, num_elements, tmp_pos;
//// 
////  left_end = mid - 1;
////  tmp_pos = left;
////  num_elements = right - left + 1;
//// 
////  while ((left <= left_end) && (mid <= right))
////  {
////    if (numbers[left] <= numbers[mid])
////    {
////      temp[tmp_pos] = numbers[left];
////      tmp_pos = tmp_pos + 1;
////      left = left +1;
////    }
////    else
////    {
////      temp[tmp_pos] = numbers[mid];
////      tmp_pos = tmp_pos + 1;
////      mid = mid + 1;
////    }
////  }
//// 
////  while (left <= left_end)
////  {
////    temp[tmp_pos] = numbers[left];
////    left = left + 1;
////    tmp_pos = tmp_pos + 1;
////  }
////  while (mid <= right)
////  {
////    temp[tmp_pos] = numbers[mid];
////    mid = mid + 1;
////    tmp_pos = tmp_pos + 1;
////  }
//// 
////  for (i=0; i <= num_elements; i++)
////  {
////    numbers[right] = temp[right];
////    right = right - 1;
////  }
////}
//void m_sort(int numbers[], int temp[], int left, int right)
//{
//  int mid;
// 
//  if (right > left)
//  {
//    mid = (right + left) / 2;
//    m_sort(numbers, temp, left, mid);
//    m_sort(numbers, temp, mid+1, right);
// 
//    merge(numbers, temp, left, mid+1, right);
//  }
//}
node *leastcommonancestor1=NULL;
 node * leastcommonancestor(node *root,int value1,int value2)
 {
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->data>value1&&temp->data<value2)
		leastcommonancestor1=temp;
	if(temp->data>value1&&temp->data>value2)
		leastcommonancestor(temp->left,value1,value2);
	if(temp->data<value1&&temp->data<value2)
		leastcommonancestor(temp->right,value1,value2);

	return leastcommonancestor1;
 }
//void mergeSort(int numbers[], int temp[], int array_size)
//{
//  m_sort(numbers, temp, 0, array_size - 1);
//}

 int sorted()
 {
	int i=0;
	while(i<end-1)
	{
		if(numbers[i]>numbers[i+1])
			return 0;
	}
	return 1;

 }
 void sort(int numbers[])
 {
	int i=0;
	while(sorted())
	{
		while(i<end-1)
		{	
			if(numbers[i]>numbers[i+1])
			{	
				int data=numbers[i+1];
				numbers[i+1]=numbers[i];
				numbers[i]=data;
			}
			i++;
		}
	}


 }
int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(10);
	root->left=insert(5);
	root->right=insert(8);
	root->left->left=insert(2);
	root->left->right=insert(20);
	/*root->right->left=insert(60);
	root->right->right=insert(100);
	root->left->left->left=insert(5);
	root->left->left->right=insert(15);
	root->left->right->left=insert(25);
	root->left->right->right=insert(35);
	root->left->left->left->left=insert(1);*/
	printf("the previous tree is\n");
	inorder(root);
	printf("after swapping\n");
	sort(numbers);
	node *res=copyvaluesin(root);
	inorder(res);
	/*int value1,value2;
	printf("enter value1\n");
	scanf("%d",&value1);
	printf("enter value2\n");
	scanf("%d",&value2);
	node *res=leastcommonancestor(root,value1,value2);
	printf("the least common ancestor of %d and %d is\n",value1,value2);
	printf("%d\n",res->data);*/
	/*mergeSort(numbers,temp,end);
	node *res=copyvaluesin(root);
	printf("the conversion from binary tree to binary search tree sussessfully completed\n");
	inorder(res);*/
	return 0;
}

