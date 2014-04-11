// constructbst(in and pre).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
struct node
{
	int data;
	node *left;
	node *right;
};
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void post(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return
	post(temp->left);
	post(temp->right);
	printf("%d\n",temp->data);

}
int search(int in[],int ele,int start,int end)
{
	while(start<=end)
	{
		if(in[start]==ele)
			return start;
		start++;
	}
	return 0;
}
node *constructbintree(int pre[],int in[],int start,int end)
{
	int i=start;
	int j=end;
	node *temp=pre[start++];
	if(temp==NULL)
		return NULL;
	if(start<end)
		return NULL;
	int breakpoint=search(in,temp->data,i,j);
	if(break)
	{
		temp->left=(pre,in,start,breakpoint-1);
		temp->right=(pre,in,breakpoint+1,end);
	}
	return temp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int pre[]={68,21,93,26,35};
	int in[]={35,26,93,21,68};
	int ch;
	while(1)
	{
		printf("\n1.construct bst from in and pre\n2.construct bst from in and post\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1:
				node *res=constructbintree(pre,in,0,4);
				post(res);
				break;
			case 2:
				//constructbintree1(post,in);
				break;

		}
	return 0;
}

