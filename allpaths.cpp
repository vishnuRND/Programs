// allpaths.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 10
int front,rear;
struct node
{
	int data;
	node *left;
	node *right;

}*arr[max];
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
		if(front==rear)
		{
			printf("the queue is empty\n");
			return NULL;
		}
		if(front==max-1&&rear==max-1)
		{
			front=-1;
			rear=-1;
		}
	   ele=arr[front++];
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


node *root=(node *)malloc(sizeof(struct node));
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node *display(node *res)
{
	node *temp=res;
	if(temp==NULL)
		return NULL;
	printf("%d\n",temp->data);
	display(temp->left);
	display(temp->right);
	return temp;
}
void print(int a[],int end)
{
	for(int i=0;i<=end;i++)
		printf("%d\t",a[i]);
}
int path(int a[],node *temp,int i)
{
	if(temp==NULL)
		return NULL;
	a[i]=temp->data;
	if(temp->left==NULL&&temp->right==NULL)
	{
		print(a,i);
		printf("\n");
		return NULL;
	}
	path(a,temp->left,i+1);
	path(a,temp->right,i+1);
	return 1;
}
node *search(node *temp,int data)
{
	node *res=NULL;
	if(temp==NULL)
		return NULL;
	if(temp->data==data)
		return temp;
	if(temp->data>data)
		res=search(temp->left,data);
	if(temp->data<data)
		res=search(temp->right,data);
	return res;
}
node *lca(node *temp,node *temp1,node *temp2)
{
	if(temp==NULL)
		return NULL;
	if((temp->data>temp1->data&&temp->data<temp2->data)||(temp->data<temp1->data&&temp->data>temp2->data))
	{
		printf("the least common ancestor is %d\n",temp->data);
		exit(0);
	}
	if((temp->data>temp1->data&&temp->data>temp2->data)||(temp->data>temp1->data&&temp->data>temp2->data))
	{
		if((temp1->data>temp2->data))
		{
			printf("no common ancestor between the nodes as %d is ancestor of %d\n",temp1->data,temp2->data);
			exit(0);
		}
		else
		{
			printf("no common ancestor between the nodes %d is ancestor of %d\n",temp2->data,temp1->data);
			exit(0);

		}
	}
	lca(temp->left,temp1,temp2);
	lca(temp->right,temp1,temp2);
	return temp;
}
int level(node *temp)
{
	if(temp==NULL)
		return NULL;
	push(temp);
	while(front!=rear)
	{
		node *data=pop();
		printf("%d\n",data->data);
		push(data->left);
		push(data->right);
	}
	return 1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(40);
	root->left=insert(20);
	root->right=insert(45);
	root->left->left=insert(10);
	root->left->right=insert(25);
	root->right->left=insert(41);
	root->right->right=insert(50);
	root->left->left->left=insert(8);
	root->left->left->right=NULL;
	root->left->right->left=NULL;
	root->left->right->right=NULL;
	root->right->left->left=NULL;
	root->right->left->right=NULL;
	root->right->right->left=NULL;
	printf("PREORDER\n");
	display(root);
	//int max=height(root,0);
	int a[10];
	printf("the paths in the given bst are\n");
	path(a,root,0);
	int data1,data2;
	printf("enter the two valued of data\n");
	scanf("%d,%d",&data1,&data2);
	node *temp1=search(root,data1);
	node *temp2=search(root,data2);
	lca(root,temp1,temp2);
	level(root);
	return 0;
}

