/*
Binary Search Tree - Common Ancestor

Create a binary search tree consisting of only positive values & print the common ancestor for the given nodes in the tree.



Note

An infinite line of integer input representing the nodes of the binary search tree. If any value less than 1 is encountered, the input loop has to break and print the common ancestor for the given nodes in the tree. 



Example

Input

2 3 1 -1 3 1 

Output

2

Explanation

2 is the root and 3 and 1 are the children of 2. So the common ancestor for 3 and 1 is 2.

 Input Format 
Read a line of integers.

 Output Format 
The common ancestor for the given nodes in the tree.

 Sample Input 
2 3 1 -1 3 1 
 Sample Output 
2
 Sample Input
3 2 4 5 1 0 4 1
 Sample Output 
3
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

Node* findCommonAncestor(Node* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }

    while (root != nullptr) {
        if (root->data > n1 && root->data > n2) {
            root = root->left;
        } else if (root->data < n1 && root->data < n2) {
            root = root->right;
        } else {
            break;
        }
    }

    return root;
}

int main() {
    Node* root = nullptr;
    int value;

    while (cin >> value && value >= 1) {
        if (root == nullptr) {
            root = createNode(value);
        } else {
            insertNode(root, value);
        }
    }

    int n1, n2;
    cin >> n1 >> n2;

    Node* commonAncestor = findCommonAncestor(root, n1, n2);

    if (commonAncestor != nullptr) {
        cout << "Common Ancestor of " << n1 << " and " << n2 << " is: " << commonAncestor->data << endl;
    } else {
        cout << "Nodes not found or no common ancestor exists!" << endl;
    }

    return 0;
}
