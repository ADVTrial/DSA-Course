/*
Write a program for level order traversal in spiral form.

Input Format :
The input consists of 7 integers that represents the value of each node in the tree.

Output Format :
Print the value of each node in the tree's level-order traversal as a single line of T space-separated Integers.

Sample testcases :
Input
1 2 3 7 6 5 4
Output
Level Order Traversal:
1 2 3 7 6 5 4 
Level Order Spiral Traversal:
1 2 3 4 5 6 7 

Input
2 3 4 5 6 7 1
Output
Level Order Traversal:
2 3 4 5 6 7 1 
Level Order Spiral Traversal:
2 3 4 1 7 6 5 
*/
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the complete binary tree
void insert(Node* &root, int value) 
{
    if (root == nullptr) {
        root = new Node(value);
    } 
    else {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) 
        {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = new Node(value);
                break;  // Value inserted, exit loop
            } 
            else if (current->right == nullptr) {
                current->right = new Node(value);
                break;  // Value inserted, exit loop
            } 
            else {
                q.push(current->left);
                q.push(current->right);
            }
        }
    }
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr) 
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void levelOrderspiralTraversal(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node* curr=s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            if(curr->right!=nullptr)
            {
                s2.push(curr->right);
            }
            if(curr->left!=nullptr)
            {
                s2.push(curr->left);
            }
        }
        while(!s2.empty())
        {
            Node* curr=s2.top();
            s2.pop();
            cout<<curr->data<<" ";
            if(curr->left!=nullptr)
            {
                s1.push(curr->left);
            }
            if(curr->right!=nullptr)
            {
                s1.push(curr->right);
            }
        }
    }
}

int main() {
    Node* root = nullptr;
    for(int i=0; i<7; i++)
    {
        int val;
        cin >> val;
        insert(root,val);
    }

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "Level Order Spiral Traversal:" << endl;
    levelOrderspiralTraversal(root);
    cout << endl;
    return 0;
}
