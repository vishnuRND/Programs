// addnumbersinlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 10
struct node
{
	int data;
	node *next;

};
struct node *root=(node *)malloc(sizeof(node));
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

}
class stack
{
public:
		int top,ele;
		int a[max];
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
			if(top==-1)
				printf("the stack is empty\n");
			for(int i=0;i<=top;i++)
				printf("%d\n",a[i]);
		}
		stack()
		{
			top=-1;

		}

}s1,s2;
node *add(node *temp,node *temp1)//pushing values of 2 linked lists to seperate stacks.
{

	while(temp!=NULL)
	{
		s1.push(temp->data);
		temp=temp->next;
	}
	while(temp1!=NULL)
	{
		s2.push(temp1->data);
		temp1=temp1->next;
	}
	node *prev=NULL;
	int hold=0;
	while(s1.top!=-1&&s2.top!=-1)//popping them to get values 
	{
		int num=s1.pop()+s2.pop()+hold;
		node *temp=NULL;
		if(num/10==0)
		{
			temp=createnode(num);
			hold=0;
		}
		else
		{
			temp=createnode(num%10);
			hold=num/10;
		}
		temp->next=prev;
		prev=temp;

	}
	if(hold!=0)
	{
		node *temp=createnode(hold);
		temp->next=prev;
		prev=temp;
	}
	return prev;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n1,data,n2;
	printf("enter no of nodes in linked list1\n");
	scanf("%d",&n1);
	printf("enter data\n");
	scanf("%d",&data);
	root=createnode(data);
	node *temp=root;
	node *temp1;
	for(int i=2;i<=n1;i++)
	{
		printf("enter data\n");
		scanf("%d",&data);
		temp1=createnode(data);
		temp->next=temp1;
		temp=temp1;
	}
	printf("enter no of nodes in linked list2\n");
	scanf("%d",&n2);
	printf("enter data\n");
	scanf("%d",&data);
	root1=createnode(data);
	node *temp2=root1;
	node *temp3;
	for(int i=2;i<=n2;i++)
	{
		printf("enter data\n");
		scanf("%d",&data);
		temp3=createnode(data);
		temp2->next=temp3;
		temp2=temp3;
	}
	print(root);
	print(root1);
	node *res=NULL;
	if(n1==n2)
	{
		res=add(root,root1);

	}
	else
	{
		int balnodes;
		 if(n1>n2)//adding node to linked list2 (n1-n2)nodes with value 0;
		 {
			 balnodes=n1-n2;
			 for(int i=0;i<balnodes;i++)
			 {
				 node *hold=createnode(0);
				 hold->next=root1;
				 root1=hold;
			 }
			 res=add(root,root1);

		 }
		 else
		 {

			 balnodes=n2-n1;
			 for(int i=0;i<balnodes;i++)//adding nodes to linked list1 n2-n1 nodes with value 0;
			 {
				 node *hold=createnode(0);
				 hold->next=root;
				 root=hold;
			 }
			res= add(root,root1);
		 }

	}
	print(res);
	return 0;
}

