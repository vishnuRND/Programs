// double to bst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 10
int front=-1,rear=-1;
struct node
{
	int data;
	node *left;
	node *right;

};
node *root=(node *)malloc(sizeof(struct node));
node *arr[100];
node *bstroot=NULL;
void pushqueue(node *ele)
{
	if(rear==(max-1))
	{
		printf("queue is full\n");
	}
	else
	{
		rear=rear+1;
		arr[rear]=ele;
	}


}
node * popqueue()
{
	node *ele;
	if(rear==-1)
		printf("queue is empty\n");
	else
	{
		ele=arr[++front];
	}
	return ele;


}
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node *print(node *root)
{
	node *temp=root;
	node *tail=NULL;
	printf("\n");
	while(temp!=NULL)
	{
		printf("->%d",temp->data);
		tail=temp;
		temp=temp->right;
	}
	return tail;
}
node * printrev(node *tail)
{
	node *temp=tail;
	node *head=NULL;
	printf("\n");
	while(temp!=NULL)
	{
		printf("->%d",temp->data);
		head=temp;
		temp=temp->left;
		
	}
	return head;
}
void display(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return;
		display(temp->left);
		printf("%d\n",temp->data);
		display(temp->right);

}
int isempty_q()
{
	if(front==rear)
		return 1;
	else
		return 0;

}
node *initbst()
{
	root=insert(20);
	root->left=insert(13);
	root->right=insert(40);
	root->left->left=insert(3);
	root->left->right=NULL;
	root->right->left=NULL;
	root->right->right=insert(45);
	root->left->left->left=NULL;
	root->left->left->right=insert(8);
	root->right->right->left=insert(43);
	root->right->right->right=NULL;
	printf("the given binary search tree in inorder is\n");
	display(root);
	return root;

}
node *init()
{
	int n,data;
	printf("enter the number of nodes in the lnked list\n");
	scanf("%d",&n);
	printf("enter value of node\n");
	scanf("%d",&data);
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	node *temp=root;
	for(int i=1;i<n;i++)
	{
		printf("enter the value of node\n");
		scanf("%d",&data);
		node *temp1=insert(data);
		temp1->left=temp;
		temp->right=temp1;
		temp=temp1;
	}
	printf("the given doubly linked list is\n");
	node *tail=print(root);
	return root;
}
node *prev=NULL;
void converttodouble(node *head)
{
	node *temp=head;
	pushqueue(temp);
	while(!isempty_q())
	{
		temp=popqueue();
		node *temp1=insert(temp->data);
		if(prev!=NULL)
		{
			temp1->left=prev;
			prev->right=temp1;
		}
		prev=temp1;
		if(temp->left!=NULL)
			pushqueue(temp->left);
		if(temp->right!=NULL)
			pushqueue(temp->right);
	}
	printf("the double linked list in reverse and straight manner are given below\n");
	node *head1=printrev(prev);
	node *tail=print(head1);
}
void insertintotree(node *root,node *temp1)
{
	node *temp=root;
	node *temp2=NULL;
	while(temp!=NULL)
	{
		temp2=temp;
		if(temp->data<temp1->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
	if(temp2->data>temp1->data)
		temp2->left=temp1;
	else
		temp2->right=temp1;
}
void converttobst(node *head)
{
	node *next=NULL;
	node *temp=bstroot;
	node *temp1=head;
	while(temp1!=NULL)
	{
		next=temp1->right;
		temp1->right=NULL;
		if(next!=NULL)
			next->left=NULL;	
		if(bstroot==NULL)
		{
			bstroot=temp1;
		}
		else
		{
			insertintotree(bstroot,temp1);
		}
		temp1=next;
	}
	printf("the bst in preorder is\n");
	display(bstroot);
}	
int _tmain(int argc, _TCHAR* argv[])
{
	int ch;
	node *head;
	printf("\n1.cnvert bst to double linked list\n2.convert double inked list to bst\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
				head=initbst();
				converttodouble(head);
				break;
	    case 2:
				head=init();
				converttobst(head);
				break;
	}
	return 0;
}

