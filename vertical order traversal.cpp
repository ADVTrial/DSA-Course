/*
Binary Search Tree - Vertical Order Traversal
Create a binary search tree consisting of only positive values & print the vertical order traversal of the tree.
Note
An infinite line of integer input representing the nodes of the binary search tree. If any value less than 1 is encountered, the input loop has to break and print the common ancestor for the given nodes in the tree. 

Example
Input
10
5
15
7
17
2
12
0

Output
2 
5 
10 7 12 
15 
17 

Explanation
The vertical order traversal flows from the leftmost node to the rightmost node in the specified order. 

 Input Format 
Read a line of integers.

 Output Format 
The Vertical order traversal of the BST.

 Sample Input
10
5
15
7
17
2
12
0
 Sample Output 
2 
5 
10 7 12 
15 
17 
 Sample Input 
10
8
5
7
17
22
12
0
 Sample Output 
5 
8 7 
10 12 
17 
22 

*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void verticalOrderTraversal(Node* root) {
    if (root == nullptr) return;

    map<int, vector<int>> verticalOrderMap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        Node* node = curr.first;
        int hd = curr.second;

        verticalOrderMap[hd].push_back(node->data);

        if (node->left != nullptr) {
            q.push({node->left, hd - 1});
        }
        if (node->right != nullptr) {
            q.push({node->right, hd + 1});
        }
    }

    for (auto it = verticalOrderMap.begin(); it != verticalOrderMap.end(); ++it) {
        for (int i = 0; i < it->second.size(); ++i) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int val;
    Node* root = nullptr;

    while (true) {
        cin >> val;
        if (val < 1) break;
        root = insert(root, val);
    }

    verticalOrderTraversal(root);

    return 0;
}

/*
or

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->data = val;
        left =right=NULL;
    }
};

Node* insert(Node* root,int val)
{
    Node* newnode = new Node(val);
    if(root==NULL)
    {
        return newnode;
    }
    else if(val>root->data)
    {
        root->right = insert(root->right,val);
    }
    else if(val<root->data)
    {
        root->left = insert(root->left,val);
    }
    return root;
}

void getvertrav(Node* root,map<int,vector<int>> &map,int ver)
{
    if(root==NULL)
    {
        return;
    }
    
    map[ver].push_back(root->data);
    
    if(root->left!=NULL)
    {
        getvertrav(root->left,map,ver-1);
    }
    if(root->right!=NULL)
    {
        getvertrav(root->right,map,ver+1);
    }
}

int main()
{
    int val;
    Node* root = NULL;
    while(cin>>val)
    {
        if(val<1)
        {
            break;
        }
        root = insert(root,val);
    }
    
    map<int,vector<int>> vert_trav;
    int ver = 0;
    
    getvertrav(root,vert_trav,ver);
    
    map<int,vector<int>>:: iterator it;
    
    for(it = vert_trav.begin();it!=vert_trav.end();it++)
    {
        vector<int> temp = it->second;
        //sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    }
}
*/

