// costructtreeinoreder.cpp : Defines the entry point for the console application.
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
node *pre1(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	printf("%d\n",temp->data);
	pre1(temp->left);
	pre1(temp->right);
}
int maximum(int in[],int start,int end)
{
	int max=0;
	int pos=0;
	for(int i=start;i<=end;i++)
	{	
		if(in[i]>max)
		{
			pos=i;
			max=in[i];
		}
	}
	return pos;
}
node *inorder(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	inorder(temp->left);
	printf("%d\n",temp->data);
	inorder(temp->right);


}
node *constructbin(int in[],int start,int end)
{
	int pos=maximum(in,start,end);
	if(start>end)
		return NULL;
	node *temp=insert(in[pos]);
	if(start==end)
		return temp;
	temp->left=constructbin(in,start,pos-1);
	temp->right=constructbin(in,pos+1,end);
	return temp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int in[]={5,10,40,30,28};
	node *res=constructbin(in,0,4);
	printf("the inorder traversal of tree generated is\n");
	pre1(res);
	return 0;
}

