// SPIRALWAY.cpp : Defines the entry point for the console application.
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
struct node *root1=(node *)malloc(sizeof(struct node);
int diameter=0;
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
int hold=1;
int checksum(node *temp)
{
	if(temp==NULL)
		return NULL;
	if(temp->left==NULL&&temp->right==NULL)
		return NULL;
	checksum(temp->left);
	checksum(temp->right);
	int sum=0;
	sum+=(temp->left==NULL)?0:temp->left->data;
	sum+=(temp->right==NULL)?0:temp->right->data;
	if(temp->data!=sum)
			hold=0;
	return hold;
}
node *converttosum(node *temp)
{
	if(temp==NULL)
		return NULL;
	if(temp->left==NULL&&temp->right==NULL)
		return NULL;
	converttosum(temp->left);
	converttosum(temp->right);
	int sum=0;
	sum+=(temp->left==NULL)?0:temp->left->data;
	sum+=(temp->right==NULL)?0:temp->right->data;
	if(temp->data>sum)
	{
		int diff=temp->data-sum;
		temp->left->data+=diff;
	}
	else if(sum>temp->data)
	{
		int diff=sum-(temp->data);
		temp->data+=diff;
	}
	return temp;
}
int calcdiamter(node *temp)
{
	if(temp==NULL)
		return NULL;
	printf("%d",temp->data);
	if(temp->right==NULL)
		calcdiamter(temp->left);
	else if(temp->right!=NULL)
		calcdiamter(temp->right);
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	root=insert(20);
	root->left=insert(13);
	root->right=insert(38);
	root->left->left=insert(6);
	root->left->right=insert(7);
	root->right->left=insert(18);
	root->right->right=insert(21);
	root->left->left->left=insert(1);
	root->left->left->right=insert(4);
	/*root->right->right->left=insert(6);
	root->right->right->right=insert(1*/
	printf("the inorder traversal of tree formed by double linked list is\n");
	inorder(root);
	int check=1;
	if(checksum(root))
		printf("the rule hold for the given tree\n");
	else
		printf("the rule broken now lets convert\n");
	node *res=converttosum(root);
	hold=1;
	if(checksum(res))
		printf("the rule hold for the given tree\n");*/
	return 0;
}