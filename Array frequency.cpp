/*
Frequent Element in an Array
Problem Statement
Given an list of values , find the most frequent element in it. If there are multiple elements that appear maximum number of times, print first one that appears in the array index of them. Use hashing technique.
Note 
Process input in chronological order

Example1
Input1
5
1 2 1 1 2
Output1
1
Explanation
1 occurred maximum number of time in the list.

Example2

Input2
5
4 4 3 3 5 

Output2
3

Explanation
The number 3 and 4 occurred the most in the list, however the input should be processed in chronological order, so 3 is printed.

 Input Format 
First line has the number of elements and the second line has the array elements separated by space.

 Output Format 
Output displays the frequently occurring element.

 Sample Input  
5
1 2 1 1 2
Sample Output 
1
 Sample Input  
5
4 4 3 3 5 
Sample Output 
3
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int freq[100]={0};
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int large = freq[0];
    int index = 0;
    for (int i = 1; i < 100; ++i) {
        if(freq[i]>large)
        {
            large = freq[i];
            index = i;
        }
    }
    cout<<index;
    return 0;
}
