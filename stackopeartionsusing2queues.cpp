// stack using twoqueues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 4
class queue
{
public:
	int front,rear;
	int arr[max];
	void push(int ele)
	{
		if(rear==max-1)
			printf("the queue is full\n");
		if(front==max-1&&rear==max-1)
		{
			front=-1;
			rear=-1;
		}
			arr[++rear]=ele;
		//front=0;
		//rear++;
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
		ele=arr[++front];
		return ele;
	}
	void display()
	{
		int i;
		if(front==rear)
			printf("the queue is empty\n");
		else
		{
		printf("the elements in the queue are\n");
		for(i=front;i<=rear;i++)
			printf("%d\n",arr[i]);
		}
	}
	queue()
	{
		front=-1;
		rear=-1;
	}
}q1,q2;
void push1(int ele)
{
	if(q1.front==-1&&q1.rear==-1)
		q1.push(ele);
	else
	{
		if(q2.rear!=-1)
			q2.push(ele);
		else
		q1.push(ele);
	}
}
void display1()
{
	if(q2.rear!=-1)
		q2.display();
	else
		q1.display();
}
int pop1()
{
	int ele;
	if(!(q1.front==q1.rear))
	{
		int start=q1.front;
		int end=q1.rear;
		for(int i=start;i<end-1;i++)
				q2.push(q1.pop());
		ele=q1.pop();
		return ele;
	}
	else
	{
		int start=q2.front;
		int end=q2.rear;
		for(int i=start;i<end-1;i++)
			q1.push(q2.pop());
		ele=q2.pop();
		return ele;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int ch,data;
	printf("now performing stack operations using queus\n");
	while(1)
	{
		printf("\n1.push\n2.pop\n3.display\n4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
				printf("enter the element wana push\n");
				scanf("%d",&data);
				push1(data);
				break;
		case 2:
				data=pop1();
				if(data!=-1)
				printf("the popped element is %d\n",data);
				break;
		case 3:
				display1();
				break;
		case 4:
				exit(0);
		default:
				printf("enter valid choice\n");
				break;
		}
	}
	return 0;
}

