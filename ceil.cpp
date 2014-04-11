// ceil.cpp : Defines the entry point for the console application.
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
int displayin(node *temp)
{
	if(temp==NULL)
		return NULL;
	displayin(temp->left);
	printf("%d\n",temp->data);
	displayin(temp->right);
}
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int ceil(node *temp,int ceilvalue)
{
	if(temp==NULL)
		return NULL;
	if(temp->data==ceilvalue)
	{
		if(temp->right!=NULL)
			printf("the ceil value of %d is %d\n",temp->data,temp->right->data);
		else
			printf("the ceil value of %d is %d\n",temp->data,temp->data);
		if(temp->left!=NULL)
		{
			node *temp1=temp->left;
			while(temp1->right!=NULL)
			temp1=temp1->right;
			printf("the floor value of %d is %d\n",temp->data,temp1->data);
		}
		else
			printf("the floor value of %d is %d",temp->data,temp->data);
	
	}
	if(temp->data>ceilvalue)
		ceil(temp->left,ceilvalue);
	else
		ceil(temp->right,ceilvalue);

}
int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(40);
	root->left=insert(20);
	root->right=insert(45);
	root->left->left=insert(10);
	root->left->right=insert(25);
	root->right->left=insert(41);
	root->right->right=insert(50);
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	//root->left->right->left=insert(8);
	root->left->right->right=NULL;
	root->right->left->left=NULL;
	root->right->left->right=NULL;
	root->right->right->left=NULL;
	displayin(root);
	//root->right->right->right=insert(9);
	int ceilvalue;
	printf("enter the key value to which you want to find ceil value\n");
	scanf("%d",&ceilvalue);
	ceil(root,ceilvalue);
	return 0;
}

