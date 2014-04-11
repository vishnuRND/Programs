// GIVENINORDER.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *left;
	node *right;
};
struct node *root=(node *)malloc(sizeof(struct node));
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int inorder(node *temp)
{
	if(temp==NULL)
		return NULL;
	inorder(temp->left);
	printf("%d\n",temp->data);
	inorder(temp->right);
}
int getindex(int arr[],int start,int end)
{
	for(int i=start;i<end;i++)
	{
		if(arr[i]>=arr[i+1])
			return i;
	}
}
int getindex1(int data,int in[],int start,int end)
{
	for(int i=start;i<end;i++)
	{
		if(in[i]==data)
			return i;
	}

}
node *construct1(int pre[],int in[],int start,int end)
{
	if(start>end)
		return NULL;
	static int i=0;
	node *temp=insert(pre[i++]);
	if(temp==NULL)
		return NULL;
	if(start==end)
		return temp;
	int index=getindex1(temp->data,in,start,end);
	temp->left=construct1(pre,in,start,index-1);
	temp->right=construct1(pre,in,index+1,end);
	return temp;
}
node *construct(int arr[],int start,int end)
{
	if(start>end)
		return NULL;
	int pos=getindex(arr,start,end);
	node *temp=insert(arr[pos]);
	if(temp==NULL)
		return NULL;
	if(start==end)
		return temp;
	temp->left=construct(arr,start,pos-1);
	temp->right=construct(arr,pos+1,end);
	return temp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int pre[]={1,2,4,8,5,3,6,9,7};
	int in[]={8,4,2,5,1,6,9,3,7};
	//node *res=construct(pre,0,sizeof(pre)/sizeof(pre[0])-1);
	node *res=construct1(pre,in,0,sizeof(pre)/sizeof(pre[0])-1);
	inorder(res);
	return 0;
}

