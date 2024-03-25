/*Circular Doubly Linked List */
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
    if(head==NULL)//List is Empty so create List
    {
        tail = newNode;
        head = newNode;
        head->prev = tail;
        tail->next = head;
    }
    else
    {
        newNode->next=head;
        newNode->prev=tail;
        head->prev=newNode;
        head=newNode;
        tail->next=head;
    }
}
void insertAtMiddle()
{
    int pos;
    cin>>pos;
    if(pos==1)
    {
        insertAtBeginning();
        return;
    }
    int value;
    cin>>value;
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
    if(temp==head && prevNode==tail)
    {
        tail=newNode;
    }
}
void insertAtEnd()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(head==NULL)
    {
        tail=newNode;
        head = newNode;
        head->prev = tail;
        tail->next = head;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail=newNode;
        head->prev = tail;
        tail->next = head;
    }
}
void deleteFirst()
{
    if(head == NULL)
    {
        cout<<"List is Empty, can't Delete\n";
    }
    else
    {
        if(head==tail)//Single Node to be deleted, then List becomes empty
        {
            delete head;
            head=NULL;
            tail=NULL;
        }
        else
        {
            Node *temp=head;
            head=head->next;
            tail->next=head;
            head->prev=tail;
            delete temp;
        }
    }
}
void deleteEnd()
{
    if(head == NULL)
    {
        cout<<"List is Empty, Can't Delete\n";
    }
    else if(head==tail)//Single node to be deleted,List becomes empty
    {
        delete(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        Node *temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        delete(temp);
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
    if(temp==tail)
    {
        tail=prevNode;
    }
    delete(temp);
}
void printforward()
{
    if( head==NULL && tail==NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}
void printbackward()
{
    if( head==NULL && tail==NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }while(temp!=tail);
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        insertAtBeginning();
    }
    printforward();
    insertAtMiddle();
    printforward();
    insertAtMiddle();
    printforward();
    insertAtEnd();
    printforward();
    insertAtEnd();
    printforward();
    
    cout<<"Circular Doubly linked list forwards: ";
    printforward();
    cout<<"Circular Doubly linked list backwards: ";
    printbackward();
    
    deleteMiddle();
    printforward();
    deleteMiddle();
    printforward();
    deleteFirst();
    printforward();
    deleteFirst();
    printforward();
    deleteEnd();
    printforward();
    deleteEnd();
    printforward();
    deleteEnd();
    printforward();
    deleteFirst();
    printforward();
    deleteFirst();
    printforward();

    return 0;
}
/*INPUT
4
10 20 30 40
2 50
5 60
70
80
3
5
*/
