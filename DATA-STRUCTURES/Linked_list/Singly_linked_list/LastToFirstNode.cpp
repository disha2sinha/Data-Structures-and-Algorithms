#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
};
Node *start;

void insert_end()
{
    Node *p = start;
    Node *temp = new Node();
    string item;

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
    Node *p = start;
    cout << " YOUR LINKED LIST LOOKS LIKE :" << endl;
    cout << "|_START";
    while (p != NULL)
    {
        cout << " |_" << p->data << "_|_|->";
        p = p->next;
    }
    cout << "[NULL]" << endl;
}
void LastToFirstList(){
    Node* p1=start,*p2=start;
    while(p1->next!=NULL)
    {
        p1=p1->next;
    }
    while(p2->next->next!=NULL)
    {
        p2=p2->next;
    }
    p1->next=start;
    start = p1;

    p2->next=NULL;
    display();
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
    display();
    LastToFirstList();
    

    return 0;
}
