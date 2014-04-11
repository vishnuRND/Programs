// moving vowelstolast.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;
};
struct node *root=(node *)malloc(sizeof(struct node));
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
int print(node *temp)
{
	if(temp==NULL)
		return NULL;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
//node * movelast(node *temp)
//{
//	if(temp==NULL)
//		return NULL;
////	node *prev=NULL;
//	int visited=0;
//	node *root1=insert(-1);
//	node *root2=NULL;
//	node *prev=root2;
//	node *prev1=root1;
//	//temp=temp->next;
//	while(temp!=NULL)
//	{
//		if((temp->data=='a')||(temp->data=='e')||(temp->data=='i')||(temp->data=='o')||(temp->data=='u'))
//		{
//			node *next=temp->next;
//			temp->next=NULL;
//			prev1->next=temp;
//			prev1=temp;
//			temp=next;
//		}
//		else
//		{
//			if(visited==0)
//			{
//				root2=temp;
//				prev=temp;
//				visited=1;
//			}
//			else
//				prev->next=temp;
//			prev=temp;
//			temp=temp->next;
//		}
//
//
//	}
//	prev->next=NULL;
//	node *hold=root1->next;
//	root1->next=NULL;
//	prev->next=hold;
//	return root2;
//}
node *swap(int start,int end)
{
	node *swap1=NULL,*swap2=NULL;
	int count=1;
	node *temp=root;
	if(temp==NULL)
		return NULL;
	int data1=0;
	while(temp!=NULL)
	{
		if(count==start)
			swap1=temp;
		if(count==end)
			swap2=temp;
		if(swap1!=0&&swap2!=0)
		{
			data1=swap1->data;
			swap1->data=swap2->data;
			swap2->data=data1;
			start=end+1;
			end=2*end;
		}
		temp=temp->next;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	char data;
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	printf("enter data\n");
	//fflush(stdin);
	scanf("%d",&data);
	root=insert(data);
	node *temp=root;
	for(int i=1;i<n;i++)
	{
		//fflush(stdin);
		printf("enter data\n");
		scanf("%d",&data);
		node *temp1=insert(data);
		temp->next=temp1;
		temp=temp1;
	}
	print(root);
	int k;
	//node *res=movelast(root);
	node *res=swap(0,3);
	print(res);
	return 0;
}

