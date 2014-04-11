// linkrevusingrev.cpp : Defines the entry point for the console application.
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
	printf("\n");
}
node *reverse(node *prev,node *curr)
{
	if(curr==NULL)
		return prev;
	node *next=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;
	reverse(prev,curr);
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
	node *prev=NULL;
	node *curr=root;
	node *root1=reverse(prev,curr);
	print(root1);
	return 0;
}

