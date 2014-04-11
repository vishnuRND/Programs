// circularlinkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;
};
struct node *root=(node *)malloc(sizeof(node));
node *root1=NULL;
int n;
node *createnode(int data)
{
	node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void print(node *temp,node *root)
{
	printf("the given linked list is:\n");
	int count=1;
	while(temp->next!=root)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d->%d\n",temp->data,temp->next->data);
}
node *insert(int data,int pos)
{
	node *temp=createnode(data);
	node *temp1=root;
	int count=1;
	if(pos==0)
	{
		while(temp1->next!=root)
			temp1=temp1->next;
		node *next=temp1->next;
		temp1->next=temp;
		temp->next=next;
		return root;
	}
	while(count<pos-1)
	{
		temp1=temp1->next;
		count++;
	}
	node *next=temp1->next;
	temp1->next=temp;
	temp->next=next;
	return root;
}
node *delete1(int pos)
{
	node *temp1=root;
	int count=1;
	if(temp1==NULL)
		return NULL;
	while(count<pos-1)
	{
		temp1=temp1->next;
		count++;
	}
	node *next=temp1->next;
	temp1->next=next->next;
	next->next=NULL;
}
int splittwo(node *temp)
{
	if(temp==NULL)
		return NULL;
	node *temp1=temp;
	 while(temp1->next != root &&temp1->next->next != root) 
	 {
		 temp1 = temp1->next->next;
		 temp = temp->next;
	 }	 
	 if(temp1->next->next == root)
		 temp1 =temp1->next;  
	root1=temp->next;
	temp->next=root;
	temp1->next=root1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//int n;
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
	temp->next=root;
	print(root,root);
	splittwo(root);
	print(root,root);
	print(root1,root1);
	return 0;
}

