/*
Find the size of stack

Write a C++ program to find the size of stack using Linked List.

Note : Calculate the size using required function.

 Input Format 
Size of stack in first line

Stack elements in the next lines(Store the values in stack until it reaches -1)

 Output Format 
A single Integer displays the size of the stack
Sample Input 
2
1
5
Sample Output 
-1
Sample Output 
16
 Sample Input  
3
4
5
6
-1
Sample Output 
24
*/

#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
};
Node* head=NULL;
int count=0;
void push(int val) 
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    count++;
}
int getSize() 
{
    return count * sizeof(head);
}
int main() 
{
    int n, val;
    cin >> n;
    do
    {
        cin >> val;
        if (val != -1)
            push(val);
    }while(val > -1);
    cout << getSize() << endl;

    return 0;
}
