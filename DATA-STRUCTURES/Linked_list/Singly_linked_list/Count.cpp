#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node *start;
void insert_end()
{
    struct Node *p = start;
    struct Node *temp;
    int item;
    temp = (struct Node *)malloc(sizeof(struct Node));

    cout<<"ENTER ITEM:"<<endl;
    cin>> item;
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
void display()
{
    struct Node *p = start;
    cout<<" YOUR LINKED LIST LOOKS LIKE :"<<endl;
    cout<<"|_START";
    while (p != NULL)
    {
        cout<<" |_"<<p->data<<"_|_|->";
        p = p->next;
    }
    cout<<"[NULL]"<<endl;
}

void count()
{
    int count=1;
    struct Node *p=start;
    while(p->next!=NULL)
    {
        p=p->next;
        count++;
    }
    cout<<"Number of Nodes:"<<count;
}
int main()
{
    int choice;
    printf("PUSH ELEMENTS ONE BY ONE BEFORE DELETING INTO THE LINKED LIST:");
    int will;
    while (will)
    {
        insert_end();
        cout<<"ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:"<<endl;
        cin>> will;
    }
    display();
    count();
    return 0;
}
