// intersection point.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node 
{
	int data;
	node *next;
}arr[100];
struct table
{
	int source;
}hash[20];//a table to store source of nodes in linked list
struct node *root=(node *)malloc(sizeof(struct node));//root of list1
struct node *root1=(node *)malloc(sizeof(struct node));//root of list2
node *create(int data)
{
	struct node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
node *print(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}

}
int hash1(node *root,node *root1)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	while(temp->next!=NULL)//inserting source nodes of linked list1 into table hash
	{
		hash[temp->next->data].source=temp->data;
		temp=temp->next;
	}
	node *temp1=root1;
	if(temp1==NULL)
		return NULL;
	while(temp1->next!=NULL)
	{
		if(hash[temp1->next->data].source!=0)//comparing source nodes with linked list2.
			return temp1->next->data;
		else
			hash[temp1->next->data].source=temp1->data;
		temp1=temp1->next;
		
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data,count=1,pos;
	printf("enter num of nodes\n");
	scanf("%d",&n);
	printf("enter the intersection pos\n");
	scanf("%d",&pos);
	printf("enter data\n");
	scanf("%d",&data);
	root->data=data;
	root->next=NULL;
	node *temp=root;
	node *hold=NULL;
	for(int i=1;i<n;i++)
	{
		if(count==pos)
			hold=temp;//holdiing the address at that point of intersection
		printf("enter data\n");
		scanf("%d",&data);
		node *temp3=create(data);
		temp->next=temp3;
		temp=temp3;
		count++;
	}
	print(root);
	printf("\nenter the data in 2 linked list\n");
	scanf("%d",&data);
	root1->data=data;
	root1->next=NULL;
	node *temp1=root1;
	for(int i=0;i<2;i++)
	{
		printf("enter the data in 2 linked list\n");
		scanf("%d",&data);
		node *temp3=create(data);
		temp1->next=temp3;
		temp1=temp3;

	}
	temp1->next=hold;//connecting the linked list2 to the hold node intersection.
	print(root1);
	int intersect=hash1(root,root1);
	printf("the intersection node is%d\n",intersect);
	return 0;
}

