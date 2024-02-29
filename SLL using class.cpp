/*Singly Linked List Representation of List ADT - using class in C++*/
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class SLL
{
    Node *head=NULL;
public:
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
};
int main()
{
    int n;
    cin>>n;
    SLL obj;
    for(int i=1;i<=n;i++)
    {
        obj.insertAtEnd();
    }
    obj.print();
    return 0;
}
