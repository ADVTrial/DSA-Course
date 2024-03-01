/*
Write a program to print all the factors of a number using stack through array implementation.

 Input Format 
First line of the input is a Number

 Output Format 
Print all the factors of the number separated by space

 Constraints 
0<N<999999

 Sample Input 
5
 Sample Output 
5 1 
 Sample Input 
200
 Sample Output 
200 100 50 40 25 20 10 8 5 4 2 1 
 Sample Input 
-1
 Sample Output 
WRONG INPUT

*/

#include <iostream>
#include <stack>
using namespace std;
const int MAX_SIZE = 1000;

void printFactors(int num) {
    if (num < 1 || num >= MAX_SIZE) 
    {
        cout << "WRONG INPUT";
        return;
    }
    stack<int> st; // Stack to store factors
    for (int i = 1; i <= num; ++i) 
    {
        if (num % i == 0)
        {
            st.push(i); // Push the factor
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main() 
{
    int num;
    cin >> num;
    printFactors(num);
    return 0;
}
