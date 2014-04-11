// foldable.cpp : Defines the entry point for the console application.
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

node *pre(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	printf("%d\n",temp->data);
	pre(temp->left);
	pre(temp->right);
}
int mirror(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	mirror(temp->left);
	//mirror(temp->right);
	node *temp1=temp->left;
	temp->left=temp->right;
	temp->right=temp1;
}
int compare(node *root,node *root1)
{
	node *temp=root;
	node *temp1=root1;
	if(temp==NULL||temp1==NULL)
		return NULL;
	int templeft,tempright,temp1left,temp1right;
	if(temp->left==NULL&&temp->right==NULL)
	{
		templeft=0;
		tempright=0;
	}
	if(temp->left!=NULL&&temp->right==NULL)
	{
		templeft=1;
		tempright=0;
	}
	if(temp->left==NULL&&temp->right!=NULL)
	{
		templeft=0;
		tempright=1;
	}
	if(temp->left!=NULL&&temp->right!=NULL)
	{
		templeft=1;
		tempright=1;
	}
	if(temp1->left==NULL&&temp1->right==NULL)
	{
		temp1left=0;
		temp1right=0;
	}
  if(temp1->left!=NULL&&temp1->right==NULL)
	{
		temp1left=1;
		temp1right=0;
	}
	if(temp1->left==NULL&&temp1->right!=NULL)
	{
		temp1left=0;
		temp1right=1;
	}
	if(temp1->left!=NULL&&temp1->right!=NULL)
	{
		temp1left=1;
		temp1right=1;
	}

	if(!((templeft==temp1left)&&(tempright==temp1right)))
	{
		printf("the tree is unfolded\n");
		exit(0);
	}
	compare(temp->left,temp1->left);
	compare(temp->right,temp1->right);
	//return 1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(20);
	root->left=insert(13);
	root->right=insert(40);
	root->left->left=insert(3);
	root->left->right=NULL;
	root->right->left=NULL;
	root->right->right=insert(45);
	root->left->left->left=NULL;
	root->left->left->right=insert(8);
	root->right->right->left=insert(43);
	root->right->right->right=NULL;
	printf("the inorder traversal of the binary tree is\n");
	pre(root);
	node *left=root->left;
	node *right=root->right;
	root->left=NULL;
	root->right=NULL;
	mirror(left);
	//printf("--\n");
	//pre(root);
	compare(left,right);
	printf("the trees are foldable\n");
	mirror(left);
	root->left=left;
	root->right=right;
	pre(root);
	return 0;
}

