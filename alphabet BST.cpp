/*
Geetha wants to insert the alphabets in a BST irrespective of their cases(i.e treat upper and lower cases equally). Then later, she wants to print the upper case letters in ascending order and the lower case letters in descending order. Help Geetha to write a suitable program to complete this task.

 Input Format 
First line of input is a number of elements(N) in BST

N number of elements in second line separated by space

 Output Format 
Upper case letters in ascending order

Lower case letters in descending order

 Constraints 
Only alphabets

 Sample Input  
12
s B X i V d a M l Z r f
Sample Output 
B M V X Z 
s r l i f d a
*/

#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, char data) {
    if (root == NULL)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (tolower(data) <= tolower(root->data))
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void InOrderUpper(Node* root) 
{
    if (root != NULL)
    {
        InOrderUpper(root->left);
        if (isupper(root->data))
            cout << root->data << " ";
        InOrderUpper(root->right);
    }
}

void InOrderLower(Node* root) 
{
    if (root != NULL)
    {
        InOrderLower(root->right);
        if (islower(root->data))
            cout << root->data << " ";
        InOrderLower(root->left);
    }
}

int main() {
    Node* root = NULL;
    int N;
    char data;
    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        cin >> data;
        root = insert(root, data);
    }
    InOrderUpper(root);
    cout << endl;
    InOrderLower(root);
    cout << endl;
    return 0;
}
