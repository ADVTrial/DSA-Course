/*
Problem statement
Write a program to convert the given infix expression to postfix expression.
Example
Input
a+b
Output
ab+
Explanation
Postfix representation of (a+b) is ab+
Input Format 
String input representing infix expression
Output Format 
Postfix representation of the given infix expression
Constraints 
Operators used are +, -, *, /, and ^ only

Sample Input   
a+b*(c^d-e)^(f+g*h)-i
Sample Output
abcd^e-fgh*+^*+i-
Sample Input  
(a+b)*(c^d+e)^(f+g)*h
Sample Output
ab+cd^e+fg+^*h*
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1; // Lower precedence
}

string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix;

    for (char c : infix)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >='0' && c <= '9')) {
            postfix += c; // Operand, add to postfix expression
        } 
	else if (c == '(') {
            operators.push(c); // Left parenthesis, push to stack
        } 
	else if (c == ')') 
	{
            while (!operators.empty() && operators.top() != '(') 
	    {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Discard the '('
        }
        else if (isOperator(c))
        {
            while (!operators.empty() && getPrecedence(c) <= getPrecedence(operators.top())) 
	    {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) 
    {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main() 
{
    string infix_expr;
    cin >> infix_expr;
    string postfix_expr = infixToPostfix(infix_expr);
    cout <<postfix_expr << endl;
    return 0;
}
