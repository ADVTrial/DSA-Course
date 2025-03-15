/*Search of a Key in BST*/
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
bool searchBST(Node *temp, int key)
{
    if( temp == NULL)
        return false;

    if(temp->data == key)
        return true;
    else if(key < temp->data)
        return searchBST(temp->left, key);
    else
        return searchBST(temp->right, key);
}
//--------------------or-------------------
bool searchLoopBST(Node* root, int key)
{
    Node *temp = root ;
    while(temp != NULL)
    {
        if(temp->data == key)
            return true ;
        if( key < temp->data)
            temp = temp->left ;
        else
            temp = temp->right ;
    }
    return false ;
}

int main() {
    Node* root = NULL;
    int val;
    cin >> val;
    while ( val > 0 ) {
        root = insert( root, val);
        cin>>val;
    }
    int key;
    cin >> key;
    bool found = searchBST(root, key);
    if (found)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
