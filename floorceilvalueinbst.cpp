// floorceilvalueinbst.cpp : Defines the entry point for the console application.
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
node * ceil(node *root,int key)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->data==key)
	{
		printf("%d\n",temp->data);
		return NULL;
	}
	if(temp->left==NULL&&temp->right==NULL)
	{
		printf("%d\n",temp->data);
		return NULL;
	}
	if(temp->data>key)
		ceil(temp->left,key);
	if(temp->data<key)
		ceil(temp->right,key);
}
int _tmain(int argc, _TCHAR* argv[])
{
	root->data=8;
	root->left=insert(4);
	root->right=insert(12);
	root->left->left=insert(2);
	root->left->right=insert(6);
	root->right->left=insert(10);
	root->right->right=insert(14);
	printf("the given binary tree is\n");
	inorder(root);
	for(int i=0;i<16;i++)
		ceil(root,i);
	return 0;
}

