/*Stack ADT - Linked List Implementation*/
/*Stack using Linked List*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
void push(int value)//Insert at Beginning
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void pop() //Delete at Beginning
{
    if(head == NULL)
    {
        cout<<"Stack is Empty, cannot pop\n";
    }
    else
    {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
}
void peek()
{
    if(head == NULL)
    {
        cout<<"Stack is Empty, No peek\n";
    }
    else
    {
        cout<<"Peek Element is "<<head->data<<endl;
    }
}
void print()
{
    cout<<"Stack Elements\n";
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
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        push(val);
    }
    print();
    pop();
    print();
    pop();
    print();
    peek();
    print();
    return 0;
}
/*
int main()
{
    int val;
    char choice;
    do
    {
        cin>>val;
        push(val);
        cin>>choice;
    }while(choice=='Y'||choice=='y');
    print();
    pop();
    print();
    pop();
    print();
    peek();
    print();
    return 0;
}
*/
