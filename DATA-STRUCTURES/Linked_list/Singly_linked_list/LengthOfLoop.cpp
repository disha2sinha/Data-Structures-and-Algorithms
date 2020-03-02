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
void create_loop(int pos)
{
    int count=1;
    Node *temp1 = start, *temp2 = start;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    while (count < pos)
    {
        temp2 = temp2->next;
        count++;
    }
    temp1->next = temp2;
    cout << temp1->next->data << endl;
}
int countNodes(Node* n)
{
    int count=1;
    Node* temp=n;
    while(temp->next!=n)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int traverse_loop()
{
    Node* slow=start,*fast=start;
    while(fast && slow && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    
        if(fast==slow)
        {
            return countNodes(slow);
        }
    }
    return 0;
}
int main()
{
    int choice;
    cout << "PUSH ELEMENTS ONE BY ONE  INTO THE LINKED LIST:" << endl;
    int count = 0;

    int will;
    while (will)
    {
        insert_end();
        cout << "ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:" << endl;
        cin >> will;
    }
    char loop;
    cout<<"Want to create a loop?Y/N"<<endl;
    cin>>loop;
    int pos;
    if(loop=='Y'|| loop=='y')
    {
        cout<<"Mention the position of the linked list where your last node will be connected:"<<endl;
        cin>>pos;
        create_loop(pos);
    }
    else if(loop=='N'||loop=='n')
    {
        cout<<"No loop exists"<<endl;
    }
    else
    {
        cout<<"Wrong input"<<endl;
    }
    
    int result=traverse_loop();
    cout<<"Number of Nodes in loop:"<<result<<endl;
    return 0;
}
