/*
Hall Ticket Collection - Queue

A group of students is waiting in a queue to collect their exam hall tickets from their teacher. But due to heavy crowd, the teacher announced that the students should form two new queues –

Queue1: Students whose names start with "S" and end with "a"

Queue2: Remaining students

The sequence should be maintained in both the queues as per the original queue.

Write a program to implement Queue functions to add an element and compare the names and then display the queues.

Example

Input

Andy,Sana,Nick,Sam,George,Veronica,Samar,Serena,Roger,Shanaya

Output

Queue 1:

Sana

Serena

Shanaya

Queue 2:

Andy

Nick

Sam

George

Veronica

Samar

Roger

Explanation

Enqueue the name starts with 's' and ends with 'a' in queue 1 i.e. Sana,Serena and Shanaya.

Remaining names are enqueued in the queue 2 i.e. Andy,Nick,Sam,George,Veronica,Samar and Roger

 Input Format
Input corresponds to the elements to be added in queue(Comma Separated Elements)

 Output Format
Output displays the names in respective queues.

If there is no elements in the queue, then display “No elements in the Queue”.

 Constraints
Perform case sensitive string comparison. Assume that both the output queues have the size 10.

 Sample Input
Andy,Sana,Nick,Sam,George,Veronica,Samar,Serena,Roger,Shanaya
Sample Output
Queue 1:
Sana
Serena
Shanaya
Queue 2:
Andy
Nick
Sam
George
Veronica
Samar
Roger
 Sample Input
Evangeline,Jeeva,Prabha,Godwin,Princeline,Felzia,Christa,Regis,Jackson,Princy,Raiza
Sample Output
Queue is full!!!
Queue 1:
No elements in the Queue
Queue 2:
Evangeline
Jeeva
Prabha
Godwin
Princeline
Felzia
Christa
Regis
Jackson
Princy
 Sample Input
Sweta,Surya,Siva,Sneha
Sample Output
Queue 1:
Sweta
Surya
Siva
Sneha
Queue 2:
No elements in the Queue
*/
/*Linear Queue - Array Implementation*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string names;
    getline(cin,names);
    queue<string> q1, q2;
    string s;
    int count=0;
    for(int i=0;i<names.length();i++)
    {
        if(count==10)
            break;
        else if(names[i]==',')
        {
            count++;
            if(s[0]=='S' && s[s.length()-1]=='a')
                q1.push(s);
            else
                q2.push(s);
            s="";
        }
        else
        {
            s+=names[i];
        }
    }
    if(s[0]=='S' && s[s.length()-1]=='a')
        q1.push(s);
    else
        q2.push(s);
    count++;
    if(count>10)
        cout<<"Queue is full!!!\n";
    cout<<"Queue 1:\n";
    if(q1.empty())
        cout<<"No elements in the Queue\n";
    else
    {
        while(!q1.empty())
        {
            cout<<q1.front()<<"\n";
            q1.pop();
        }
    }
    cout<<"Queue 2:\n";
    if(q2.empty())
        cout<<"No elements in the Queue\n";
    else
    {
        while(!q2.empty())
        {
            cout<<q2.front()<<"\n";
            q2.pop();
        }
    }
    return 0;
}
