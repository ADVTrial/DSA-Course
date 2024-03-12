/*

Write a program to remove element in a binary search tree.

 Input Format
First line contains an integer, n denoting the number of nodes in a tree.

Each of the n subsequent lines contains an integer,data, denoting the value of an element that must be added to the BST.

Third line contains the element to be deleted.

 Output Format
BST with element removed.

 Sample Input  Sample Output
7
20 10 5 15 30 25 35
5
AFTER DELETION
10 15 20 25 30 35


Problem Statement
Write a program that constructs a binary search tree (BST) using a given set of integer values, deletes a specified key value, and prints the in-order traversal of the BST both before and after the deletion.

 Input Format
The first line consists of the input number of nodes, n.

The second line consists of the space-separated input node values.

The third line consists of the node value to be deleted.

 Output Format
The output prints the node values in the in-order traversal before and after the deletion of the key value.

If the key value is not present in the tree, the output prints the in-order traversal of the original tree as it is.
Refer to the sample output for formatting specifications.

 Constraints
The given test cases will fall under the following constraints.

1 ≤ n ≤ 50.

0≤key values≤105.

1≤delKey≤10^5.

 Sample Input  Sample Output
5
10 30 5 6 7
30
Before deletion of key value: 5 6 7 10 30
After deleting key value 30: 5 6 7 10
 Sample Input  Sample Output
3
10 60 20
12
Before deletion of key value: 10 20 60
After deleting key value 12: 10 20 60

*/

/*Binary Search Tree - Linked List Implementation
Input
50 25 6 75 30 60 70 52 85 -1
30
25
50

Output
Tree values are:
6 25 30 50 52 60 70 75 85
Inorder traversal after deletion of 30: 6 25 50 52 60 70 75 85
Inorder traversal after deletion of 25: 6 50 52 60 70 75 85
Inorder traversal after deletion of 50: 6 52 60 70 75 85
*/
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

Node* findMinimum(Node* current) {
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        //case 1: Delete Leaf Node
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		//case 2: Delete Node with one child
        else if (root->left == NULL)
        {
            Node* temp=root;
			root=root->right;
			delete temp;
			return root;
        }
        else if (root->right == NULL)
        {
            Node* temp=root;
			root=root->left;
			delete temp;
			return root;
        }
        //case 3: Delete Node with 2 child
        else
        {
            Node* temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, val;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        root = insert( root, val);

    }
    /*
    while ( val > 0 ) {
        root = insert( root, val);
        cin>>val;
    }
    cout << "Tree values are:" << endl;
    inorder( root );
    cout << endl;
    */
    int key;
    cin>>key;
    cout << "Before deletion of key value: ";
    inorder(root);
    cout << endl;
    root = deleteNode(root, key);
    cout << "After deleting key value "<< key <<": ";
    inorder(root);
    cout << endl;
    /*
    int key;
    cin>>key;
    root = deleteNode(root, key);
    cout << "AFTER DELETION\n";
    inorder(root);
    cout << endl;
    /*
    cin>>key;
    root = deleteNode(root, key);
    cout << "Inorder traversal after deletion of " << key << ": ";
    inorder(root);
    cout << endl;

    cin>>key;
    root = deleteNode(root, key);
    cout << "Inorder traversal after deletion of " << key << ": ";
    inorder(root);
    cout << endl;
    */
    return 0;
}
