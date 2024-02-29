/*Doubly Linked List */
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head=NULL;
void insertAtBeginning()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next=head;
        head->prev = newNode;
        head = newNode;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    Node *temp = head;
    Node *prevNode = head;
    while(--pos)
    {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next=newNode;
    newNode->prev = prevNode;
    newNode->next = temp;
    temp->prev = newNode;
}
void insertAtEnd()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
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
        newNode->prev=temp;
    }
}
void deleteFirst()
{
    if(head == NULL){
        cout<<"List is Empty\n";
    }
    else{
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
}
void deleteEnd()
{
    if(head == NULL)
    {
        cout<<"List is Empty\n";
    }
    else if(head->next==NULL)//Single node to be deleted,List becomes empty
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
    Node *prevNode=head;
    while(--pos)
    {
        prevNode=temp;
        temp=temp->next;
    }
    prevNode->next=temp->next;
    temp->next->prev=prevNode;
    delete(temp);
}
void printforward()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void printbackward()
{
    Node *temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        insertAtBeginning();
        printforward();
    }
    insertAtMiddle();
    printforward();
    insertAtMiddle();
    printforward();
    int count;
    cin>>count;
    for(int i=1;i<=count;i++)
    {
        deleteEnd();
        printforward();
    }
    deleteMiddle();
    printforward();
    deleteMiddle();
    printforward();
    cout<<"Doubly linked list forwards: ";
    printforward();
    cout<<"Doubly linked list backwards: ";
    printbackward();
    return 0;
}
