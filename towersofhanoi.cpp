// towersofhanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define max 5
class stack
{
public:
		int top,ele;
		int a[max];
		void push(int ele)
		{
			if(top==max-1)
				printf("the stack is full\n");
			a[++top]=ele;
		}
		int pop()
		{
			if(top==-1)
				printf("stack is empty\n\n");
			else
			{
				ele=a[top];
				top--;
			}
			return ele;
		}
		void display()
		{
			if(top==-1)
				printf("the stack is empty\n");
			for(int i=0;i<=top;i++)
				printf("%d\n",a[i]);
		}
		stack()
		{
			top=-1;
		}
}sourcestack,holdstack,destinationstack;
void init()
{
	for(int i=0;i<max;i++)
		sourcestack.push(max-i);
}
void transfer()
{
	while(sourcestack.top!=0)
	{
		holdstack.push(sourcestack.pop());
	}
	destinationstack.push(sourcestack.pop());

}
void finaltransfer()
{
	while(holdstack.top!=-1)
		destinationstack.push(holdstack.pop());
}
int _tmain(int argc, _TCHAR* argv[])
{
	printf("the process started\n");
	init();
	printf("source stack elements are\n");
	sourcestack.display();
	transfer();
	printf("hold stack elements are\n");
	holdstack.display();
	printf("destination stacks are\n");
	destinationstack.display();
	finaltransfer();
	printf("the final elements in the 3 stacks are\n\n");
	printf("source stack\n");
	sourcestack.display();
	printf("hold stack\n");
	holdstack.display();
	printf("destination stack\n");
	destinationstack.display();
	return 0;
}

