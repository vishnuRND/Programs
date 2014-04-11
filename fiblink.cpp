// fiblink.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{

	int data;
	node *next;

};
node *head=(node *)malloc(sizeof(struct node));

node *create(int value)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	return temp;

}
void print(node *temp)
{
	while(temp!=NULL)
	{

		printf("->%d",temp->data);
		temp=temp->next;

	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	head->data=0;
	head->next=NULL;
	int n;
	printf("enter number of values you want to know\n");
	scanf("%d",&n);
	node *temp=head;
	node *temp1=create(1);
	temp->next=temp1;
	for(int i=2;i<n;i++)
	{
		node *temp2=create(temp->data+temp1->data);
		temp1->next=temp2;
		temp=temp1;
		temp1=temp2;
	}
	print(head);
	return 0;
}

