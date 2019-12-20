#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int item;
void insertifempty();
void insert_beginning(void);
void insert_end(void);
void insert_location();
void insert_after_value();
void display(void);
struct node
{
    int data;
    struct node *next;
};
struct node *start;
void main()
{
    int choice;
    while (1)
    {
        printf("\nCIRCULAR LINKED LIST: \n 1. INSERT IF LINKED LIST IS EMPTY\n 2. INSERT AT THE BEGINNING\n 3. INSERT AT THE END\n 4. INSERT AT A GIVEN LOCATION\n 5. INSERT AFTER A GIVEN VALUE\n 6. DISPLAY\n 7. EXIT\n\n");
        printf("\nENTER YOUR CHOICE:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertifempty();
            break;

        case 2:
            insert_beginning();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_location();
            break;
        case 5:
            insert_after_value();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\n YOU HAVE ENTERED A WRONG CHOICE\n");
        }
    }
}
void insertifempty()
{
    if(start!=NULL)
    {
        printf("LINKED LIST IS NOT EMPTY.TRY OTHER OPTIONS!!!!\n");
        return;
    }
    struct node* temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n ENTER ITEM:\n");
    scanf("%d", &item);
    temp->data = item;
    start=temp;
    start->next=start;
}
void insert_beginning()
{
    if(start==NULL)
    {
        insertifempty();
        return;
    }
    struct node *p = start, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n ENTER ITEM:\n");
    scanf("%d", &item);
    temp->data = item;
    temp->next = start;
    while(p->next!=start)
    {
        p=p->next;
    }
    p->next=temp;
    start = temp;
}
void insert_end()
{
    if (start == NULL)
    {
        insertifempty();
        return;
    }
    struct node *p = start, *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n ENTER ITEM:\n");
    scanf("%d", &item);
    temp->data = item;
    
    while (p->next != start)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = start;
}
void insert_location()
{
    if (start == NULL)
    {
        insertifempty();
        return;
    }

    struct node *p = start, *temp;
    int loc, i;
    printf("\nENTER LOCATION\n ");
    scanf("%d", &loc);
    if (loc < 1)
    {
        printf("Invalid Location entered\n");
        return;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n ENTER ITEM:\n");
    scanf("%d", &item);
    temp->data = item;
    if (loc == 1)
    {
        temp->next = start;
        while(p->next!=start)
        {
            p=p->next;
        }
        p->next=temp;
        start = temp;

    }
    else
    {

        for (i = 1; i < loc - 1; i++)
        {
            p = p->next;

            if (p == NULL)
            {
                printf("NO SUCH LOCATION\n");
                free(p);
                return;
            }
        }

        struct node *location = p->next;
        p->next = temp;
        temp->next = location;
    }
}
void insert_after_value()
{
    if (start == NULL)
    {
        insertifempty();
        return;
    }

    int value;
    struct node *p = start->next, *temp;
    printf("\nENTER DATA OF A NODE AFTER WHICH YOU WISH TO SEE ITEM:\n");
    scanf("%d", &value);
    if (start->data==value)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\n ENTER ITEM:\n");
        scanf("%d", &item);
        temp->data = item;
        temp->next = start->next;
        start->next = temp;
        return;
    }
    while (p != start)
    {
        if (p->data == value)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            printf("\n ENTER ITEM:\n");
            scanf("%d", &item);
            temp->data = item;
            temp->next = p->next;
            p->next = temp;
            break;
        }
        else if (p->next == start && p->data != value)
        {
            printf("NO SUCH VALUE");
            return;
        }
        p = p->next;
    }
}
void display()
{
    int count=1;
    if(start==NULL)
    {
        printf("LINKED LIST EMPTY\n");
        return;
    }
    struct node *p = start->next;
    printf("\n YOUR LINKED LIST LOOKS LIKE :\n\n");
    printf("\n--->|_HEAD|_%d_|_|->",start->data);
    while (p != start)
    {
        printf(" |_%d_|_|->", p->data);
        count++;
        p = p->next;
    }
    printf("--\n");
    printf("|");
    printf("_________________");
    for(int i=1;i<count;i++)
        printf("___________");
    printf("__|");
}
