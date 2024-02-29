/*Singly Linked List*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
void insertAtBeginning()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL)//List is empty so create the list
        head = newNode;
    else
    {
        Node *temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void insertAtMiddle()
{
    int value;
    cin>>value;
    int pos;
    cin>>pos;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    Node *temp = head;
    Node *prev = head;
    while(--pos)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next=newNode;
    newNode->next = temp;
}
void deleteFirst()
{
    if(head == NULL)
    {
        cout<<"List is Empty\n";
    }
    else
    {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
}
void deleteEnd()
{
    if(head == NULL)
    {
        cout<<"List is Empty\n";
    }
    else if(head->next== NULL)//Single node to be deleted,List becomes empty
    {
        delete(head);
        head = NULL;
    }
    else
    {
        Node *temp=head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
}
void deleteMiddle()
{
    int pos;
    cin>>pos;
    Node *temp=head;
    Node *prev=head;
    while(--pos)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete(temp);
}
void print()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        insertAtEnd();
    }
    print();
    insertAtBeginning();
    print();
    insertAtBeginning();
    print();
    insertAtMiddle();
    print();
    insertAtMiddle();
    print();
    deleteMiddle();
    print();
    deleteFirst();
    print();
    deleteMiddle();
    print();
    deleteEnd();
    print();
    return 0;
}
