/*
Max PRIORITY QUEUE - Largest Number = Highest Priority
Min PRIORITY QUEUE - Smallest Number = Highest Priority

Priority Queue

Problem Description
Write a C++ program to implement the priority queue.

 Input Format 
The first input represents the number of values to be inserted.
The second input represents the values to be inserted in a priority queue.

 Output Format 
Refer the Sample Output

 Constraints 
1 <= n <= 100
1 <= a[i] <= 1000

 Sample Input  
5
6 2 4 3 5
Sample Output 
The priority queue elements are:
6 5 4 3 2 

 Sample Input  
4
8 1 3 2
Sample Output 
The priority queue elements are:
8 3 2 1 
*/
#include <iostream>
#include <queue>
using namespace std;
int main() 
{
    int n;
    cin >> n;
    int values[n];
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    priority_queue<int, vector<int>, less<int>> pq;      //Max Priority Queue
    //priority_queue<int, vector<int>, greater<int>> pq; //Min Priority Queue
    for (int i = 0; i < n; ++i) {
        pq.push(values[i]);
    }
    cout << "The priority queue elements are:" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}
