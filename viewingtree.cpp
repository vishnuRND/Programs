// level.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 100
int top=-1;
int popele;
int front=-1,rear=-1;
struct node
{
	int data;
	node *left;
	node *right;
};
node *root=(node *)malloc(sizeof(struct node));
node *arr[10];
void pushqueue(node *ele)
{
	if(rear==max-1)
	{
		printf("queue is full\n");
	}
	arr[++rear]=ele;
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
int isempty_q()
{
	if(front==-1&&rear==-1)
		return 1;
	else
		return 0;

}
void display(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return;
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
void levelorder(node *root)
{
  node *temp=root;
  pushqueue(temp);
  while(!isempty_q())
  {
		node *hold=popqueue();
		if(hold!=NULL)
		{
 			printf("%d\n",hold->data);
			if(hold->left!=NULL)
			pushqueue(hold->left);
			if(hold->right!=NULL)
			pushqueue(hold->right);
		}

  }

}
int outlevel(node *root,int key)
{
	static int level=0;
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->data==key)
		return level;
	else if(temp->data>key)
	{	
		level++;
		outlevel(temp->left,key);
	}
	else if(temp->data<key)
	{
		level++;
		outlevel(temp->right,key);
	}
}
int distancenodes(node *root,int distance,int level)
{
	int level1=level;
	int level2=level;
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(level==distance)
		printf("%d\n",temp->data);
	distancenodes(temp->left,distance,++level1);
	distancenodes(temp->right,distance,++level2);
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

	//root->left->left->left=NULL;
	//root->left->left->right=NULL;
	///*root->left->right->left=NULL;*/
	//root->left->right->right=insert(8);
	///*root->right->left->left=NULL;*/
	//printf("the preorder is\n");
	///*root->right->left->right=NULL;*/
	//root->right->right->left=insert(43);
	///*root->right->right->right=NULL;*/
	display(root);
	//printf("the level ordering of the given bst is\n");
	//levelorder(root);
	int key,distance;
	printf("enter the key\n");
	scanf("%d",&key);
	int level=outlevel(root,key);
	printf("the node with data %d is present at %d level\n",key,level);
	printf("enter the distance\n");
	scanf("%d",&distance);
	distancenodes(root,distance,0);
	return 0;
}

