/*Sum of Leaf Nodes in Binary Search Tree*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == NULL){
        Node* newnode = new Node();
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int sumOfLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }
    return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
}

int main() {
    Node* root = NULL;
    
    int val;
    cin >> val;
    while ( val > 0 ) {
        root = insert( root, val);
        cin>>val;
    }
    /*
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 10);
    */
    int sum = sumOfLeafNodes(root);
    cout << sum << endl;
    return 0;
}
