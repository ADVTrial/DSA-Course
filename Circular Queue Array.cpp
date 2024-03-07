/*CIRCULAR QUEUE - Array Implementation*/
#include <iostream>
using namespace std;
const int SIZE = 5;
int queue[SIZE];
int front = -1, rear = -1;
bool isEmpty()
{
    if(front == -1 && rear == -1)
        return true;
    else
        return false;
}
bool isFull()
{
    if((rear + 1) % SIZE == front)
        return true;
    else
        return false;
}
void enqueue(int value)
{
    if (isFull()) {
        cout << "Queue is full, cannot enqueue" << endl;
        return;
    }
    else if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
}

void dequeue()
{
    if (isEmpty()) {
        cout << "Queue is empty, cannot dequeue" << endl;
        return;
    }
    else if (front == rear) {
        cout << "Element dequeued from the queue :" << queue[front] <<endl;
        front = rear = -1;
    }
    else {
        cout << "Element dequeued from the queue :" << queue[front] <<endl;
        front = (front + 1) % SIZE;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements are: ";
    int i = front;
    while(i!=rear)
    {
        cout << queue[i] << " ";
        i = (i + 1) % SIZE;
    }
    cout<< queue[rear];
    cout << endl;
}

int main() {
    int choice, element;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
