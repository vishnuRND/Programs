// sorting a link.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;

};
int arr[25]={0};
struct node *root=(node *)malloc(sizeof(struct node));
struct node *root1=(node *)malloc(sizeof(struct node));
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
node *union1(node *temp,node *temp1)
{
	node *res=NULL;
	while(temp!=NULL)
	{
		arr[temp->data]=1;
		temp=temp->next;
	}
	while(temp1!=NULL)
	{
		if(arr[temp1->data]==1)
		{
			node*temp2=createnode(temp1->data);
			temp2->next=res;
			res=temp2;
		}
		temp1=temp1->next;
	}
	return res;
}
node *intersect(node *temp,node *temp1)
{

	node *res1=NULL;
	while(temp!=NULL)
	{
		node *temp2=createnode(temp->data);
		temp2->next=res1;
		res1=temp2;
		temp=temp->next;
	}
	while(temp1!=NULL)
	{
		if(arr[temp1->data]!=1)
		{
			node*temp3=createnode(temp1->data);
			temp3->next=res1;
			res1=temp3;
		}
		temp1=temp1->next;
	}
	return res1;

}
int _tmain(int argc, _TCHAR* argv[])
{
	int n1,data,n2;
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
	printf("enter no of nodes in linked list2\n");
	scanf("%d",&n2);
	printf("enter data\n");
	scanf("%d",&data);
	root1=createnode(data);
	node *temp2=root1;
	node *temp3;
	for(int i=2;i<=n2;i++)
	{
		printf("enter data\n");
		scanf("%d",&data);
		temp3=createnode(data);
		temp2->next=temp3;
		temp2=temp3;
	}
	print(root);
	print(root1);
	node *res=union1(root,root1);
	node *res1=intersect(root,root1);
	printf("the union of two given linked list is\n");
	print(res);
	printf("the intersection of given two linked list is\n");
	print(res1);
	return 0;
}

