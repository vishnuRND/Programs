// greaterlist.cpp : Defines the entry point for the console application.
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
node *rmvegrt(node *temproot)
{
	node *dummy=createnode(-1);
	node *temp=temproot;
	node *temp1=temproot->next;
	node *move=dummy;
	while(temp->next!=NULL)
	{
	if(temp->data<temp1->data)
	{
		move->next=temp1;	
		temp->next=NULL;
		temp=temp1;
		temp1=temp1->next;
	}
	else
	{
        move->next=temp;
		move=temp;
		temp=temp->next;
		temp1=temp1->next;
	}
	}

   return dummy->next;
}
node *alternate(node *temp,int n)
{
	int k=1;
	if(temp==NULL)
		return NULL;
	odd=createnode(-1);
	even=createnode(-1);
	node *temp1=odd;
	node *temp2=even;
	while(temp!=NULL)
	{
		node *next=temp->next;
		if(k%2==0)
		{
			temp1->next=temp;
			temp1=temp;
		}
		else
		{
			temp2->next=temp;
			temp2=temp;
		}
		temp->next=NULL;
		temp=next;
		k++;
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
	//node *res=rmvegrt(root);
	alternate(root,n);
	print(even->next);
	//printf("\n");
	print(odd->next);
	return 0;
}

