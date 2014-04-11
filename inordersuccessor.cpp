// inordersuccessor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 20
struct node
{
	int data;
	node *left;
	node *right;
	//node *parent;
};
node *root=(node *)malloc(sizeof(struct node));
node *a[max];
int top=-1;node *ele;
		//int a[max];
		void push(node *ele)
		{
			if(top==max-1)
				printf("the stack is full\n");
			a[++top]=ele;
		}
		node *pop()
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
void display(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return;
		display(temp->left);
		printf("%d\n",temp->data);
		display(temp->right);

}
node *insert(int data)
{
	
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
//node *inordersuccessor(node *root1)
//{
//	node *temp=root1;
//	if(temp==NULL)
//		return NULL;
//	if(temp->right==NULL)
//	{
//		//while(!temp->isvisited==0)
//		temp=temp->parent;
//		return temp;
//
//	}
//	else
//	{
//		if(temp->right->left==NULL)
//			return temp->right;
//		else
//		{
//			temp=temp->right;
//			while(temp->left!=NULL)
//			{
//				temp=temp->left;
//			}
//			return temp;
//		}
//	}
//
//
//
//}
node *search(node *root,int key)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->data==key)
		return temp;
	else if(temp->data>key)
	{
		push(temp);
		search(temp->left,key);
	}
	else if(temp->data<key)
	{
		push(temp);
		search(temp->right,key);
	}
}
node * call(node *temp)
{
	node *res=pop();
	int data=temp->data;
	while(!(temp->right->data!=data))
	{
		data=temp->data;
		temp=pop();
	}
	return temp;
}
node *inordersuccessorwithoutparent(node *temp)
{
	node *temp1=root;
	node *res=NULL;
	if(temp==NULL||temp1==NULL)
		return NULL;
	if(temp->right!=NULL)
		res=temp->right;
	else
		res=call(temp);
	return res;
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
	/*root->left->left->right->parent=root->left->left;
	root->left->left->parent=root->left;
	root->left->parent=root;
	root->right->parent=root;
	root->right->right->left->parent=root->right->right;
	root->right->right->parent=root->right;*/
	root->right->right->right=NULL;
	root->right->left=insert(35);
	root->right->left->left=insert(30);
	printf("the inorder traversal of the given tree is\n");
	display(root);
	int key;
	printf("enter the node value\n");
	scanf("%d",&key);
	node *temp=search(root,key);
	node *next=inordersuccessorwithoutparent(temp);
	printf("%d",next->data);
	return 0;
}

