// grouprev.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;

};
struct node *root=(node *)malloc(sizeof(node));
node *prevtail=NULL;
node *prestail=NULL;
node *temphead=NULL;
node *revroot=NULL;
int count=1,first=0;
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
node *reverse(node *temp)
{
    node *prev=NULL;
	node *curr=temp;
	node *next=temp;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=NULL;
		curr->next=prev;
		prev=curr;
		curr=next;
     
	}
	return prev;

}
node *alternatesplit(node *temp,int k)
{
	temphead=temp;
	node *temp1=temp;
	node *temp2=NULL;
	temphead=temp;
	while(temp!=NULL)
	{
		if(temp==NULL||temp1==NULL)
			return root;
		if(count==k&&first==0)
		{
			prestail=temphead;
			temp=temp->next;
			temp1->next=NULL;
			root=reverse(temphead);
			temp1=temp;
			temphead=temp1;
			first=1;
			count=1;
		}
		else if(count==k&&first!=0)
		{
			prevtail=prestail;
			prestail=temphead;
			temp=temp->next;
			temp1->next=NULL;
			temp2=reverse(temphead);
			prevtail->next=temp2;
			temp1=temp;
			temphead=temp1;
			count=1;
		}
		if(temp!=NULL)
		{
		  temp=temp->next;
		  temp1=temp1->next;
		  count++;
		}
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
     int k;
	printf("\n\nenter splitting position\n");
	scanf("%d",&k);
	printf("\n\nafter splitting alternatively\n");
	node *res=alternatesplit(root,k);
	print(res);
	return 0;
}

