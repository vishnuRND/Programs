// numpalandrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 10
int a[max];
class stack
{
public:
		int top,ele;
		void push(int ele)
		{
			if(top==max-1)
				printf("the stack is full\n");
			a[++top]=ele;
		}
		int pop()
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
		void display()
		{
			for(int i=0;i<=top;i++)
				printf("%d\n",a[i]);
		}
		stack()
		{
			top=-1;
		}
}s1;
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
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;

	}
	printf("\n");
}
int check(node *temp,int n)
{
	if(temp==NULL)
		return NULL;
	node *temp1=temp;
	while(temp1!=NULL&&temp1->next==NULL)
	{

		s1.push(temp->data);
		temp=temp->next;
		temp1=temp->next->next;

	}
	if(n%2!=0)
		s1.pop();
	while(temp!=NULL)
	{		
		if(temp->data!=s1.pop())
			return 0;
		temp=temp->next;
	}
	return 1;

}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data;
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	printf("enter data part of linked list\n");
	scanf("%d",&data);
	root=createnode(data);
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
	if(check(root,n))
		printf("its palindrome\n");
	return 0;
}

