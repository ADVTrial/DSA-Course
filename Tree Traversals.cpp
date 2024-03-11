/*Binary Search Tree - Traversals

Input
50 25 6 75 30 60 70 52 85 -1

Output
Preorder Traversal:
50 25 6 30 75 60 52 70 85 
Inorder Traversal:
6 25 30 50 52 60 70 75 85 
Postorder Traversal:
6 30 25 52 70 60 85 75 50 
Levelorder Traversal:
50 25 75 6 30 60 85 52 70

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val) {
    if (root == NULL){
        Node* newnode = new Node();
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) 
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void levelorder(Node* root) {
    if (root == NULL) 
        return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}


int main() {
    Node* root = NULL;
    int val;
    cin >> val;
    while ( val > 0 ) {
        root = insert( root, val);
        cin>>val;
    }
    cout << "Preorder Traversal:" << endl;
    preorder( root ); 
    cout << endl;
    cout << "Inorder Traversal:" << endl;
    inorder( root ); 
    cout << endl;
    cout << "Postorder Traversal:" << endl;
    postorder( root ); 
    cout << endl;
    cout << "Levelorder Traversal:" << endl;
    levelorder( root ); 
    cout << endl;
    return 0;
}
