/*
Ankit along with Karthick has opened new PVC pipe shop. They have 3 stacks of cylindrical pipes where each pipe has the equal diameter, but they may vary in height. They can change the height of a stack by removing and discarding its topmost pipe any number of times.



Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means they must remove zero or more cylindrical pipes from the top of zero or more of the three stacks until they're all the same height, and then print the height. The removals must be performed in such a way as to maximize the height. Also, remember, an empty stack is still a stack.



Karthick is not clear about this arrangement. So Ankit, explained with an example. (Refer Sample Input)

There are 3 stacks with different height. To make all stacks of equal height, they remove the first two cylinders from stack 1 and one cylinder each from stack 2 and 3.



 Input Format 
The 1st line contains three space-separated integers N1, N2 and N3 (i.e Number of pipes in stacks 1,2 ,3 )

The 2nd line contains N1 space-separated integers describing the pipe heights in stack 1. The first element is the top of the stack.

The 3rd line contains N2 space-separated integers describing the pipe heights in stack 2. The first element is the top of the stack.

The 4th line contains N3 space-separated integers describing the pipe heights in stack 3. The first element is the top of the stack.

 Output Format 
Display the maximum height at which all stacks will be of equal height.

 Sample Input  
4 3 5
1 1 4 1
4 3 2
3 2 1 1 1
Sample Output 
5
*/

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int N1, N2, N3;
    cin >> N1 >> N2 >> N3;
    vector<int> stack1(N1), stack2(N2), stack3(N3);
    for (int i = 0; i < N1; ++i) 
        cin >> stack1[i];
    for (int i = 0; i < N2; ++i) 
        cin >> stack2[i];
    for (int i = 0; i < N3; ++i) 
        cin >> stack3[i];

    // Calculating sum of each stack
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int height : stack1) 
        sum1 += height;
    for (int height : stack2) 
        sum2 += height;
    for (int height : stack3) 
        sum3 += height;

    // Finding the maximum possible height at which all stacks will be of equal height
    int idx1 = 0, idx2 = 0, idx3 = 0;
    while (true) 
    {
        // If any stack is empty, break
        if (idx1 == N1 || idx2 == N2 || idx3 == N3) 
            break;

        // If all stacks are equal in height, break
        if (sum1 == sum2 && sum2 == sum3) 
            break;

        // Find the shortest stack and adjust the index accordingly
        int shortest = min(min(sum1, sum2), sum3);
        if (sum1 > shortest) {
            sum1 -= stack1[idx1++];
        }
        if (sum2 > shortest) {
            sum2 -= stack2[idx2++];
        }
        if (sum3 > shortest) {
            sum3 -= stack3[idx3++];
        }
    }
    // Output the maximum height at which all stacks will be of equal height
    cout << min(min(sum1, sum2), sum3) << endl;
    return 0;
}
