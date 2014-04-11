// node delete.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 100
struct node
{
	int  data;
	node *next;
};
class stack
{
public:
		int top,ele;
		char a[max];
		void push(char ele)
		{
			if(top==max-1)
				printf("the stack is full\n");
			a[++top]=ele;
		}
		char pop()
		{
			if(top==-1)
				printf("stack is empty\n");
			else
			{
				ele=a[top];
				top--;
			}
			return ele;
		}
		stack()
		{
			top=-1;
		}
}s1;
node *create(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
int display(node *temp)
{
	if(temp==NULL)
		return NULL;
	while(temp!=NULL)
	{
			printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
node *delete1(node *root,int data)
{
	node *temp=root;
	while(temp->data!=data)
		temp=temp->next;
	temp->data=temp->next->data;
	temp->next=temp->next->next;
	return root;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;char data;
	printf("enter the node of nodes in the linked list\n");
	scanf("%d",&n);
	fflush(stdin);
	printf("enter data\n");
	scanf("%d",&data);
	//s1.push(data);
	node *root=create(data);
	node *temp=root;
	for(int i=1;i<n;i++)
	{
		fflush(stdin);
		printf("enter data\n");
		scanf("%d",&data);
		//s1.push(data);
		node *temp1=create(data);
		temp->next=temp1;
		temp=temp1;
	}
	display(root);
	/*printf("enter data that you want to delete\n");
	scanf("%d",&data);
	node *res=delete1(root,data);
	display(res);*/
	/*while(s1.top!=-1)
	{
		char ele=s1.pop();
			printf("%c->",ele);
	}*/
	node *even=NULL;
	node *odd=NULL;
	node *prev=even;
	node *prev1=NULL;
	temp=root;
	int count=1;
	while(temp!=NULL)
	{
		if(count%2==0)
		{
			if(prev==NULL)
			{
				even=temp;
				prev=even;
			}
			else
			{
				prev->next=temp;
				prev=temp;
			}
		}
		else
		{
			if(prev1==NULL)
			{
				odd=temp;
				prev1=odd;
			}
			else
			{
				prev1->next=temp;
				prev1=temp;
			}
		}
		node *next=temp->next;
		temp->next=NULL;
		temp=next;
		count++;
	}
	prev->next=odd;
	display(even);
	return 0;
}

