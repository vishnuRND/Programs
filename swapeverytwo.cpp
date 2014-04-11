// swapeverytwo.cpp : Defines the entry point for the console application.
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
node *swap(node *root)
{
	node *temp=root;
	node *temp1=root->next;
	while(temp->next!=NULL)
	{

		int tmp=temp->data;
		temp->data=temp1->data;
		temp1->data=tmp;
		temp=temp->next->next;
		if(temp==NULL)
		{
			printf("\nprocess completes as temp2 cannot move further\n");
			break;

		}
		temp1=temp1->next->next;

	}
	return root;
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
	for(int i=2;i<=n;i++)
	{
		printf("enter data part of linked list\n");
		scanf("%d",&data);
		temp1=createnode(data);
		temp->next=temp1;
		temp=temp1;
	}
	print(root);
	node *root1=swap(root);
	print(root1);
	return 0;
}

