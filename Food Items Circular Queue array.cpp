/*
Design and implement a food ordering system for a restaurant using a circular queue data structure. The system should manage incoming food orders from multiple customers and allocate kitchen staff to prepare the orders efficiently.

The system should allow the user to perform the following operations:

Enqueue a food order into the queue with a unique order number, customer name, and list of food items ordered.
Dequeue an order from the queue (when it has been processed by the kitchen staff).
Display the current state of the queue with the order numbers, customer names, and list of food items ordered.
Exit the program.

The program should be able to handle invalid inputs and display appropriate error messages. The program should also be able to handle the circular nature of the queue, ensuring that when the last element is reached, the next enqueued order is added at the beginning of the queue.

Note: There is a new line space after the last line of the output.

 Input Format 
The program starts with a menu that allows the user to choose from the following options: 

Enqueue an order into the queue (option 1)
Dequeue an order from the queue (option 2)
Display the current state of the queue (option 3)
Exit the program (option 4)

When the user selects option 1, the program prompts the user to enter the order number, customer name, and food items ordered.
When the user selects option 2, the program removes the first order in the queue.
When the user selects option 3, the program displays the current state of the queue with the order numbers, customer names, and food items ordered.

 Output Format 
For option 1, the program will confirm the order has been added to the queue.
For option 2, the program will confirm the order has been removed from the queue.
For option 3, the program will display the current state of the queue with the order numbers, customer names, and food items ordered.
For option 4, the program will exit.

If the queue reaches its maximum size, then display "Queue is full".
If the dequeue is performed on an empty queue, then display "Queue is empty".
If the input is any of the mentioned options, then print "Invalid choice".

 Constraints 
MAX_FOOD_ITEMS = 20
MAX_QUEUE_SIZE = 100

 Sample Input
1
1
John
3
burger
fries
coke
1
2
Sarah
2
Pizza
Soda
3
2
4
Sample Output
Order added to queue
Order added to queue
Order number	Customer name	Food items
1		John		burger, fries, coke, 
2		Sarah		Pizza, Soda, 
Order number: 1
Customer name: John
Food items: 
burger
fries
coke
 Sample Input   
5
1
101
jhon
2
egg
milk
3
4
Sample Output
Invalid choice
Order added to queue
Order number	Customer name	Food items
101		jhon		egg, milk, 
*/
#include<iostream>
using namespace std;
const int MAX_FOOD_ITEMS = 20;
const int MAX_QUEUE_SIZE = 100;
struct Order
{
    int orderNumber;
    string customerName;
    int foodItemsCount;
    string foodItems[MAX_FOOD_ITEMS];
};
Order queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(Order data)
{
    if((rear+1)%MAX_QUEUE_SIZE == front)
    {
        cout<<"Queue is full\n";
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear+1) % MAX_QUEUE_SIZE;
    }
    queue[rear]=data;
    cout<<"Order added to queue"<<endl;
}

void dequeue()
{
    if(front == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        Order curr=queue[front];
        cout<<"Order number: "<<curr.orderNumber<<endl;
        cout<<"Customer name: "<<curr.customerName<<endl;
        cout<<"Food items: "<<endl;
        for(int i=0; i<curr.foodItemsCount; i++)
            cout<<curr.foodItems[i]<<endl;
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
        }
    }
}

void display()
{
    if(front == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        cout << "Order number\tCustomer name\tFood items\n";
        int i = front;
        while(i!=rear)
        {
            Order curr=queue[i];
            cout<<curr.orderNumber<<"\t"<<curr.customerName<<"\t";
            for(int i=0; i<curr.foodItemsCount; i++)
                cout<<curr.foodItems[i]<<", ";
            cout<<endl;
            i = (i + 1) % MAX_QUEUE_SIZE;
        }
        Order curr=queue[i];
        cout<<curr.orderNumber<<"\t"<<curr.customerName<<"\t";
        for(int i=0; i<curr.foodItemsCount; i++)
            cout<<curr.foodItems[i]<<", ";
        cout<<endl;
    }
}
int main() 
{
    int choice;
    do 
    {
        cin >> choice;
        switch (choice) 
        {
            case 1:
            {
                Order neworder;
                cin>>neworder.orderNumber;
                cin>>neworder.customerName;
                cin>>neworder.foodItemsCount;
                for(int i=0;i<neworder.foodItemsCount;i++)
                    cin>>neworder.foodItems[i];
                enqueue(neworder);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}
