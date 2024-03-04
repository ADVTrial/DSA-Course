/*
Raja bought a packet of cream biscuits and brought it home by cycle. While coming, he dropped the biscuit packet. All biscuits were broken except the middle one when he opened the pack. Now, help Raja to pick the middle one.



Refer to the sample input and output if the number of biscuits is even.



Use the stack concept

 Input Format 
The first line of input should contain the array size

The second line of input contains array of elements

 Output Format 
The output should print the middle element

 Sample Input
5
1 2 3 4 5
Sample Output
1 2 4 5 
 Sample Input   
4
1 2 3 4
Sample Output
1 3 4 
*/

/*Removing Middle Element Using Stack*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printMiddle(stack<int> s, int size) 
{
    vector<int> v;
    int middle = size / 2;
    for (int i = 0; i < middle; ++i) 
    {
        v.push_back(s.top());
        s.pop();
    }
    s.pop(); // Remove the middle element
    while (!s.empty()) 
    {
        v.push_back(s.top());
        s.pop();
    }
    for (int i = 0; i < v.size(); ++i) 
    {
        s.push(v[i]);
    }
    while (!s.empty()) 
    {
        cout << s.top() <<" ";
        s.pop();
    }
    cout << endl;
}

int main() 
{
    int n,val;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; ++i) 
    {
        cin >> val;
        st.push(val);
    }
    printMiddle(st, n);
    return 0;
}

