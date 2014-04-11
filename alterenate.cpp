// alterenate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;

};
struct node *root=(node *)malloc(sizeof(node));
node *odd=NULL;
node *even=NULL;
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
node *alternatesplit(node *temp)
{
	if(temp==NULL)
		return NULL;
	while(temp!=NULL&&temp->next!=NULL)
	{
		node *next=temp->next;
		temp->next=temp->next->next;
		next->next=NULL;
		temp=temp->next;
	}
}
node *swap(node *temp)
{
	if(temp==NULL)
		return NULL;
	node *temp1=temp->next;
	while(temp!=NULL&&temp->next!=NULL)
	{
		int data=temp->data;
		temp->data=temp->next->data;
		temp->next->data=data;
		temp=temp->next->next;
		if(temp1->next!=NULL)
		temp1=temp1->next->next;
	}
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
	int ch;
	/*printf("\n1.odd split\n2.even split\n");
	printf("enter choice\n");
	scanf("%d",&ch);
	node *next;
	switch(ch)
	{
	case 1:
		    alternatesplit(root);
			print(root);
			break;
	case 2:
			next=root->next;
			root->next=NULL;
			alternatesplit(next);
			print(next);
			break;
	}
*/
	//swap(root);
	temp=root;
	node *next=root->next;
	while(temp->next->next!=NULL)
		temp=temp->next;
	root->next=NULL;
	node *next1=temp->next;
	temp->next=NULL;
	next1->next=next;
	temp->next=root;
	print(next1);
	return 0;
}

