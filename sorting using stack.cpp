/*
Write a program to sort the set of elements in descending order using stack.

 Input Format 
Number of elements in first line

Stack elements in second line separated by space

 Output Format 
Elements in descending order separated by space

 Sample Input  
5
8 10 4 2 7
 Sample Output 
10 8 7 4 2 
*/
/*Sort in Descending order using stack*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void sortStack(stack<int> &st) {
    vector<int> v;
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    sort(v.begin(), v.end(), less<int>());
    for (int num : v) {
        st.push(num);
    }
}

int main() {
    int n,val;
    cin >> n;
    stack<int> elements;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        elements.push(val);
    }
    sortStack(elements);
    while (!elements.empty()) {
        cout << elements.top() << " ";
        elements.pop();
    }
    cout << endl;
    return 0;
}
