// lastkthelement.cpp : Defines the entry point for the console application.
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
node *head=NULL;
node *temp2;
int count=1;
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
int checkcount(int k)
{
	int totallen=count*2-1;
	int move=totallen-(k-1)-count;
	return move;
}
int checkcount1(int k)
{
	int totallen=count*2;
	int move=totallen-(k-1)-count;
	return move;
}
//node *lastk(node *root,int position)
//{
//	node *temp=root;
//	node *temp1=root;
//	//int k=position;
//	int move=-1;
//	while(temp!=NULL)
//	{
//		if(already==0&&temp1->next==NULL)
//		{
//			move=checkcount1(position);
//			count=0;
//			already=1;
//		}
//		else if(already==0&&temp1->next->next==NULL)
//		{
//
//			move=checkcount(position);
//			count=0;
//			already=1;
//
//		}
//		if(count==move)
//		{
//			return temp;
//
//		}
//		if(temp1->next!=NULL)
//		{
//			temp1=temp1->next->next;
//
//		}
//		count++;
//		temp=temp->next;
//	}
//
//
//
//
//
//}
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
node *alternate(node *temp)
{
		node *temp1=temp->next;
  while(temp!=NULL)
  {
	if(count==2)
	{
     	temp2=temp;
		temp2->next=NULL;
		if(prevtail==prestail)
		{
			prestail=temp;
			head=reverse(hold);
			count==1;
			
		}
		else
		{
             prevtail=prestail;
			 prestail=temp2;
			 head=reverse(hold);
			 prevtail->next=head;
			 count=1;

		}
		temp=temp1;

	}
	else if(temp1!=NULL)
	{
	 count++;
	 temp=temp->next;
	 temp1=temp->next;
	}
	else
	  temp=temp->next;
  }
  return root;
}


int _tmain(int argc, _TCHAR* argv[])
{
   	int n,data,k;
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
    temp=alternate(root);
	print(root);
	return 0;
}

