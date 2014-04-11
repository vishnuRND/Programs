// fromyaxis.cpp : Defines the entry point for the console application.
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
struct node *root1=(node *)malloc(sizeof(struct node));
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
int yaxis(node *temp)
{
	if(temp==NULL)
		return NULL;
	if(temp->right!=NULL)
	{
		printf("%d\n",temp->data);
		yaxis(temp->right);
	}
	else
	{
		printf("%d\n",temp->data);
		yaxis(temp->left);
	}



}
int _tmain(int argc, _TCHAR* argv[])
{
	
	root=insert(20);
	root->left=insert(13);
	//root->right=insert(40);
	root->left->left=insert(3);
	root->left->right=NULL;
	//root->right->left=NULL;
	//root->right->right=insert(45);
	root->left->left->left=NULL;
	root->left->left->right=insert(8);
	//root->right->right->left=insert(43);
	//root->right->right->right=NULL;
	printf("the inorder traversal of the above tree is\n");
	inorder(root);
	yaxis(root);
	return 0;
}

