// reverseinorder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 15
struct node
{
	int data;
	node *left;
	node *right;
};
node *root=(node *)malloc(sizeof(struct node));
class queue
{
public:
	int front,rear;
	node *arr[max];
	void push(node *ele)
	{
		if(rear==max-1)
			printf("the queue is full\n");
		if(front==max-1&&rear==max-1)
		{
			front=-1;
			rear=-1;
		}
			arr[++rear]=ele;

	}
	node *pop()
	{
		node *ele;
		if(front==max-1||(front==-1&&rear==-1))
		{
			printf("the queue is empty\n");
			return NULL;
		}
		if(front==max-1&&rear==max-1)
		{
			front=-1;
			rear=-1;
		}
		ele=arr[++front];
		return ele;
	}
	void display()
	{
		int i;
		if(front==rear)
			printf("the queue is empty\n");
		else
		{
		printf("the elements in the queue are\n");
		for(i=front;i<rear;i++)
			printf("%d\n",arr[i]);
		}
	}
	int isemtpy_q()
	{
		if(front==rear)
			return 1;
		else
			return 0;

	}

	queue()
	{
		front=-1;
		rear=-1;
	}

}q1;
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
			for(int i=0;i<=top;i++)
				printf("%d\n",a[i]);
		}
		stack()
		{
			top=-1;
		}
}s1;
node *inorder(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return root;
	inorder(temp->left);
	printf("%d\n",temp->data);
	inorder(temp->right);

}
void print(node *root)
{
	node *temp=root;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->right;
	}

}
node *insert(int data)
{
	
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void revlevelorder(node *root)
{
  node *temp=root;
  q1.push(temp);
  s1.push(temp->data);
  while(!q1.isemtpy_q())
  {
	  int end=q1.rear;
	  int start=q1.front;
	 // node *prev=NULL;
	  //node *root1=NULL;
	  //node *hold=NULL;
	 // node *hold1=NULL;
	  for(int i=start;i<end;i++)
	  {
		  node *hold1=q1.pop();
		 /* if(prev==NULL)
		  {
			  root1=insert(hold1->data);
			  hold=root1;
		  }
		  else
		  {
			  hold=insert(hold1->data);
			 hold->left=prev;
			 prev->right=hold;
		  }*/
		  if(hold1->left!=NULL)
		{
			q1.push(hold1->left);
			s1.push(hold1->right->data);
		}
		if(hold1->right!=NULL)
		{
			q1.push(hold1->right);
			s1.push(hold1->left->data);
		}
	  }
	 // print(root1);
		

  }

}

int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);
	root->right->left=insert(7);
	root->right->right=insert(9);
	root->left->left->right=insert(6);
	root->right->left->right=insert(8);
	printf("the binary tree is\n");
	inorder(root);
	printf("the rev inorder of the given bst is\n");
	revlevelorder(root);
	while(s1.top>=0)
		printf("%d\n",s1.pop());
	return 0;
}

