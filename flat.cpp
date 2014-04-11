// flat.cpp : Defines the entry point for the console application.
//

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
		printf("the download links of %d are\n",temp->data);
		while(temp1!=NULL)
		{
			printf("%d\n",temp1->data);
			temp1=temp1->down;

		}

		temp=temp->left;
	}



}
void printflat(node *root)
{
	node *tmp=root;
	while(tmp!=NULL)
	{
		printf("->%d",tmp->data);
		tmp=tmp->left;

	}
	printf("\n");

}
void flat(node *root)
{
	node *temp=root;
	while(temp!=NULL)
	{
		node *next=temp->left;
		temp->left=NULL;
		node *temp3=temp;
		while(temp3!=NULL)
		{
			node *down=temp3->down;
			temp3->down=NULL;
			node *temp4=root;
			if(temp4->left==NULL&&temp4->data<temp3->data)
					temp4->left=temp3;
			while(temp4->left!=NULL)
			{
				if(temp3->data==temp4->data)
					break;
				if(temp4->data<temp3->data&&temp4->left->data>temp3->data)
				{
					node *next1=temp4->left;
					temp4->left=temp3;
					temp3->left=next1;

				}
				if(temp4->left->left==NULL&&temp4->left->data<temp3->data)
					temp4->left->left=temp3;
				temp4=temp4->left;
			}
			temp3=down;
		}
		temp=next;
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
	node *temp3=root;
	node *temp1=temp3;
	printf("enter no of down links of %d in main channel\n",temp3->data);
	scanf("%d",&down1);
	for(int i=0;i<down1;i++)
		{
			printf("enter data part\n");
			scanf("%d",&data);
			node *temp2=insert(data);
			temp1->down=temp2;
			temp1=temp2;
		}
	for(int i=0;i<main-1;i++)
	{
		printf("enter data part of next channel\n");
		scanf("%d",&data);
		node *temp=insert(data);
		temp3->left=temp;
		temp3=temp;
		printf("enter no of down links of %d in main channel\n",temp3->data);
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
	}
	print(root);
	flat(root);
	printf("\nthe flattend list is \n");
	printflat(root);
	return 0;
}



