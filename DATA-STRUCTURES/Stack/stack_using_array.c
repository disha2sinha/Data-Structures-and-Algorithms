#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 5
int stack[MAXSIZE],top=-1;
void push(void);
void pop(void);
void peep(void);
void main()
{
	int choice;
	while(1)
	{
		printf ("\n STACK: \n 1. PUSH\n 2. POP\n 3. PEEP\n 4. EXIT\n");
		printf ("\nENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: peep();
					break;
			case 4: exit(0);
					break;
			default: printf("\n YOU HAVE ENTERED A WRONG CHOICE\n");		
		}	
	}
}
void push()
{
	int item;
	if (top==MAXSIZE-1)
	{
		printf ("\n STACK OVERFLOW\n");
	}
	else
	{
		printf("\n ENTER ITEM: \n");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
	}
}
void pop()
{
	int unit;
	if (top==-1)
	{
		printf ("\nSTACK UNDERFLOW\n");
	}
	else
	{
		unit=stack[top];
		printf("\n %d IS DELETED\n",unit);
		top=top-1;
	}
}
void peep()
{
	int i;
	if (top==-1)
	{
		printf("\nSTACK EMPTY\n");	
	}
	else
	{
		printf("\nSTACK:\n");
		for(i=top;i>=0;i--)
		{
			printf ("\n %d \n",stack[i]);		
		}	
	}	
}
