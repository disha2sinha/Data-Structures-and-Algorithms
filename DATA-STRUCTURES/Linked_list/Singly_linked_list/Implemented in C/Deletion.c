#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int item;
void insert_end();
void delete_by_location();
void delete_by_item();
void deleteLList();
void display(void);
struct node
{
    int data;
    struct node *next;
};
struct node *start;
struct node *tail = NULL;
void main()
{
    int choice;
    printf("PUSH ELEMENTS ONE BY ONE BEFORE DELETING INTO THE LINKED LIST:");
    int will;
    while(will)
    {
        insert_end();
        printf("ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:");
        scanf("%d",&will);
    }
    while (1)
    {
        printf("\n LINKED LIST: \n 1. DELETE BY LOCATION\n 2. DELETE BY VALUE\n 3. DELETE LINKED LIST COMPLETELY\n 4. DISPLAY\n 5. EXIT\n\n");
        printf("\nENTER YOUR CHOICE:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            delete_by_location();
            break;
        case 2:
            delete_by_item();
            break;
        case 3:
            deleteLList();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\n YOU HAVE ENTERED A WRONG CHOICE\n");
        }
    }

}
void insert_end()
{
    struct node *p = start, *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n ENTER ITEM:\n");
    scanf("%d", &item);
    temp->data = item;
    if (start == NULL)
    {
        start = temp;
        temp->next = NULL;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = NULL;
    }
}
void delete_by_location()
{
    struct node *p = start, *old = start, *temp;
    int loc, i;
    if (start==NULL)
    {
        printf("NOTHING TO DELETE");
        return;
    }
    printf("\nENTER LOCATION:\n");
    scanf("%d", &loc);
    for (i = 1; i < loc; i++)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        printf("LOCATION NOT FOUND\n");
        free(p);
        return;
    }
    if (p == start)
    {
        start = start->next;
        free(p);
    }
    else if (p->next == NULL)
    {
        for (i = 1; i < loc - 1; i++)
        {
            old = old->next;
        }
        old->next = NULL;
        free(p);
    }
    
    else
    {
        for (i = 1; i < loc - 1; i++)
        {
            old = old->next;
        }
        old->next = p->next;
        free(p);
    }
}
void delete_by_item()
{
    int value;
    struct node *p = start, *old = start, *temp;
    if (start == NULL)
    {
        printf("NOTHING TO DELETE\n");
        return;
    }
    printf("\nENTER DATA OF A NODE WHICH YOU WISH TO DELETE:\n");
    scanf("%d", &value);
    while (p->data != value)
    {
        p = p->next;
        if (p==NULL)
        {
            printf("VALUE ENTERED IS NOT FOUND");
            free(p);
            return;
        }
    }

    if (p == start)
    {
        start = start->next;
        free(p);
    }
    else if (p->next == NULL)
    {
        while (old->next->data != value)
        {
            old = old->next;
        }
        old->next = NULL;
        free(p);
    }
    

    else
    {
        while (old->next->data != value)
        {
            old = old->next;
        }
        old->next = p->next;
        free(p);
    }
}

void deleteLList()
{
    if(start==NULL)
    {
        printf("Nothing To Delete");
        return;
    }
    struct node*p=start;
    struct node*nextnode;
    while(p!=NULL)
    {
        nextnode=p->next;
        free(p);
        p=nextnode;
    }
    start=NULL;
    printf("Linked List Deleted\n");
    
}
void display()
{
    struct node *p = start;
    printf("\n YOUR LINKED LIST LOOKS LIKE :\n\n");
    printf("\n|_START");
    while (p != NULL)
    {
        printf(" |_%d_|_|->", p->data);
        p = p->next;
    }
    printf("[NULL]\n");
}
