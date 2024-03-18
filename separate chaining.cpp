/*
Write a program to implement hashing by using separate chaining.

Note: consider the table size as 3.

 Input Format 
The first line of the input consists of the value of n.

The next inputs are the elements.

 Output Format 
The output prints the table.

Refer sample input and output for formatting specifications.

 Sample Input   
5
10 12 6 24 31
Sample Output
chain[0]-->12 -->6 -->24 -->NULL
chain[1]-->10 -->31 -->NULL
chain[2]-->NULL

 Sample Input  
8
10 12 6 24 31 35 42 50
Sample Output
chain[0]-->12 -->6 -->24 -->42 -->NULL
chain[1]-->10 -->31 -->NULL
chain[2]-->35 -->50 -->NULL
*/
/*Hashing using separate chaining */
#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, key, index;;
    cin >> n;
    const int size = 3; 
    list<int> table[size];

    for (int i = 0; i < n; ++i) 
    {
        cin >> key;
        index = key % size;
        table[index].push_back(key);
    }
    for (int i = 0; i < size; ++i) 
    {
        cout << "chain[" << i << "]-->";
        for (auto value : table[i]) 
        {
            cout << value << " -->";
        }
        cout << "NULL\n";
    }
    return 0;
}

