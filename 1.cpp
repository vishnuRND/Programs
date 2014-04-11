// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 100;
int top=-1;
int popele;
int front=-1,rear=-1;
struct node
{
	int data;
	node *left;
	node *right;
	int noofchild;
	node()
	{
		noofchild=0;
	}

};
node *root=(node *)malloc(sizeof(struct node));
node *arr[100];
//void push(int ele)
//{
//	if(top==99)
//		printf("stack is full\n");
//	top++;
//	arr[top]=ele;
//
//}
void pushqueue(node *ele)
{
	if(rear==(max-1))
	{
		printf("queue is full\n");
	}
	else
	{
		arr[++rear];
	}


}
node * popqueue()
{
	if(rear==-1)
		printf("queue is empty\n");
	else
	{
		node *ele=arr[front++];
	}
	return ele;


}
int pop()
{
	if(top==-1)
		printf("stack is empty\n");
	popele=arr[top];
	top--;
	return popele;

}
int stack_empty()
{
	if(top==-1)
		return 1;
	else
		return 0;

}
node *insert(int data)
{
	
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
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

void displaywithchild(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return;
	printf("%d\t%d\n",temp->data,temp->noofchild);
		displaywithchild(temp->left);
		displaywithchild(temp->right);

}
node * search(node *root,int ele)
{
	node *temp=root;
	if(ele==temp->data)
		return temp;
	else if(ele<temp->data)
		search(temp->left,ele);
	else if(ele>temp->data)
	search(temp->right,ele);

}
void displaypre(node *root)
{
	push(root->data);
	while(!stack_empty())
	{
		int ele=pop();
		printf("%d\n",ele);
		node *hold=search(root,ele);
		if(hold->right!=NULL)
			push(hold->right->data);
		if(hold->left!=NULL)
		push(hold->left->data);
	}


}
int search(int in[],int ele)
{
	int i=0;
	while(i<=6)
	{
		if(in[i]==ele)
			return i;
		i++;
	}


}
//node * constructbin(int in[],int pre[],int inStart,int inEnd)
//{	
//		/*static int base=0;
//		int index;
//		if(start>end)
//			return NULL;
//		node *temp;
//		if(base==0)
//		{
//				root=insert(pre[base++]);
//				temp=root;
//		}
//		else
//		{
//				temp=insert(pre[base++]);
//		}
//		index=search(in,temp->data);
//		temp->left=constructbin(in,pre,start,index-1);
//		temp->right=constructbin(in,pre,index+1,end);
//		return root*/;
//static int preIndex = 0;
// 
//  if(inStart > inEnd)
//     return NULL;
// 
//  /* Pick current node from Preorder traversal using preIndex
//    and increment preIndex */
//  struct node *tNode = insert(pre[preIndex++]);
// 
//  /* If this node has no children then return */
//  if(inStart == inEnd)
//    return tNode;
// 
//  /* Else find the index of this node in Inorder traversal */
//  int inIndex = search(in,tNode->data);
// 
//  /* Using index in Inorder traversal, construct left and
//     right subtress */
//  tNode->left = constructbin(in, pre, inStart, inIndex-1);
//  tNode->right = constructbin(in, pre, inIndex+1, inEnd);
// 
//  return tNode;
//
//}
//node * post(node *root)
//{
//node *temp=root;
//if(temp==NULL)
//  return NULL;
//  post(temp->left);
//	post(temp->right);
//printf("%d\n",temp->data);
//
//}
void diffneg(node *temp,int diff)
{
	if(temp->left!=NULL)
	{
		temp->left->data=temp->left->data+diff;
		diffneg(temp->left,diff);
	}
	if(temp->right!=NULL)
	{
		temp->right->data=temp->right->data+diff;
		diffneg(temp->right,diff);
	}


}
node *change(node *root)
{
	node *temp=root;
	int left,right;
	int diff;
	if(temp==NULL||temp->left==NULL||temp->right==NULL)
		return NULL;
	change(temp->left);
	change(temp->right);
	if(temp->left!=NULL)
		left=temp->left->data;
	if(temp->right!=NULL)
		right=temp->right->data;
	if(diff>0)
	{
		diff=(left+right)-temp->data;
		temp->data=temp->data+diff;
	}
	else
	{
			diffneg(temp,-diff);

	}

	return root;
}
int isempty_q()
{
	if(front==-1&&rear==-1)
		return 1;
	else
		return 0;

}
node * noofchild(node* root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	noofchild(temp->left);
	noofchild(temp->right);
	if(temp->left==NULL&&temp->right==NULL)
		temp->noofchild=0;
	if(temp->left!=NULL&&temp->right!=NULL)
		temp->noofchild=temp->left->noofchild+2+temp->right->noofchild;
	if(temp->right!=NULL&&temp->left==NULL)
		temp->noofchild=temp->right->noofchild+1;
	if(temp->left!=NULL&&temp->right==NULL)
		temp->noofchild=temp->left->noofchild+1;

	return root;
}
void levelorder(node *root)
{
  node *temp=root;
  pushqueue(root)
  while(!isempty_q)
  {
		node *hold=pop();
		printf("%d\n",hold->data);
		pushqueue(hold->left);
		pushqueue(hold->right);
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
	/*int pre[]={20,10,3,12,40,35,50};
	int in[]={3,10,12,20,35,40,50};
	constructbin(in,pre,0,6);*/
	/*printf("the postorder is\n");
	post(root);*/
	/*printf("\n modified tree is\n");
	node *res=change(root);
	display(res);*/
	printf("nodeval\tnoofchild\n");
	printf("---------------------------\n");
	noofchild(root);
	displaywithchild(root);
	printf("the level ordering of the given bst is\n");
	levelorder(root);
	return 0;
}

