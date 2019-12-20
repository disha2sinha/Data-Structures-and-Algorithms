#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 5
int cqueue[MAXSIZE],front=-1,rear=-1;
void qinsert(void);
void qdelete(void);
void qdisplay(void);
void main()
{
	int choice;
	while(1)
	{
		printf ("\nCIRCULAR QUEUE: \n 1. INSERT\n 2. DELETE\n 3. DISPLAY\n 4. EXIT\n");
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
	if ((front==0 && rear==MAXSIZE-1)||(front==rear+1))
	{
		printf ("\n CIRCULAR QUEUE OVERFLOW\n");
	}
	else
	{
		printf("\n ENTER ITEM: \n");
		scanf("%d",&item);
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		else if(rear==MAXSIZE-1)
		{
			rear=0;
		}
		else
		{
			rear=rear+1;
		}
		cqueue[rear]=item;
	}
}
void qdelete()
{
	int unit;
	if (front==-1)
	{
		printf ("\n CIRCULAR QUEUE UNDERFLOW\n");
	}
	else
	{
		unit=cqueue[front];
		printf("\n %d IS DELETED\n",unit);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(front==MAXSIZE-1)
		{
			front=0;
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
		printf("\nCIRCULAR QUEUE EMPTY\n");	
	}
	else
	{
		printf("\nCIRCULAR QUEUE:\n");
		if (front<=rear)
		{
			for(i=0;i<=front-1;i++)
			{
				printf("\n * \n");
			}
			for(i=front;i<=rear;i++)
			{
				printf ("\n %d \n",cqueue[i]);		
			}
			for(i=rear+1;i<=MAXSIZE-1;i++)
			{
				printf("\n * \n");	
			}
		}
		else
		{
			for(i=0;i<=rear;i++)
			{
				printf("\n %d \n",cqueue[i]);
			}
			for(i=rear+1;i<=front-1;i++)
			{
				printf ("\n * \n");		
			}
			for(i=front;i<=MAXSIZE-1;i++)
			{
				printf("\n %d \n",cqueue[i]);	
			}
			
		}
	}	
}
