// ZIGZAG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 10
struct node
{
	int data;
	node *left;
	node *right;
};
class stack
{
public:
		int top;
		node *ele;
		node* a[max];
		void push(node *ele)
		{
			if(top==max-1)
				printf("the stack is full\n");
			a[++top]=ele;
		}
		node * pop()
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
				printf("%d\n",a[i]->data);
		}
		stack()
		{
			top=-1;
		}
}s1,s2;
node *root=(node *)malloc(sizeof(struct node));
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node *in(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	printf("%d\n",temp->data);
	in(temp->left);
	in(temp->right);
}
void zigzag(node *root)
{
	int performed=0;
	node *temp=root;
	s1.push(temp);
	while(!(s1.top==-1&&s2.top==-1))
	{
		if(s1.top!=-1&&performed==0)
		{
			int end=s1.top;
			for(int i=0;i<=end;i++)
			{	
				node* hold=s1.pop();
				printf("%d\n",hold->data);
				if(hold->left!=NULL)
					s2.push(hold->left);
				if(hold->right!=NULL)
					s2.push(hold->right);
			}
			performed=1;
		}
		if(s2.top!=-1&&performed==0)
		{
			int end=s2.top;
			for(int i=0;i<=end;i++)
			{	
				node* hold=s2.pop();
				printf("%d\n",hold->data);
				if(hold->left!=NULL)
					s1.push(hold->left);
				if(hold->right!=NULL)
					s1.push(hold->right);
			}
			performed=1;
		}
		
	performed=0;
	}

}
int balance(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	int h_left=1+balance(temp->left);
	int h_right=1+balance(temp->right);
	int k=h_left-h_right;
	if(k>1||k<-1)
	{
		printf("the tree is not balanced\n");
		exit(0);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(20);
	root->left=insert(13);
	root->right=insert(40);
	root->left->left=insert(3);
	root->left->right=NULL;
	root->right->left=NULL;
	root->right->right=insert(45);
	root->left->left->left=NULL;
	//root->left->left->right=insert(8);
	root->right->right->left=insert(43);
	root->right->right->right=NULL;
	printf("the inorder traversal of the binary tree is\n");
	in(root);
	balance(root);
	printf("the tree is balanced\n");
	//zigzag(root);
	return 0;
}

