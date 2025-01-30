/*
From the given set of numbers form a linked list and delete those nodes which have a greater value on their right side.

Note: The linked list should be formed in the reverse order of the given input integers. For a better understanding refer sample input and output.
Input Format 
The first input consists of an integer representing the number of elements.
The second line of input consists of an integer representing the elements separated by space.
Output Format 
The first line of output prints the given linked list. 
(Linked List)
The second line of output prints the modified linked list. 
(Final Linked List)
Sample Input 
5
3 2 6 5 11
Sample Output
Given Linked List 
11 5 6 2 3 
Modified Linked List 
11 6 3 
*/

#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
Node *tail=NULL;
void insert()
{
    int value;
    cin>>value;
     Node* newNode=new Node();
     newNode->data=value;
     newNode->next=head;
     head=newNode;    
}
void print()
{
    Node *y=head;
    while(y!=NULL)
    {
        cout<<y->data<<" ";
        y=y->next;
    }
}
void print1()
{
 Node *prev=NULL;
 Node *t=head;
 while(t!=NULL)
 {
     Node *temp=t->next;
    int f=1;
     while(temp!=NULL)
     {
         if(t->data >= temp->data)
         {
             f=1;
         }
         else
         {
             f=0;
             break;
         }
         temp=temp->next;
     }
     if(f==1)
     {
         cout<<t->data<<" ";
     }
     t=t->next;
     //cout<<t-
 }
 //cout<<t->data<<" ";
 
}
int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        insert();
    }
    cout<<"Given Linked List ";
    cout<<endl;
    print();
    cout<<endl;
    cout<<"Modified Linked List ";
    cout<<endl;
    print1();
    cout<<endl;
    
}

//------------------------or--------------------------
/
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val)
    {
        this->data = val;
        next=NULL;
    }
};

Node* head=NULL;

void insertbeg(int v)
{
    Node* newNode = new Node(v);
    
    if(head==NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void modify()
{
    Node* trav1 = head;
    Node* prev = NULL;
    while(trav1!=NULL)
    {
        int v1 = trav1->data;
        bool yes = false;
        Node* trav2 = trav1->next;
        while(trav2!=NULL)
        {
            int v2 = trav2->data;
            if(v2>v1)
            {
                yes = true;
                break;
            }
            trav2 = trav2->next;
        }
        if(yes)
        {
            if(prev==NULL)
            {
                Node* temp = trav1;
                head = trav1->next;
                trav1 = trav1->next;
                delete temp;
                continue;
            }
            else
            {
                Node* temp = trav1;
                prev->next = trav1->next;
                trav1=trav1->next;
                delete temp;
                continue;
            }
        }
        prev = trav1;       
        trav1 = trav1->next;
    }
}

void disp()
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        insertbeg(v);
    }
    
    cout<<"Given Linked List "<<endl;
    
    disp();
    
    modify();
    
    cout<<"\nModified Linked List "<<endl;
    
    disp();
    return 0;
}
