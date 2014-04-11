// NFIRST N LAST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
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
node *deletefirstlast(node *root,int  pos)
{
	node *temp=root;
	node *temp1=root;
	node *hold=NULL;
	int count=1;
	if(pos==1)
	{
		hold=temp1;
		temp1=temp1->next;
		while(temp1->next!=NULL)
		{
			temp=temp->next;
			temp1=temp->next;

		}
		root=hold->next;
		hold->next=NULL;
		temp->next=temp->next->next;

	}
	else
	{
	while(count<pos+1)
	{
		if(count==pos-1)
			hold=temp1;
		temp1=temp1->next;
		count++;
	}
	while(temp1->next!=NULL)
	{
		temp=temp->next;
		temp1=temp1->next;
	}
	hold->next=hold->next->next;
	temp->next=temp->next->next;
}
	return root;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data;
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	printf("enter data part of linked list\n");
	scanf("%d",&data);
	root->data=data;
	root->next=NULL;
	node *temp=root;
	node *temp1;
	for(int i=1;i<n;i++)
	{
		printf("enter data part of linked list\n");
		scanf("%d",&data);
		temp1=createnode(data);
		temp->next=temp1;
		temp=temp1;
	}
	print(root);
	int pos;
	printf("enter the position\n");
	scanf("%d",&pos);
	if(pos>n)
	{
		printf("enter the valid position\n");
		exit(0);
	}
	node *res=deletefirstlast(root,pos);
	print(res);
	return 0;
}

