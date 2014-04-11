// all linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int n;
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
	while(temp->next!=root)
	{
		printf("%d-->",temp->data);
		temp=temp->next;

	}

}
node *init()
{
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	root->data=1;
	root->next=NULL;
	node *temp=root;
	node *temp1;
	for(int i=2;i<=n;i++)
	{
		temp1=createnode(i);
		temp->next=temp1;
		temp=temp1;
	}

	return root;
}
node *delete1(node *root,int pos)
{
	node *temp;
	int count=1;
	if(pos>n)
	{
		printf("your selected position is beyond the range\n");
		return NULL;
	}
	else
	{
		temp=root;
		if(temp==NULL)
			return NULL;
		else
		{
			while(temp!=NULL)
			{
				if(count==pos-1)
					temp->next=temp->next->next;
				count++;
				temp=temp->next;

			}

		}

	}
	return temp;


}
node *insert(node *root,int pos,int data)
{
	node *temp;
	int count=0;
	if(pos>n+1)
	{
		printf("beyond the range\n");
		return NULL;
	}
	else
	{
		temp=root;
		if(temp==NULL)
			return NULL;
		else
		{

			while(temp!=NULL)
			{
				if(count==pos-1)
				{
					node *temp1=createnode(data);
					node *next=temp->next;
					temp->next=temp1;
					temp1->next=next;
				}
				temp=temp->next;
				count++;

			}
		}


	}

}
node *queuepush(int data)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	node *temp1=createnode(data);
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=temp1;
	return root;
}
node *queuepop()
{
	node *next=root->next;
	root->next=NULL;
	root=next;
	return root;
}
node *stackpop()
{
	node *temp=root;
	while(temp->next->next!=NULL)
		temp=temp->next;
	temp->next=NULL;
	return root;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int ch,data;
	int intialized=0,pos;
	printf("MENU LIST\n------------------------\n");
	printf("1.initalization\n2.delete node in linked list\n3.insert a node\4.queuepush\n5.queuepop\n6.stackpush\n7.stackpop\n8.display linked list\n");
	while(1)
	{
		printf("\nenter your choice\n");
		scanf("%d",&ch);
		node *temp=NULL;
		switch(ch)
		{
		case 1:
					if(intialized==0)
					{
						temp=init();
						intialized=1;
					}
					else
						printf("linked list is already intialized\n");
					break;
		case 2:
			       printf("enter position where you want to perform delete\n");
				   scanf("%d",&pos);
				   temp=delete1(root,pos);
				   break;

		case 3:
				printf("enter the position where you want to perform insert\n");
				scanf("%d",&pos);
				printf("enter data\n");
				scanf("%d",&data);
				temp=insert(root,pos,data);
				break;
		case 4:
				printf("enter data you want to push\n");
				scanf("%d",&data);
				temp=queuepush(data);
				break;
		case 5:
				temp=queuepop();
				break;
		case 6:
				printf("enter data you want to push\n");
				scanf("%d",&data);
				temp=queuepush(data);
				break;
		case 7:
				temp=stackpop();
				break;
		case 8:
				print(root);
				break;
		case 9:
				printf("enter valid choice\n");
				break;
		}
	}
	return 0;
}

