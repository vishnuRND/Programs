// detandremloop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *next;
	int isvisit;
    node()
	{
       isvisit=0;

	}

};
struct node *root=(node *)malloc(sizeof(node));
struct node *tail=(node *)malloc(sizeof(node));
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
bool detect(node *root)
{
	node *temp=root;
	node *temp1=root;
	temp=temp->next;
	temp1=temp->next->next;
	while(temp1)
	{

		if(temp->data==temp1->data)
		{
           printf("loop exists and modification must be done immmediatly\n");
		  return 1;

		}
		temp=temp->next;
		temp1=temp1->next->next;
	}
	return 0;
}
bool remveloop(node *root)
{
	node *temp=root;
	node *temp1=temp->next;
	while(temp!=NULL)
	{
		if(temp->isvisit==0&&temp1->isvisit==0)
		{
			temp->isvisit=1;
		}
		else if(temp1->isvisit!=0)
		{ 
			temp->next=NULL;
		}
		temp=temp->next;
		temp1=temp1->next;

	}

 return 1;


}
node *insert(node *root,int ele)
{
	node *temp=root;
	node *newroot=createnode(ele);
	if(root->data>ele)
	{
		
		newroot->next=root;
		tail->next=newroot;
		newroot=root;

	}
	else if(tail->data<ele)
	{
		newroot->next=root;
		tail->next=newroot;
		newroot=tail;

	}
	else
	{
		if(temp->data<ele)
			temp=temp->next;
		else
		{


		}


	}


}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data,element;
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	printf("enter data\n");
    scanf("%d",&data);
	root=createnode(data);
	node *temp=root;
	node *temp1,*loopstart;
	for(int i=2;i<=n;i++)
	{
		printf("enter data\n");
		scanf("%d",&data);
		  temp1=createnode(data);
		  temp->next=temp1;
		  temp=temp1;
	}
	tail=temp;
	temp->next=root;
	/*bool value=detect(root);
	if(value)
	{
		bool res=remveloop(root);
		if(res)
		{
			printf("loop removed u can proceed\n");
			exit(0);

		}
		else
			printf("wait not yet done\n");*/


	/*}
	else
	 printf("no transformtion is required linkedlist have no loops in it\n");
	return 0;*/
	printf("enter the element you wanto insert\n");
	scanf("%d",&element);
	node *result=insert(root,element);
	print(result);
}

