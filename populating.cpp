// populating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *left;
	node *right;
	node *inorder;
};
node *root=(node *)malloc(sizeof(struct node));
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->inorder=NULL;
	return temp;
}

node *pre(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	int k=(temp->inorder==NULL)?0:temp->inorder->data;
	printf("%d\t%d\n",temp->data,k);
	pre(temp->left);
	pre(temp->right);
}
node *prev=NULL;
node *populate(node *temp)
{
	if(temp==NULL)
		return NULL;
	populate(temp->left);
	populate(temp->right);
	/*if(temp->right==NULL)
	{
		if(prev==NULL)
			prev=temp;
		else
		{
			prev->inorder=temp;
			prev=temp;
		}

	}
	else
	{
		node *right=temp->right;
		while(right->right!=NULL)
			right=right->left;
		temp->inorder=right;
	}

*/
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
	populate(root);
	pre(root);
	return 0;
}

