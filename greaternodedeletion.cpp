// greaternodedeletion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;

};
struct node *root=(node *)malloc(sizeof(struct node));
node *createnode(int data)
{
	node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void print(node *temp)
{
	printf("\nthe given linked list is:\n");
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;

	}

}
node *greatdelete(node *temp)
{
	int visited=0;
	node *prev=NULL,*res=NULL;
	if(temp==NULL)
		return NULL;
	node *next=NULL;
	while(temp->next!=NULL)
	{
		if(temp->data<temp->next->data)
		{
			next=temp->next;
			if(visited==0)
			{
				res=next;
				visited=1;
			}
			temp->next=NULL;
			next->next=prev;
			prev=next;
		}
		temp=next;

	}
	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n1,data;
	printf("enter no of nodes in linked list1\n");
	scanf("%d",&n1);
	printf("enter data\n");
	scanf("%d",&data);
	root=createnode(data);
	node *temp=root;
	node *temp1;
	for(int i=2;i<=n1;i++)
	{
		printf("enter data\n");
		scanf("%d",&data);
		temp1=createnode(data);
		temp->next=temp1;
		temp=temp1;
	}
	print(root);
	node *res=greatdelete(root);
	print(res);
	return 0;
}

