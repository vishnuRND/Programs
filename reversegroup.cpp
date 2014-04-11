// reversegroup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
struct node
{
	int data;
	node *next;

};
struct node *root=(node *)malloc(sizeof(node));
struct node *lastail=NULL;
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
	int n,count=0;
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
	int group;
   temp1=reverse(temp);
   print(temp1);
	printf("\nenter group size\n");
	scanf("%d",&group);
	temp=root;
	temp1=root;
	node *temp2,*temp3;
	while(temp!=NULL)
	{
		if(count==group)
		{
			if(lastail==NULL)
			{
				temp3=temp;
				temp2=reverse(temp1);
				print(temp2);
				count=0;

			}
			else
			{
				temp3=temp->next;
				//temp2=reverse(temp1);
				lastail->next=temp2;
				count=0;
			}
			temp1=temp3;

		}
		else
			count++;
		temp1=temp;
       temp=temp->next;
	}
	print(root);
	return 0;
}

