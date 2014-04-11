// reverseof a double.cpp : Defines the entry point for the console application.
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
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node *print(node *root)
{
	node *temp=root;
	node *tail=NULL;
	printf("\n");
	while(temp!=NULL)
	{
		printf("->%d",temp->data);
		tail=temp;
		temp=temp->right;
	}
	return tail;
}
node * printrev(node *tail)
{
	node *temp=tail;
	node *head=NULL;
	printf("\n");
	while(temp!=NULL)
	{
		printf("->%d",temp->data);
		head=temp;
		temp=temp->left;
		
	}
	return head;
}
node *root1=NULL;
node *reverse(node *temp)
{
	if(temp==NULL)
		return NULL;
	node *prev=NULL;
	while(temp!=NULL)
	{
		node *next=NULL;
		if(prev==NULL)
		{
			prev=temp;
			root1=prev;
			next=temp->right;
			temp->right=NULL;
			temp->left=NULL;

		}
		else
		{
			next=temp->right;
			temp->right=prev;
			prev->left=temp;
			prev=temp;
		}
		
		temp=next;
	}
	root1=prev;
	root1->left=NULL;
	return root1;

}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data;
	printf("enter the number of nodes in the lnked list\n");
	scanf("%d",&n);
	printf("enter value of node\n");
	scanf("%d",&data);
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	node *temp=root;
	for(int i=1;i<n;i++)
	{
		printf("enter the value of node\n");
		scanf("%d",&data);
		node *temp1=insert(data);
		temp1->left=temp;
		temp->right=temp1;
		temp=temp1;
	}
	printf("the given doubly linked list is\n");
	node *tail=print(root);
	printrev(tail);
	node *res=reverse(root);
	tail=print(res);
	printrev(tail);
	return 0;

}

