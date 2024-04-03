/*
You are given an array of integers, and you need to find the largest rectangular area in the histogram that can be formed using these integers. The histogram is represented by an array of integers, where each element represents the height of the bar. The width of each bar is assumed to be 1.

For example, if the input array is [6, 2, 5, 4, 5, 1, 6], the largest rectangular area that can be formed is 12, which is the area formed by the bars with heights 5, 4, and 3.

Check for Diagram => Histogram max area

 Input Format 
The first line of input specifies the length of the array.

The second line of input specifies space-separated array values.

 Output Format 
The output prints the largest rectangular area formed with the input values.

 Constraints 
The maximum height is 100000.

 Sample Input 
7
6 2 5 4 5 1 6
Sample Output
12
 Sample Input 
4
2 1 3 5
Sample Output
6
 Sample Input   
6
3 5 1 7 5 9
Sample Output
15
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();
    int i = 0;
    while (i < n) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i++);
        } else {
            int tp = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[tp] * width);
        }
    }
    while (!s.empty()) {
        int tp = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, heights[tp] * width);
    }
    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
