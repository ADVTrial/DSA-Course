/*Reverse the Linked List and Swap two Nodes*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node *head=NULL;
Node *tail=NULL;
void insertLast() {
    int value;
    cin >> value;
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}

void reverseLinkedList()
{
    Node *prev = NULL;
    Node *nextNode = NULL;
    Node *curr = head;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head=prev;
}

void swapNodes(int a, int b) {
    if(a == b)
        return;

    Node *prevA = NULL;
    Node *currA = head;
    while(currA != NULL && currA->data != a)
    {
        prevA = currA;
        currA = currA->next;
    }

    Node *prevB = NULL;
    Node *currB = head;
    while(currB != NULL && currB->data != b) {
        prevB = currB;
        currB = currB->next;
    }
    if(currA == NULL || currB == NULL)
        return;

    if(prevA != NULL) {
        prevA->next = currB;
    } else {
        head = currB;
    }

    if(prevB != NULL) {
        prevB->next = currA;
    } else {
        head = currA;
    }

    Node* temp = currB->next;
    currB->next = currA->next;
    currA->next = temp;
    return;
}

// Function to print the linked list
void print() {
    Node *temp=head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        insertLast();
    }
    print();
    int a, b;
    cin >> a >> b;
    reverseLinkedList();
    print();
    swapNodes(a, b);
    print();

    return 0;
}
