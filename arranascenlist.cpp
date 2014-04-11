// arranascenlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
 struct node
 {
	 int data;
	 node *next;
	 int isvisited;
	 node()
	 {
		 isvisited=0;

	 }

 }*str[3];
 struct node *root=(node *)malloc(sizeof(node));
node *createnode(int data)
{
	node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
node *sort(node *dum)
{
	node *temp=dum;
	int i=0;
	while(temp!=NULL)
	{
		if(temp->isvisited==0)
		{
			str[i]=temp;
			i++;

		}
		else
		{
              if(temp->data>



		}



	}

temp=temp->next;



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
int _tmain(int argc, _TCHAR* argv[])
{
	int n,data;
	printf("enter no of nodes in linked list\n");
	scanf("%d",&n);
	printf("enter data part of linked list\n");
	scanf("%d",&data);
	root->data=data;
	root->next=NULL;
	node *temp=root;
	node *temp1;
	for(int i=1;i<n;i++)
	{
		printf("enter data part of linked list\n");
		scanf("%d",&data);
		temp1=createnode(data);
		temp->next=temp1;
		temp=temp1;
	}
	print(root);
	node *res=sort(root);
     print(res);

 
}

