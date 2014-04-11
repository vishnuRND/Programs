// flatenninglinkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *left;
	node *down;
};
node *root=(node *)malloc(sizeof(struct node));
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->down=NULL;
	return temp;
}
void print(node *root)
{
	node *temp=root;
	while(temp!=NULL)
	{
		printf("%d->\n",temp->data);
		node *temp1=temp->down;
		while(temp1!=NULL)
		{
			printf("%d\n",temp1->data);
			temp1=temp1->down;

		}

		temp=temp->left;
	}



}
int _tmain(int argc, _TCHAR* argv[])
{
	int main,down1,data;
	printf("enter number of nodes on main channel\n");
	scanf("%d",&main);
	printf("enter data part\n");
	scanf("%d",&data);
	root->data=data;
	root->left=NULL;
	root->down=NULL;
	for(int i=0;i<main-1;i++)
	{
		node *temp3=root;
		printf("enter no of down links of eacn node in main channel\n");
		scanf("%d",&down1);
		node *temp1=temp3;
		for(int i=0;i<down1;i++)
		{
			printf("enter data part\n");
			scanf("%d",&data);
			node *temp2=insert(data);
			temp1->down=temp2;
			temp1=temp2;
		}
		printf("enter data part of next channel\n");
		scanf("%d",&data);
		node *temp=insert(data);
		temp3->left=temp;
		temp3=temp;
	}
	print(root);
	return 0;
}

