#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *start;

void insert_end()
{
    Node *p = start;
    Node *temp = new Node();
    int item;

    cout << "ENTER ITEM:" << endl;
    cin >> item;
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
    cout << " YOUR LINKED LIST LOOKS LIKE :" << endl;
    cout << "|_START";
    while (p != NULL)
    {
        cout << " |_" << p->data << "_|_|->";
        p = p->next;
    }
    cout << "[NULL]" << endl;
}

void deleteduplicates()
{
    Node *p1 = start,*p2;
    while (p1 && p1->next)
    {
        p2=p1;
        while(p2->next){
            if (p1->data == p2->next->data)
            {
                Node *temp = p2->next;
                p2->next = p2->next->next;
                free(temp);
            }
            else
                p2 = p2->next;
        }
        p1=p1->next;
    }
    display();
}

int main()
{
    int choice;
    cout << "PUSH ELEMENTS ONE BY ONE  INTO THE LINKED LIST:" << endl;

    int will;
    while (will)
    {
        insert_end();
        cout << "ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:" << endl;
        cin >> will;
    }
    deleteduplicates();
    return 0;
}
