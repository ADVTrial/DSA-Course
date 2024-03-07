/*
Implement two queues in an array:

Write a program to insert and delete elements from both queues.

Note: n is always 10 (5 each).

 Input Format 
The first line of the input consists of the queue 1 elements.

The next line consists of the queue 2 elements.

 Output Format 
The output prints the dequeued elements from both queues separated by a space.

 Sample Input  
10 9 8 7 6
1 2 3 4 5
Sample Output 
10 1
*/
/*DEQUE = Double Ended Queue*/
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int arr[MAX_SIZE];
int front1=-1, rear1=-1;
int front2=MAX_SIZE / 2 - 1, rear2= MAX_SIZE / 2 - 1;

void enqueue1(int x) {
    if (rear1 == MAX_SIZE / 2 - 1) {
        cout << "Queue 1 is full." << endl;
        return;
    }
    if (front1 == -1) {
        front1 = 0;
    }
    arr[++rear1] = x;
}

void enqueue2(int x) {
    if (rear2 == MAX_SIZE - 1) {
        cout << "Queue 2 is full." << endl;
        return;
    }
    if (front2 == MAX_SIZE / 2 - 1 ) {
        front2 = MAX_SIZE / 2;
    }
    arr[++rear2] = x;
}

int dequeue1() {
    if (front1 > rear1 || front1 == -1) {
        cout << "Queue 1 is empty." << endl;
        return -1; // Returning -1 for an empty queue
    }
    return arr[front1++];
}

int dequeue2() {
    if (front2 > rear2 || front2 == (MAX_SIZE / 2 - 1)) {
        cout <<"Queue 2 is empty." << endl;
        return -1; // Returning -1 for an empty queue
    }
    return arr[front2++];
    cout<<front2<<endl;
}

int main() {
int value;
// Input for queue 1
for (int i = 0; i < 5; ++i) {
    cin>>value;
    enqueue1(value);
}

// Input for queue 2
for (int i = 0; i < 5; ++i) {
    cin>>value;
    enqueue2(value);
}

// Dequeue and print elements from both queues
cout << dequeue1() << " ";
cout << dequeue2() << endl;

return 0;
}
