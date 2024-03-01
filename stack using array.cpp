/*Stack using Array*/
#include<iostream>
#define SIZE 5
using namespace std;
int stack[SIZE];
int top=-1;

bool isFull()
{
    if(top == SIZE -1)
        return true;
    else
        return false;
}
bool isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}
void push(int value)
{
    if(isFull())
        cout<<"Stack Overflow, cant push"<<endl;
    else
        stack[++top]=value;
}
void pop()
{
    if(isEmpty())
        cout<<"Stack Underflow, cant pop"<<endl;
    else
        cout<<"Popped "<<stack[top--]<<endl;
}
void peek()
{
    cout<<"Top element is "<<stack[top]<<endl;
}
void display()
{
    cout<<"Stack Elements"<<endl;
    for(int i=top; i>=0; i--)
        cout<<stack[i]<<endl;
}
int main()
{
    int n,value;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        push(value);
    }  
    display();
    pop();
    display();
    pop();
    display();
    peek();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}