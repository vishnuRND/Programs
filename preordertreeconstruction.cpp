// preordertreeconstruction.cpp : Defines the entry point for the console application.
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
int displayin(node *temp)
{
	if(temp==NULL)
		return NULL;
	displayin(temp->left);
	printf("%d\n",temp->data);
	displayin(temp->right);
}
node *insert(int data)
{
	node *temp=(node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int getindex(int pre[],int start,int end)
{
	int i=start;
	int j=start+1;
	while(j<end)
	{
		if(pre[i]<pre[j])
			return j;
		j++;
	}
	return j-1;

}
node * constructtree(int pre[],int start,int end)
{
	if(start>end)
		return NULL;
	int index=getindex(pre,start,end);
	node *temp=insert(pre[start++]);
	if(temp==NULL)
		return NULL;
	if(start==end)
		return temp;
	//start++;
	temp->left=constructtree(pre,start,index);
	temp->right=constructtree(pre,index+1,end);
	return temp;

}
int path(node *temp,int total,int sum)
{
	//static int total=0;
	if(temp==NULL)
		return NULL;
	total+=temp->data;
	if(temp->left==NULL&&temp->right==NULL)
	{
		if(total==sum)
		{
			printf("the path exists between %d and%d\n",root->data,temp->data);
			exit(0);
		}
	}
	path(temp->left,total,sum);
	path(temp->right,total,sum);


}
int number(node *temp)
{
	static int count=0;
	if(temp==NULL)
		return NULL;
	count++;
	number(temp->left);
	number(temp->right);
	return count;
}
int delete1(node *temp)
{
	if(temp==NULL)
		return NULL;
	delete1(temp->left);
	delete1(temp->right);
	free(temp);
}
node *mirror(node *temp)
{
	if(temp==NULL||(temp->left==NULL&&temp->right==NULL))
		return NULL;
	mirror(temp->left);
	mirror(temp->right);
	node *hold=temp->left;
	temp->left=temp->right;
	temp->right=hold;



}
int maxheight=0;
int height(node *temp,int height1)
{

	if(temp==NULL)
		return NULL;
	height1++;
	if(temp->left==NULL&temp->right==NULL)
	{
		if(maxheight==0)
			maxheight=height1;
		else
		{
			if(maxheight<height1)
				maxheight=height1;
		}
	return NULL;
	}
	height(temp->left,height1);
	height(temp->right,height1);
	return maxheight;
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*int pre[]={20,10,11,12,13};
	root=constructtree(pre,0,5);*/
	root=insert(40);
	root->left=insert(20);
	root->right=insert(45);
	root->left->left=insert(10);
	root->left->right=insert(25);
	root->right->left=insert(41);
	root->right->right=insert(50);
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	root->left->right->left=insert(8);
	root->left->right->right=NULL;
	root->right->left->left=NULL;
	root->right->left->right=NULL;
	root->right->right->left=insert(47);
	root->right->right->left->left=insert(48);
	displayin(root);
	//int sum;
	//printf("enter the value of sum\n");
	//scanf("%d",&sum);
	//path(root,0,sum);
	//printf("no such path exists\n");
	int count=number(root);
	printf("the size of the tree is %d\n",count);
	//delete1(root);
	mirror(root);
	displayin(root);
	//remirroriing;
	printf("reverse mirroring\n");
	mirror(root);
	displayin(root);
	int max=height(root,0);
	printf("the height of the tree is %d\n",max);
	return 0;
}

