// alterndelete.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
struct node
{
	int data;
	node *next;

};
struct node *root=(node *)malloc(sizeof(node));
node * even(node *temp)
{
	node *temp1=temp->next;
	node *temp2=temp1;
	node *fp;
	while(temp1!=NULL)
	{
		fp=temp1->next->next;
		temp1->next=fp;
		temp1=fp;
	}
	return temp2;

}
node* odd(node *temp)
{
	node *temp1=temp;
	node *fp=(node *)malloc(sizeof(struct node));
	while(temp1->next!=NULL)
	{
		fp=temp1->next->next;
		temp1->next=fp;
		temp1=fp;

	}
	return temp;


}
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
int _tmain(int argc, _TCHAR* argv[])
{
	int n,ch;
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
	print(root);
	printf("\n\nenter your choice of alternating deletion\n1.even places\n2.odd places\nenter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:temp1=even(root);
		    print(temp1);
		    break;
	case 2:temp1=odd(root);
		    print(temp1);
		    break;
	default:
		    printf("enter correct choice\n");
			break;
	}

	return 0;
}

