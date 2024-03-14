/*
Binary Search Tree - Diameter

Problem statement

Create a binary search tree consisting of only positive values & print the diameter of the tree.

Note

An infinite line of integer input represents the nodes of the binary search tree. If any value less than 1 is encountered, the input loop has to break and print the diameter of the tree. 

Example

Input

2 3 1 0

Output

3

Explanation

2 is the root of the tree. 3 and 1 are the right and left children of 2. The diameter of this BST is 3 since the path 3 2 1 or 1 2 3.

 Input Format 
Read a line of integers.

 Output Format 
Print the diameter of the tree.

 Sample Input  
2 3 1 0 
Sample Output 
3
 Sample Input
2 3 1 4 0
Sample Output 
4
*/
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* insert(Node* root, int value) {
    if (root == nullptr) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else  {
        root->right = insert(root->right, value);
    }

    return root;
}

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int diameter(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

int main() {
    Node* root = nullptr;
    int value;

    while (cin >> value && value >= 1) {
        root = insert(root, value);
    }

    int treeDiameter = diameter(root);
    cout << treeDiameter << endl;

    return 0;
}
