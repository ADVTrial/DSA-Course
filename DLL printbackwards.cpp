#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head=NULL;
Node *tail=NULL;
void insertAtBeginning()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(head == NULL){//update the head->prev only when list is already created
       head = newNode;
       tail = newNode;
    }
    else
    {
        newNode->next=head;
        head->prev = newNode;
        head = newNode;
    }
}
void printforward()
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void printbackward()
{
    /*
    Node *temp=head;
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
    
    -----------------or--------------------*/
    Node *temp = tail;
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
    for(int i=0;i<n;i++)
    {
        insertAtBeginning();
    }
    cout<<"Doubly linked list forwards: ";
    printforward();
    cout<<"Doubly linked list backwards: ";
    printbackward();
    return 0;
}