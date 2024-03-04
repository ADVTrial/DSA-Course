/*
Expression Evaluation
You are given with a Postfix Expression. Evaluate the Expression using Stack.
Example
Input
10 2 3 + *
Output
50

Explanation
exp=" 10 2 3 + * "
exp[0]="10" => push() => Stack=10
exp[1]="2" => push() => Stack=10 2
exp[2]="3" => push() => Stack=10 2 3
exp[3]="+" => pop() => Stack=10 5 (perform addition on first two top most element 3+2=5)
exp[4]="*" => pop() => Stack=50 (perform multiplication on first two top most element 10*5=50)
Print the last value 50.

Input Format
A String representing the Expression.
Output Format
Display the Result after Evaluation.

Sample Input
4 5 +
Sample Output
9
 Sample Input
10 2 3 + *
Sample Output
50
*/

#include <bits/stdc++.h>
using namespace std;
int st[100];
int top=-1;
void push(int v)
{
    st[++top]=v;
}
int pop()
{
    return st[top--];
}
int evaluatePostfix(string exp) {
    for (int i=0;i<exp.length();i++) {
        if (isdigit(exp[i])) {
            int num = 0;
            while(isdigit(exp[i]))
			{
                num=num*10 + (int)(exp[i]-'0');
				i++;
			}
			i--;
            push(num);
        }
        else if(exp[i] == ' ')
        {
            continue;
        }
        else
        {
            int operand2 = st[top];
            pop();
            int operand1 = st[top];
            pop();
            switch (exp[i])
            {
                case '+':
                	push(operand1 + operand2);break;
                case '-':
                	push(operand1 - operand2);break;
                case '*':
                	push(operand1 * operand2);break;
                case '/':
                	push(operand1 / operand2);break;
            }
        }
    }
    return st[top];
}

int main() {
    string expression;
    getline(cin, expression);
    int result = evaluatePostfix(expression);
    cout << result << endl;
    return 0;
}
