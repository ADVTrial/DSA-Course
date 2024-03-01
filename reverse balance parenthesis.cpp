/*
Reverse to Balance Parenthesis

Given a string S consisting only of opening and closing curly brackets '{' and '}' find out the minimum number of reversals required to make a balanced expression.

A Balanced Expression is one where Each ‘{‘ has a corresponding ‘ }’ and all curly brackets inside it are also balanced.

Example

Input1

{{}{{}

Output1

1

Explanation

To balance the given expression reverse one open parenthesis to closed parenthesis (i.e. {{}}{} )to make it a balanced one, thus print 1.

Example

Input

}}{}{}{}{{{}}

Output2

-1

Explanation

The string's length is 13, which is an odd number, thus print -1.

 Input Format
String consisting of opening and closing curly brackets in first line

 Output Format
Print out minimum reversals required to make S balanced. If the length of the string is odd print -1. If it is already balanced print 0.

 Constraints
String > 0

String < 100.

 Sample Input  Sample Output
{{}{{}
1
 Sample Input  Sample Output
}}{}{}{}{{{}}
-1
 Sample Input  Sample Output
{{}}{}
0
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int minReversalsToBalance(string expr) {
    int len = expr.length();
    // If the length of the string is odd, it can't be balanced
    if (len % 2 != 0)
    {
        return -1;
    }

    stack<char> st;

    for (int i = 0; i < len; ++i)
    {
        char current = expr[i];
        if (current == '}' && !st.empty())
        {
            if (st.top() == '{') {
                st.pop(); // If matched, remove the corresponding '{'
            }
            else {
                st.push(current); // Unmatched '}' - push it
            }
        }
        else
        {
            st.push(current); // For '{', directly push it onto the stack
        }
    }

    // At this point, the stack contains mismatched braces
    int unbalancedCount = 0;
    while (!st.empty())
    {
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();

        // Two unmatched braces are at the top of the stack
        // Reversing them will balance the expression
        if (c1 != c2)
        {
            unbalancedCount += 2;
        }
        else
        {
            unbalancedCount++;
        }
    }
    return unbalancedCount;
}

int main() {
    string input;
    cin >> input;
    int minReversals = minReversalsToBalance(input);
    cout << minReversals << endl;
    return 0;
}


