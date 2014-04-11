// constructtreepre.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *left;
	node *right;
};
node *root=(node *)malloc(sizeof(struct node));
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node *post(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	post(temp->left);
	post(temp->right);
	printf("%d\n",temp->data);

}
node *pre1(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	printf("%d\n",temp->data);
	pre1(temp->left);
	pre1(temp->right);
}
node *inorder(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	pre1(temp->left);
	printf("%d\n",temp->data);
	pre1(temp->right);
}
int less(int pre[],int ele,int start,int end)
{
	while(start<=end)
	{
		if(pre[start]>ele)
			return start;
		else
		start++;
	}
	return start;

}
int already=0;
node *constructreepre(int pre[],int start,int end,int endcons)
{
	static int i=0,j;
	if(start>end)
		return NULL;
	node *temp=insert(pre[i++]);
	j=i;
	if(temp==NULL)
		return NULL;
	if(start==end)
		return temp;
	if(j==end)
		return temp;
	int pos=less(pre,temp->data,j,end);
	if(endcons==pos-1)
	{
		temp->left=constructreepre(pre,start+1,pos,endcons);
	}
	else
	{
		temp->left=constructreepre(pre,start+1,pos-1,endcons);
		temp->right=constructreepre(pre,pos,end,endcons);
	}
	return temp;
}
int check(node *res)
{
	node *temp=res;
	if(temp==NULL)
		return 0;
	if(temp->left!=NULL&&temp->right!=NULL)
		return 0;
	if(temp->left!=NULL)
		check(temp->left);
	if(temp->right!=NULL)
		check(temp->right);
	return 1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int pre[]={20,10,11,13,12};
	node *res=constructreepre(pre,0,4,4);
	inorder(res);
	int k=check(res);
	if(k)
		printf("every node in bst has only one child\n");
	else
		printf("nope some nodes has more than one child\n");
	return 0;
}

