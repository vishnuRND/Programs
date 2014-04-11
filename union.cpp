// IntersectionAndUnion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
struct node
{
	int value;
	struct node* next;
};

node* insert(struct node* head,int value)
{
	struct node *newnode=(node*)malloc(sizeof(node));
	newnode->value=value;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	return head;
}
void display(node* head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->value);
		temp=temp->next;
	}
	printf("NULL\n");
}

node* Sort(node* head)
{
	//struct node *temp=head;
	
	int i=0;
	while(i<=6)
	{
		node *temp2=head;
		node *temp1=head->next;
		while(temp1 != NULL)
		{
		if(temp1->value<temp2->value)
		{
			int t;
			t=temp2->value;
			temp2->value=temp1->value;
			temp1->value=t;
		}
		temp1=temp1->next;
		temp2=temp2->next;
		}
		i++;
	}
	return head;
}



node * Union(node* head1,node* head2)
{
	struct node* temp1=head1;
	struct node* temp2=head2;
	struct node *headu=NULL;
	while(temp1!= NULL && temp2 != NULL)
	{
		if(temp2->value > temp1->value)
		{
			headu=insert(headu,temp1->value);
			headu=insert(headu,temp2->value);
		}
		else if(temp2->value < temp1->value)
		{
			headu=insert(headu,temp2->value);
			headu=insert(headu,temp1->value);
		}
		else
		{
			headu=insert(headu,temp2->value);
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	if(temp1!=NULL)
	{
		while(temp1 != NULL)
		{
			headu=insert(headu,temp1->value);

			temp1=temp1->next;
		}
	}
	if(temp2!=NULL)
	{
		while(temp2 != NULL)
		{
			headu=insert(headu,temp2->value);

			temp2=temp2->next;
		}
	}
	return headu;
}

node* intersection(node *head1,node *head2)
{
	struct node *temp=head1;
	struct node *temp1=head2;
	struct node *headint=NULL;
	struct node* prev=NULL;
	node *next=NULL;
	while(temp!=NULL)
	{
		
		if(temp->value!=temp1->value)
		{
			if(headint==NULL)
			{
				headint=temp;
				next=temp->next;
				headint->next=temp1;
				prev=temp1;
			}
			else
			{
				prev->next=temp;
				prev=temp;
				next=temp->next;
				prev->next=temp1;
				prev=temp1;
			}
			temp=next;
			temp1=temp1->next;

		}
		else
		{
			temp=temp->next;
			temp1=temp1->next;
		}
		
	}
	return headint;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head1=NULL,*head2=NULL,*headu=NULL,*headint=NULL;
	int a1[6]={1,3,4,6,8,42};
	int a2[6]={22,12,3,6,4,1};
	for(int i=0;i<6;i++)
	{
		head1=insert(head1,a1[i]);
	}
	for(int i=0;i<6;i++)
	{
		head2=insert(head2,a2[i]);
	}
	display(head1);
	display(head2);
	head1=Sort(head1);
	head2=Sort(head2);
	display(head1);
	display(head2);
	headu=Union(head1,head2);
	headint=intersection(head1,head2);
	display(headu);
	display(headint);
	return 0;
}

