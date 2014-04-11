// double.cpp : Defines the entry point for the console application.
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
void print(node *temp)
{
	printf("the given linked list is:\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->right;
	}
}
int inorder(node *temp)
{
	if(temp==NULL)
		return NULL;
	inorder(temp->left);
	printf("%d\n",temp->data);
	inorder(temp->right);
}
node *prev=NULL;
node *tree(node *root2)
{
	node *temp=root2;
	if(temp==NULL)
		return NULL;
	tree(temp->left);
	if(prev==NULL)
	{
		root1=temp;
		prev=temp;
	}
	else
	{
		prev->right=temp;
		temp->left=prev;
		prev=temp;
	}
	tree(temp->right);
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
	printf("the inorder traversal of tree formed by double linked list is\n");
	inorder(root);
	printf("the generated linked list is\n");
	tree(root);
	print(root1);
}

