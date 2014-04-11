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

node *pre1(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	printf("%d\n",temp->data);
	pre1(temp->left);
	pre1(temp->right);
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
			for(int i=0;i<=s1.top;i++)
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
			for(int i=0;i<=s2.top;i++)
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
	root->left->left->right=insert(8);
	root->right->right->left=insert(43);
	root->right->right->right=NULL;
	printf("the inorder traversal of the binary tree is\n");
	pre1(root);
	printf("the zigzag traversal of the binary tree is\n");
	zigzag(root);
	return 0;
}

