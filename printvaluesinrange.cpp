// printvaluesinrange.cpp : Defines the entry point for the console application.
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
node *inorder(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return root;
	inorder(temp->left);
	printf("%d\n",temp->data);
	inorder(temp->right);

}
int range(node *root,int r1,int r2)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(r1<=temp->data&&r2>=temp->data)
		printf("%d\n",temp->data);
	if(r1<temp->data)
		range(temp->left,r1,r2);
	if(r2>temp->data)
		range(temp->right,r1,r2);
}
int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(20);
	root->left=insert(8);
	root->right=insert(22);
	root->left->left=insert(4);
	root->left->right=insert(12);
	/*root->right->left=insert(7);
	root->right->right=insert(9);
	root->left->left->right=insert(6);
	root->right->left->right=insert(8);*/
	printf("the binary tree is\n");
	inorder(root);
	int r1,r2;
	printf("enter base range\n");
	scanf("%d",&r1);
	printf("enter end range\n");
	scanf("%d",&r2);
	printf("the nodes within range are\n");
	range(root,r1,r2);
	return 0;
}

