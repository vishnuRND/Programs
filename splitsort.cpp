// splitsort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
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
void split(node *root)
{
	node *one=createnode(-1);
	node *two=createnode(-1);
	node *first=one;
	node *second=two;
	node *temp=root;
	node *temp1=root->next;
	while(temp1!=NULL)
	{
		one->next=temp;
		two->next=temp1;
		one=temp;
		two=temp1;
		temp=temp->next->next;
		temp1=temp1->next->next;
		temp->next=NULL;
		temp1->next=NULL;
	}
	print(first);
	print(second);



}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,n2,data;
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	printf("enter data part of linked list\n");
	scanf("%d",&data);
	root->data=data;
	root->next=NULL;
	node *temp=root;
	node *temp1;
	for(int i=2;i<=n;i++)
	{
		printf("enter data part of linked list\n");
		scanf("%d",&data);
		temp1=createnode(data);
		temp->next=temp1;
		temp=temp1;
	}
	print(root);
	split(root);
	return 0;
}

