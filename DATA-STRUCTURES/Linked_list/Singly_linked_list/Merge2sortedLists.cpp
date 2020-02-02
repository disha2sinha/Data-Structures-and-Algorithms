
/* Merge two sorted Linked List to get a single sorted LinkedList*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList{
    public:
        Node* start;
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
};
void display(Node* start)
{
    struct Node *p = start;
    cout << " YOUR MERGED LINKED LIST LOOKS LIKE :" << endl;
    cout << "|_START";
    while (p != NULL)
    {
        cout << " |_" << p->data << "_|_|->";
        p = p->next;
    }
    cout << "[NULL]" << endl;
}

Node* MergeLists(Node* start1,Node* start2)
{
    if (start1==NULL && start2==NULL)
    {
        return NULL;
    }
    if(start1!=NULL && start2==NULL)
    {
        return start1;
    }
    if(start1==NULL && start2!=NULL)
    {
        return start2;
    }
    if(start1->data<=start2->data)
    {
        start1->next=MergeLists(start1->next,start2);
    }
    else{
        Node* temp=start2;
        start2=start2->next;
        temp->next=start1;
        start1=temp;
        start1->next=MergeLists(start1->next,start2);
    }
    return start1;

}
int main()
{
    int choice;
    cout << "PUSH ELEMENTS ONE BY ONE  INTO THE LINKED LIST:" << endl;
    int count = 0;

    int will;
    cout<<"Enter elements for first Linked List:"<<endl;
    LinkedList* LList1=new LinkedList();
    while (will)
    {
        LList1->insert_end();
        cout << "ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:" << endl;
        cin >> will;
    }
    cout << "Enter elements for second Linked List:" << endl;
    int will1;
    LinkedList* LList2=new LinkedList();
    while (will1)
    {
        LList2->insert_end();
        cout << "ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:" << endl;
        cin >> will1;
    }
    Node* LList3=MergeLists(LList1->start,LList2->start);
    display(LList3);
    return 0;
}