/*Write a program to implement a stack and search for an element in the stack.

 Input Format 
Number of stack elements in first line

Stack elements in second line separated by space

Element to be searched in third line

 Output Format 
Output prints whether the element is found or not

 Sample Input  
5
1 2 3 4 5
3
Sample Output 
Element found
 Sample Input  
5
1 2 3 4 5
37
Sample Output 
Element not found

*/

/*Search using Stack - Array Representation*/
#include<iostream>
using namespace std;
int stack[100];
int top=-1;
void push(char value)
{
    stack[++top]=value;
}
void search(int key)
{
    bool flag=false;
    for(int i=0;i<=top;i++)
    {
        if(stack[i]==key)
        {
            flag = true;
            break;
        }
    }
    if(flag)
        cout<<"Element Found";
    else
        cout<<"Element not found";
}
int main()
{
    int n,val,key;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        push(val);
    }
    cin>>key;
    search(key);
    return 0;
}

-----------------------or-------------------

/*Search - Stack using Linked List*/
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
void search(int key)
{
    bool flag = false;
    Node *temp = head;
    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            flag = true;
            break;
        }
        temp = temp->next;
    }
    if(flag)
        cout<<"Element Found";
    else
        cout<<"Element not found";
}
int main()
{
    int n,val,key;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        push(val);
    }
    cin>>key;
    search(key);
    return 0;
}

