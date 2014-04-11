// rotatinglist.cpp : Defines the entry point for the console application.
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
	printf("\n\nthe given linked list is:\n");
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;

	}

}
node *rotate(node *root,int pos,int n)
{
	node *temp=root;
	node *temp1=root;
	node *temp2=NULL;
	for(int i=1;i<=n-pos;i++)
		temp1=temp1->next;
	while(temp1->next!=NULL)
	{
	 temp=temp->next;
	 temp1=temp1->next;
	}
	temp1->next=root;
	temp1=temp->next;
	temp->next=NULL;
	root=temp2;
	return temp1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data,pos;
	printf("enter no of nodes in linked list1\n");
	scanf("%d",&n);
	printf("enter data part of linked list1\n");
	scanf("%d",&data);
	root=createnode(data);
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
	printf("enter the position\n");
	scanf("%d",&pos);
	node *res=rotate(root,pos,n);
	print(res);
	return 0;
}

