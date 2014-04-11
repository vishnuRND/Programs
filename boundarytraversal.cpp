// boundarytraversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 4
struct node
{
	int data;
	node *left;
	node *right;
};
node *root=(node *)malloc(sizeof(struct node));
int arr[4];
int top=-1;
void push(int ele)
{
	if(top==max-1)
		printf("stack is full\n");
	arr[++top]=ele;

}
int pop()
{
	int ele;
	if(top==-1)
		printf("stack is empty\n");
	ele=arr[top];
	top--;
	return ele;
}
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
	node *temp=root;
	if(temp==NULL)
		return root;
	inorder(temp->left);
	printf("%d\n",temp->data);
	inorder(temp->right);

}
node *leftboundarynotleaf(node *root)
{	
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->left==NULL&&temp->right==NULL)
		return NULL;
	printf("%d\n",temp->data);
	leftboundarynotleaf(temp->left);

}
node *rightboundarynotleaf(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->right==NULL&&temp->left==NULL)
		return NULL;
	push(temp->data);
	rightboundarynotleaf(temp->right);
}
node *leaves(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->left==NULL&&temp->right==NULL)
		printf("%d\n",temp->data);
	leaves(temp->left);
	leaves(temp->right);

}
int reverse(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->left==NULL&&temp->right==NULL)
		printf("%d\n",temp->data);
	reverse(temp->left);
	reverse(temp->right);
	if(!(temp->left==NULL&&temp->right==NULL))
	printf("%d\n",temp->data);
}
int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);
	root->right->left=insert(7);
	root->right->right=insert(9);
	root->left->left->right=insert(6);
	root->right->left->right=insert(8);
	printf("the binary tree is\n");
	inorder(root);
	printf("the boudary nodes are\n");
	leftboundarynotleaf(root);
	leaves(root);
	rightboundarynotleaf(root);
	while(top>=0)
		printf("%d\n",pop());
	printf("the reverse inorer is\n");
	reverse(root);
	return 0;
}

