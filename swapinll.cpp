
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
void print(node *temp)
{
	printf("\n\nthe given linked list is:\n");
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;

	}

}
node *swap(node *root,int data1,int data2)
{
	node *temp=root;
	node *prevstart,*prevend;
	int visited=0;
	while(temp->next!=NULL)
	{
		if((temp->next->data==data1||temp->next->data==data2))
		{
			if(visited==0)
			{
				prevstart=temp;
				visited=1;
			}
			else
				prevend=temp;

		}
			temp=temp->next;
	}
	node *start=prevstart->next;
	node *end=prevend->next;
	prevstart->next=end;
	node *next=end->next;
	end->next=start->next;
	prevend->next=start;
	start->next=next;
	return root;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data,pos;
	printf("enter no of nodes in linked list1\n");
	scanf("%d",&n);
	printf("enter data part of linked list1\n");
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
	int data1,data2;
	printf("enter 1st node\n");
	scanf("%d",&data1);
	printf("enter 2nd node\n");
	scanf("%d",&data2);
	node *res=swap(root,data1,data2);
	print(res);
	return 0;
}

