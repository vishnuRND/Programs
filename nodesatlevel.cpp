// nodesatlevel.cpp : Defines the entry point for the console application.
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
	node* pop()
	{
		node * ele;
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
	int empty()
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
node *display(node *res)
{
	node *temp=res;
	if(temp==NULL)
		return NULL;
	printf("%d\n",temp->data);
	display(temp->left);
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
int levelnodes(node *root)
{
	//sstatic int level=0;
	int count=0;
	node *temp=root;
	if(temp==NULL)
		return NULL;
	q1.push(temp);
	printf("the nodes from right view are\n");
	while(!q1.empty())
	{
		int start=q1.front;
		int end=q1.rear;
		for(int i=start;i<end;i++)
		{
			node *hold=q1.pop();
			if(i==end-1)
				printf("%d\n",hold->data);
			if(hold->left!=NULL)
				q1.push(hold->left);
			if(hold->right!=NULL)
				q1.push(hold->right);
		}
		//level++;
	}
	//return count;
}
int widthlevel=0;
int maxnodes=1;
int width(node *root)
{
		static int level=0;
	int count=0;
	node *temp=root;
	if(temp==NULL)
		return NULL;
	q1.push(temp);
	while(!q1.empty()&&level<4)
	{
		int start=q1.front;
		int end=q1.rear;
		for(int i=start;i<end;i++)
		{
			node *hold=q1.pop();
			count++;
			if(hold->left!=NULL)
				q1.push(hold->left);
			if(hold->right!=NULL)
				q1.push(hold->right);
		}
		if(count>maxnodes)
			widthlevel=level;
		level++;
	}
	return widthlevel;

}
int _tmain(int argc, _TCHAR* argv[])
{
	root=insert(20);
	root->left=insert(10);
	root->right=insert(40);
	root->left->left=insert(3);
	root->left->right=insert(12);
	root->right->left=insert(35);
	root->right->right=insert(45);
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	root->left->right->left=NULL;
	root->left->right->right=NULL;
	root->right->left->left=NULL;
	root->right->left->right=NULL;
	root->right->right->left=NULL;
	root->right->right->right=NULL;
	display(root);
	//int level=width(root);
	levelnodes(root);
	//printf("no of nodes at the particular level %d are %d\n",level,count);
	return 0;
}

