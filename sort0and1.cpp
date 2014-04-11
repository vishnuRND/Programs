// sortond1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;

};
struct node *root1=(node *)malloc(sizeof(node));
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
node *sort(node *root1,node *root,node *root2)
{
	node *temp=root1;
	node *temp1=root;
	node *temp2=root2;
	if(temp2==NULL||temp==NULL||temp1==NULL)
		return NULL;
	node *next=NULL;
	while(temp!=NULL)
	{
		next=temp->next;
		if(temp->data==0)
		{
			temp1->next=temp;
			temp->next=NULL;
			temp1=temp;
		}
		else if(temp->data==1)
		{
			temp2->next=temp;
			temp->next=NULL;
			temp2=temp;

		}
		temp=next;
		
	}//we get 2 linked list one with o's and other with 1's
	next=root->next;//removing the dummy node 0
	root->next=NULL;
	root=next;
	next=root2->next;//removing the dummy node 1
	root2->next=NULL;
	temp1->next=next;
	return root;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data;
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	printf("enter data part of linked list\n");
	scanf("%d",&data);
	root1=createnode(data);
	node *temp=root1;
	node *temp1;
	for(int i=1;i<n;i++)
	{
		printf("enter data part of linked list\n");
		scanf("%d",&data);
		temp1=createnode(data);
		temp->next=temp1;
		temp=temp1;
	}
	print(root1);
	node *root=createnode(0);//creating dummy node to store 0	
	node *root2=createnode(1);//to store 1;
	node *res=sort(root1,root,root2);
	print(res);
	return 0;
}

