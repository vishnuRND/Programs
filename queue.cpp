// queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 10
int arr[max];
int front=-1,rear=-1;
void push(int ele)
{
	if(rear==max-1)
		printf("the queue is full\n");
		arr[rear]=ele;
	rear++;

}
int pop()
{
	int ele;
	if(front==max-1||(front==-1&&rear==-1))
	{
		printf("the queue is empty\n");
		return -1;
	}
	if(front==max-1&&rear==max-1)
	{
		front=-1;
		rear=-1;
	}
	ele=arr[front++];
	return ele;
}
void display()
{
	int i;
	printf("the elements in the queue are\n");
	for(i=front;i<rear;i++)
		printf("%d\n",arr[i]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	while(1)
	{	
		int ch,data;
		printf("\n\n1.pushele\n2.popele\n3.display\n4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			    printf("enter element\n");
				scanf("%d",&data);
				push(data);
				break;
		case 2:
				data=pop();
				if(data!=-1)
				printf("the element is %d",data);
				break;
		case 3:
				display();
				break;
		case 4:
				exit(0);

		}


	}
	return 0;
}

