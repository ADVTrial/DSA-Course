/*
Write a program to implement a priority queue using an array-based approach. 



The priority queue should support the following operations: insert an element into the priority queue with a specified priority, remove the element with the highest priority from the priority queue, and print the elements in the order of their priorities.



Company Tags: Wipro

Input format :
The first line of input consists of an integer N, representing the number of elements to be inserted into the priority queue.

This is followed by N lines, each containing two space-separated integers: element and priority. 1 has the highest priority.

Output format :
The first line of output prints the initial state of the priority queue after inserting all the elements, based on priority.

The second line prints the state of the priority queue after performing the dequeue operation.



Refer to the sample output for the exact text and format.

Code constraints :
The priority queue can store up to 100 elements (MAX_SIZE = 100).

Sample test cases :
Input 1 :
5
4 2
3 1
6 4
2 3
1 5
Output 1 :
Priority Queue: 3 4 2 6 1 
Priority Queue: 4 2 6 1 
Input 2 :
3
9 1
2 2
7 3
Output 2 :
Priority Queue: 9 2 7 
Priority Queue: 2 7
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct Element{
    int value;  
    int priority;
};
bool operator<(const Element& o1, const Element& o2)  {
    return o1.priority > o2.priority;
}
void print(priority_queue<Element> pq){
    while(!pq.empty()){
        cout<<pq.top().value<<" ";
        pq.pop();
    }
    cout<<endl;
}
int main(){
    int n;
    cin >> n;
    priority_queue<Element> pq;
    for(int i=0; i<n; i++){
        Element e;
        cin >> e.value >> e.priority;
        pq.push(e);
    }
    cout <<"Priority queue: ";
    print(pq);
    pq.pop();
    cout <<"Priority queue: ";
    print(pq);
    return 0;
}
----------------or---------------------
/*
#include <iostream>
using namespace std;
#define MAX_SIZE 100

struct Element {
    int value;
    int priority;
};

class PriorityQueue {
    Element arr[MAX_SIZE];
    int size;

public:
    PriorityQueue() { size = 0; }

    void insert(int value, int priority) {
        if (size == MAX_SIZE) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[size].value = value; 
        arr[size].priority = priority;
        size++;
    }

    void removeHighestPriority() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        size--;
    }
    void arrange(){
        for(int i=0;i<size-1;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(arr[i].priority < arr[j].priority)
                {
                    swap(arr[i],arr[j]);
                }
    
            }
        }
    }
    void printQueue() {
        cout << "Priority Queue: ";
        for (int i = size-1; i >= 0; i--) {
            cout << arr[i].value << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int value, priority;
        cin >> value >> priority;
        pq.insert(value, priority);
    }
    pq.arrange();
    pq.printQueue();
    pq.removeHighestPriority();
    pq.printQueue();
    
    return 0;
}
*/
--------------------------or------------------
#include<iostream>
#include<algorithm>
using namespace std;
struct Element{
    int value;  
    int priority;
};
void print(Element arr[], int n)
{
    for(int i=n-1; i>=0; i--){
        cout<<arr[i].value<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin >> n;
    Element arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].value >> arr[i].priority;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i].priority < arr[j].priority){
                swap(arr[i], arr[j]);
            }
        }
    }
    cout <<"Priority queue: ";
    print(arr, n);
    n = n-1;
    cout <<"Priority queue: ";
    print(arr, n);
    // for(int i=n-1; i>=0; i--){
    //     cout<<arr[i].value<<" ";
    // }
    return 0;
}
