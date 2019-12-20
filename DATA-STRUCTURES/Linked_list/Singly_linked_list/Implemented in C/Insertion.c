#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int item;
void insert_beginning(void);
void insert_end(void);
void insert_location();
void insert_after_value();
void display(void);
struct node
{
	int data;
	struct node* next;

};
struct node *start;
struct node*tail=NULL;
void main()
{
	int choice;
	while(1)
	{
		printf ("\n LINKED LIST: \n 1. INSERT AT THE BEGINNING\n 2. INSERT AT THE END\n 3. INSERT AT A GIVEN LOCATION\n 4. INSERT AFTER A GIVEN VALUE\n 5. DISPLAY\n 6. EXIT\n\n");
		printf ("\nENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_beginning();
				break;
			case 2:insert_end();
				break;
			case 3:insert_location();
				break;
			case 4:insert_after_value();
				break;
			case 5:display();
				break;
			case 6:exit(0);
				break;
			default: printf("\n YOU HAVE ENTERED A WRONG CHOICE\n");
		}
	}
}
void insert_beginning()
{
	struct node *p= start,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER ITEM:\n");
	scanf("%d",&item);
	temp->data= item;
	temp->next= start;
	start=temp;
}
void insert_end()
{
	struct node *p= start, *temp;
	
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER ITEM:\n");
	scanf("%d",&item);
	temp->data=item;
	if (start == NULL)
	{
		start=temp;
		temp->next = NULL;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->next=NULL;
	}
}
void insert_location()
{
	struct node *p=start, *temp;
	int loc,i;
	printf("\nENTER LOCATION\n ");
	scanf("%d",&loc);
	if (loc<1)
	{
		printf("Invalid Location entered\n");
		return;
	}
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER ITEM:\n");
	scanf("%d",&item);
	temp->data= item;
	if (loc==1)
	{
		temp->next=p;
		start=temp;
	}
	else
	{
	
		for(i=1;i<loc-1;i++)
		{
			p=p->next;
		
			if(p==NULL)
			{
				printf("NO SUCH LOCATION\n");
				free(p);
				return;
			}
		}

		struct node *location=p->next;
		p->next=temp;
		temp->next=location;
	}
	
}
void insert_after_value()
{
	int value;
	struct node *p=start, *temp;
	printf("\nENTER DATA OF A NODE AFTER WHICH YOU WISH TO SEE ITEM:\n");
	scanf("%d",&value);
	while(p!=NULL)
	{
		if(p->data==value)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			printf("\n ENTER ITEM:\n");
			scanf("%d",&item);
			temp->data= item;
			temp->next=p->next;
			p->next=temp;
			break;
		}
		else if(p->next==NULL && p->data!=value)
		{
			printf("NO SUCH VALUE");
			return;
		}
		p=p->next;
	}
	if (p==start && p==NULL)
	{
		printf("This Action Can Not be performed as there is no element in the linked list");
		return;
	}
}
void display()
{
	struct node* p= start;
	printf("\n YOUR LINKED LIST LOOKS LIKE :\n\n");
	printf("\n|_HEAD");
	while(p!=NULL)
	{
		printf(" |_%d_|_|->",p->data);
		p=p->next;
	}
	printf("[NULL]\n");
}

