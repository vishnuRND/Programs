// queueusing2stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define max 10
int lastoperpush=0;
int lastoperpop=0;
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
				printf("stack is empty\n");
			else
			{
				ele=a[top];
				top--;
			}
			return ele;
		}
		void display()
		{
			for(int i=0;i<=top;i++)
				printf("%d\n",a[i]);
		}
		stack()
		{
			top=-1;
		}
}s1,s2;
void push(int ele)
{
	if(s1.top!=-1)
	{
		if(lastoperpush==1)
		{
			s1.push(ele);
		}
		else
		{
			for(int i=0;i<=s1.top;i++)
				s2.push(s1.pop());
			s2.push(ele);
		}

	}
	else
	{
		if(lastoperpush==1)
		{
			s2.push(ele);
		}
		else
		{
			for(int i=0;i<=s2.top;i++)
				s1.push(s2.pop());
			s1.push(ele);
		}
	}
}
void pop()
{
	int ele,end;
  if(s1.top!=-1)
  {
	  if(lastoperpush==1)
	  {
		 end=s1.top;
		 for(int i=0;i<=end;i++)
		 {
			ele=s1.pop();
			  s2.push(ele);

		}
		 ele=s2.pop();
	  }
	  ele=s1.pop();
	  printf("the popped out element is %d\n",ele);
  }
  else if(s2.top!=-1)
  {
	  if(lastoperpush==1)
	  {
	  end=s2.top;
	  for(int i=0;i<=end;i++)
	  {
		  s1.push(s2.pop());

	  }
	  ele=s1.pop();
	  }
	  else
		  ele=s2.pop();
	printf("the popped out element is %d\n",ele);
  }
  else
  {
		printf("the stack is empty\n");
  }

}
void display()
{
	if(s1.top!=-1)
		s1.display();
	else
		s2.display();
}
int _tmain(int argc, _TCHAR* argv[])
{
	int ch,data;
	while(1)
	{
		printf("\n1.push\n2.pop\n3.display\n4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
	switch(ch)
		{

		case 1:
				printf("enter data\n");
				scanf("%d",&data);
				push(data);
				lastoperpush=1;
				lastoperpop=0;
				break;
		case 2:
				pop();
				lastoperpush=0;
				lastoperpop=1;
				break;
		case 3:
				display();
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

