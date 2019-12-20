#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 5
int queue[MAXSIZE],front=-1,rear=-1;
void qinsert(void);
void qdelete(void);
void qdisplay(void);
void main()
{
	int choice;
	while(1)
	{
		printf ("\n QUEUE: \n 1. INSERT\n 2. DELETE\n 3. DISPLAY\n 4. EXIT\n");
		printf ("\nENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: qinsert();
					break;
			case 2: qdelete();
					break;
			case 3: qdisplay();
					break;
			case 4: exit(0);
					break;
			default: printf("\n YOU HAVE ENTERED A WRONG CHOICE\n");		
		}	
	}
}
void qinsert()
{
	int item;
	if (rear==MAXSIZE-1)
	{
		printf ("\n QUEUE OVERFLOW\n");
	}
	else
	{
		printf("\n ENTER ITEM: \n");
		scanf("%d",&item);
		rear=rear+1;
		queue[rear]=item;
		if(front==-1)
		{
			front=0;
		}
	}
}
void qdelete()
{
	int unit;
	if (front==-1)
	{
		printf ("\nQUEUE UNDERFLOW\n");
	}
	else
	{
		unit=queue[front];
		printf("\n %d IS DELETED\n",unit);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=front+1;
		}
	}
}
void qdisplay()
{
	int i;
	if (front==-1)
	{
		printf("\nQUEUE EMPTY\n");	
	}
	else
	{
		printf("\nQUEUE:\n");
		for(i=0;i<=front-1;i++)
		{
			printf("\n * \n");
		}
		for(i=front;i<=rear;i++)
		{
			printf ("\n %d \n",queue[i]);		
		}
		for(i=rear+1;i<=MAXSIZE-1;i++)
		{
			printf("\n * \n");	
		}	
	}	
}
