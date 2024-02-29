/*Circular Singly Linked List*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
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
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next=head;
        head = newNode;
        tail->next=head;
    }
}
void insertAtEnd()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL)//List is empty so create the list
    {
        head = tail = newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
        tail->next=head;
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
    else if(head == tail) //Single Node Deletion
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        tail->next=head;
        delete temp;
    }
}
void deleteEnd()
{
    if(head == NULL)
    {
        cout<<"List is Empty\n";
    }
    else if(head == tail)//Single node deletion,List becomes empty
    {
        delete(head);
        head = tail = NULL;
    }
    else
    {
        Node *temp = head;
        Node *prev = head;
        while(temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        tail = prev;
        tail->next = head;
        delete temp;
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
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
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

