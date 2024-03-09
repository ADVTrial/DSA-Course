/*Binary Search Tree - Linked List Implementation - Height, FindMin, FindMax*/
#include <iostream>
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
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int getHeight(Node* root) {
    if (root == NULL) 
    {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int findMaximum(Node *curr)
{
    while(curr->right!=NULL)
    {
        curr = curr->right;
    }
    return (curr->data);
}

int findMinimum(Node *curr)
{
    while(curr->left!=NULL)
    {
        curr = curr->left;
    }
    return (curr->data);
}

int main() {
    Node* root = NULL;
    int val;
    cin >> val;
    while ( val > 0 ) {
        root = insert( root, val);
        cin>>val;
    }
    cout << "Tree values are:" << endl;
    inorder( root );
    cout << "\nMaximum element is "<< findMaximum( root ) <<endl;
    cout << "Minimum element is "<< findMinimum( root ) << endl;
    int height = getHeight(root);
    cout << height << endl;
    return 0;
}
