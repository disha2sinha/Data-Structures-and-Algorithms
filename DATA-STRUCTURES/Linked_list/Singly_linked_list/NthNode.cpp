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
    Node *temp=new Node();
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

void search(int index)
{
    int count = 0;
    Node *p = start;
    while (p != NULL)
    {
        p = p->next;

        count++;
    }
    
    assert(index<=count);

    p = start;
    for (int i = 1; i < index; i++)
    {
        p = p->next;
    }
    cout << "Node At " << index << "th position:" << p->data << endl;
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
    int key;
    cout << "Enter Key:";
    cin >> key;
    display();
    search(key);
    return 0;
}
