// rotate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
struct node
{
	int data;
	node *next;

};
struct node *root=(node *)malloc(sizeof(node));
node *createnode(int data)
{
	node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void print(node *temp)
{
	printf("the given linked list is:\n");
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;

	}

}
node *devide(node *temp,int part)
{
	if(temp==NULL)
		return NULL;
	int count=1;
	while(count!=part)
	{
		temp=temp->next;
		count++;
	}
	node *next1=temp->next;
	temp->next=NULL;
	node *temp1=next1;
	while(next1->next!=NULL)
		next1=next1->next;
	next1->next=root;
	root=temp1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data,part;
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	root->data=1;
	root->next=NULL;
	node *temp=root;
	node *temp1;
	for(int i=2;i<=n;i++)
	{
		temp1=createnode(i);
		temp->next=temp1;
		temp=temp1;
	}
	print(root);
	printf("enter the partition num\n");
	scanf("%d",&part);
	devide(root,part);
	print(root);
	return 0;
}

