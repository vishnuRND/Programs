// sorttwosort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;

};
struct node *root=(node *)malloc(sizeof(node));
struct node *root1=(node *)malloc(sizeof(node));
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
node *sort(node *a,node *b)
{
	node *temp=a;
	node *next;
	while(a!=NULL&&b!=NULL)
	{
	
		if(a->data>b->data)
		{
           next=b->next;
		   b->next=a;
		   b=next;

		}
		else if(a->data<b->data)
		{
			next=a->next;
			a->next=b;
			a=next;

		}
		else if(a->data==b->data)
		{
			next=a->next;
			a->next=b;
			a=next;

		}

	}

	return temp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data;
	printf("enter no of nodes in linked list1\n");
	scanf("%d",&n);
	printf("enter data part of linked list1\n");
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
	printf("enter no of nodes in linked list2\n");
	scanf("%d",&n);
	printf("enter data part of linked list2\n");
	scanf("%d",&data);
	root1->data=data;
	root1->next=NULL;
	node *temp2=root1;
	for(int i=1;i<n;i++)
	{
		printf("enter data part of linked list2\n");
		scanf("%d",&data);
		temp1=createnode(data);
		temp2->next=temp1;
		temp2=temp1;
	}
	print(root1);
	node *res=sort(root,root1);
	print(res);
	return 0;
}

