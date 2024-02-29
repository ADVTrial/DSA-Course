/*Doubly Linked List */
#include<iostream>
using namespace std;
struct Node
{
    string name;
    int id;
    float avg;
    Node *prev;
    Node *next;
};
Node *head=NULL;
void insertAtBeginning()
{
    string name;
    int id;
    float avg;
    cin>>name>>id>>avg;
    Node *newNode = new Node();
    newNode->name = name;
    newNode->id =id;
    newNode->avg = avg;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(head != NULL){//update the head->prev only when list is already created
       newNode->next=head;
       head->prev = newNode;
    }
    head = newNode;
}
void insertAtEnd()
{
    string name;
    int id;
    float avg;
    cin>>name>>id>>avg;
    Node *newNode = new Node();
    newNode->name = name;
    newNode->id =id;
    newNode->avg = avg;
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
void print()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->name<<" "<<temp->id<<" "<<temp->avg<<endl;
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
    int count;
    cin>>count;
    for(int i=1;i<=count;i++)
    {
        deleteEnd();
    }
    print();
    return 0;
}
