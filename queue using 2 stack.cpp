/*
Queue using Two Stacks

Problem Description:

A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting for the longest) is always the first one to be removed.

A basic queue has the following operations:

Enqueue: add a new element to the end of the queue.

Dequeue: remove the element from the front of the queue and return it.

In this challenge, you must first implement a queue using two stacks. Then process q queries, where each query is one of the following 3  types:

1 x: Enqueue element x into the end of the queue.

2: Dequeue the element at the front of the queue.

3: Print the element at the front of the queue.

Sample Input:

10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2
Sample Output:
14
14

Explanation:
Perform the following sequence of actions:
Enqueue 42; queue = {42}
Dequeue the value at the head of the queue, 42; queue = {}
Enqueue 14; queue = {14}
Print the value at the head of the queue, 14; queue = {14}
Enqueue 28; queue = {14, 28}
Print the value at the head of the queue, 14; queue = {14, 28}
Enqueue 60; queue = {14, 28, 60}
Enqueue 78; queue = {14, 28, 60, 78}
Dequeue the value at the head of the queue, 14; queue = {28, 60, 78}
Dequeue the value at the head of the queue, 28; queue = {60, 78}.

 Input Format 
The first line contains a single integer, q, denoting the number of queries.

Each line i of the q subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query type, but only query 1 is followed by an additional space-separated value, x, denoting the value to be enqueued.

 Output Format 
For each query of type 3, print the value of the element at the front of the queue on a new line.
Sample Input
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2
Sample Output 
14
14
 Sample Input  
10
1 76
1 33
2
1 23
1 97
1 21
3
3
1 74
3
Sample Output 
33
33
33
*/
/*Queue Using Two Stacks*/
#include<bits/stdc++.h>
using namespace std;
stack<int> s1,s2;
void enqueue(int x)
{
    s1.push(x);
}
void dequeue()
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
void frontElement()
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    cout<<s2.top()<<endl;
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                int val;
                cin>>val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                frontElement();
                break;
        }
    }
    return 0;
}
