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
node *root=(node *)malloc(sizeof(struct node));
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node *post(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	post(temp->left);
	post(temp->right);
	printf("%d\n",temp->data);

}
node *pre1(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	printf("%d\n",temp->data);
	pre1(temp->left);
	pre1(temp->right);
}
node *inorder(node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	pre1(temp->left);
	printf("%d\n",temp->data);
	pre1(temp->right);


}
int search(int in[],int ele)
{
	int i=0;
	while(i<6)
	{
		if(in[i]==ele)
			return i;
		i++;
	}
	return 0;
}
node *constructbintree(int pre[],int in[],int start,int end)
{
	static int i=0;
	int k=start;
	int j=end;
	node *temp=insert(pre[i++]);
	if(temp==NULL)
		return NULL;
	if(start>end)
		return NULL;
	if(start==end)
		return temp;
	int breakpoint=search(in,temp->data);
	if(breakpoint)
	{
		temp->left=constructbintree(pre,in,k,breakpoint-1);
		temp->right=constructbintree(pre,in,breakpoint+1,j);
	}
	return temp;
}
node *constructbintree1(int post[],int in[],int start,int end)
{
	static int i=end+1;
	int k=start;
	int j=end;
	if(start>end)
		return NULL;
	node *temp=insert(post[--i]);
	if(temp==NULL)
		return NULL;
	if(start==end)
		return temp;
	int breakpoint=search(in,temp->data);
	if(breakpoint)
	{
		temp->right=constructbintree1(post,in,breakpoint+1,j);
		temp->left=constructbintree1(post,in,k,breakpoint-1);
	}
	return temp;
}
int search2(int post[],int data)
{
	int i=0,n=6;
	while(i<n)
	{	
		if(post[i]==data)
			return i;
		i++;
	}
	return 0;
}
int search1(int pre[],int data)
{
	int i=0,n=6;
	while(i<n)
	{	
		if(pre[i]==data)
			return i;
		i++;
	}
	return 0;



}
node *constructbintree2(int pre[],int post[],node *root)
{
	node *temp=root;
	if(temp==NULL)
		return NULL;
	temp->left=insert(pre[search1(pre,temp->data)+1]);
	temp->right=insert(post[search2(post,temp->data)-1]);
	constructbintree2(pre,post,temp->left);
	constructbintree2(pre,post,temp->right);
	return temp;
}
int check(node *res)
{
	int count=0;
	node *temp=res;
	if(temp==NULL)
		return 0;
	if(temp->left==NULL&&temp->right==NULL)
			return 1;
	count+=check(temp->left);
	count+=check(temp->right);
	count++;
	return count;
}
int check1(node *root)
{
	static int i=0;
	node *temp=root;
	if(temp==NULL)
		return NULL;
	if(temp->left==NULL&&temp->right==NULL)
	{
		++i;
		printf("%d\n",temp->data);
	}
	check1(temp->left);
	check1(temp->right);
	return i;
}
int isvisited=0,minheight=0;
int check2(node *res,int count)
{
	node *temp=res;
	if(temp==NULL)
		return NULL;
	++count;
	if(temp->left==NULL&&temp->right==NULL)
	{
		if(isvisited==0)
		{
			minheight=count;
			isvisited=1;
		}
		else
		{
			if(minheight>count)
				minheight=count;
		}
	}
	check2(temp->left,count);
	check2(temp->right,count);
	return minheight+1;
}
int allancesters(node *res,int ele)
{
	node *temp=res;
	if(temp==NULL)
		return NULL;
	if(temp->data==ele)
	{
		printf("no ancestors from now\n");
		exit(0);
	}
	if(temp->data>ele)
	{
		printf("%d\n",temp->data);
		allancesters(temp->left,ele);
	}
	if(temp->data<ele)
	{
		printf("%d\n",temp->data);
		allancesters(temp->right,ele);
	}
}
int search3(node *res,int ele)
{
	 node *temp=res;
	 if(temp==NULL)
		 return NULL;
	 if(temp->data==ele)
		return 1;
	
	 if(temp->data<ele)
		 search3(temp->right,ele);
	   if(temp->data>ele)
		 search3(temp->left,ele);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int in[]={4,2,5,1,6,3};
	int pre[]={1,2,4,5,3,6};
	int post1[]={4,5,2,6,3,1};
	node *res;
	int ch,count,ele;
	int minheight;
	while(1)
	{
		printf("\n1.construct bst from in and pre\n2.construct bst from in and post\n3.construct bst from pre and post\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1:
				res=constructbintree(pre,in,0,5);
				printf("\nthe post order of obtained binary tree is\n");
				post(res);
				printf("the number of nodes are\n");
				count=check(res);
				printf("%d\n",count);
				break;
			case 2:
				res=constructbintree1(post1,in,0,5);
				printf("the preorder of obtained binary tree is\n");
				pre1(res);
				printf("the leaf nodes are given below\n");
				count=check1(res);
				printf("total leaf nodes are %d\n",count);
				minheight=check2(res,0);
				printf("%d\n",minheight);
				printf("enter the element\n");
				scanf("%d",&ele);
				if(search3(res,ele))
				allancesters(res,ele);
				else
					printf("enter the correct value and it must be present in the tree\n");
				break;
		}
	return 0;
}

}