/*
Ramu want to implement a fixed size queue of maximum size 5 using an array. His friend Priya has typed some code and asked Ramu to complete the missing code to implement. Help Ramu by writing suitable functions to do the basic queue operations.



Structure declaration and main fucntions are already implemented. Write the suitable code for functions only.

Example

Input

140

255

145

985

215

Output

140 255 145 985 215 

145 985 215 

Queue is empty

Explanation

First Enqueue 140,255,145,985,215 and display queue values. 

Second Dequeue two values 140 and 255 and print all the queue values i.e.145,985,215 .

Last dequeue all the elements from the queue and print "Queue is empty".



 Input Format 
Queue elements one below the other

 Output Format 
Display entire queue elements in first line

Display remaining queue elements in second line (After performing dequeue 2 times)

Display empty message in third line as shown in sample output(After removing all the elements from the queue)

 Constraints 
Queue size is 5

 Sample Input  
140
255
145
985
215
Sample Output 
140 255 145 985 215 
145 985 215 
Queue is empty
*/
/*Linear Queue - Array Implementation*/
#include<iostream>
using namespace std;
#define size 5
int queue[size];
int front=-1;
int rear=-1;
bool isEmpty()
{
    return (front==-1 && rear==-1);
}
bool isFull()
{
    return (rear==size-1);
}
void enqueue(int value)
{
    if(isFull())
    {
        cout<<"Queue is full. Cannot enqueue more elements"<<endl;
        return;
    }
    else if(isEmpty())
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=value;
}
void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty. Cannot dequeue elements"<<endl;
        return;
    }
    else if(front==rear)//Single Node Deletion
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
int getFront() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return queue[front];
}
void print()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int element;
    for(int i=0;i<5;i++)
    {
        cin>>element;
        enqueue(element);
    }
    print();
    dequeue();
    dequeue();
    cout<<getFront()<<endl;
    print();
    for(int i=1;i<=3;i++)
    {
        dequeue();
    }
    print();
}
