#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insert(void);
void display(void);
int main()
{
	int option,val;
	do
	{
		printf("1.insert an element\n");
		printf("2.display the element\n");
		printf("3.EXIT");
		printf("enter your option \n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
				
		}
		
	}while(option!=5);
	getch();
	return 0;
	
}
void insert()
{
	int num;
	printf("enter the number to be inserted\n");
	scanf("%d",&num);
	if (front==0 && rear==MAX-1)
			printf("OVERFLOW");
	else if (front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=num;
		
		
	}
	else if(rear=MAX-1 && front!=0)
	{
		rear=0;
		queue[rear]=num;
	}
	else
	{
		rear++;
		queue[rear]=num;
	}
}
void display()
{
	int i;
	printf("\n");
	if(front==-1 && rear==-1)
	 	printf("queue is empty\n");
	else
	{
		if (front<rear)
		{
			for(i=front;i<=rear;i++)
				printf("%d",queue[i]);
				
		}
		else
		{
			for(i=front;i<MAX;i++)
				printf("%d",queue[i]);
			for(i=0;i<rear;i++)
				printf("%d",queue[i]);
		}
	}
	
}
