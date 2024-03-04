/*
Balance Parentheses

Given an expression string exp, write a program to examine whether the pairs and the orders of "{", "}", "(", ")", "[", "]" are correct in exp.

Example
Input1
{()}[]
Output1
True

Explanation
exp={()}[]
exp[0]="{" => push() => Stack={
exp[1]="(" => push() => Stack={(
exp[2]=")" => pop() =>"(" => Stack={
exp[3]="}" => pop() =>"{" => Stack empty
exp[4]="[" => push() => Stack=[
exp[5]="]" => pop() =>"[" => Stack empty
The stack is empty after processing the expression, thus output "True."

Input2
[(])
Output2
False

Explanation
exp=[(])
exp[0]="[" => push() => Stack=[
exp[1]="(" => push() => Stack=[(
exp[2]="]" => Parenthesis are not matched. top of the stack should have "[" to perform pop() operation.
Stack is not empty so print False.

Input Format
Input consists of a String exp.

Output Format
Print True for Balanced and False for Unbalanced.
*/

#include <iostream>
using namespace std;
char st[100];
int top=-1;
void push(char c)
{
    st[++top]=c;
}
void pop()
{
    top--;
}
bool isBalanced(string exp) {
    for (char ch : exp)
    {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top==-1) {
                return false; // Unmatched closing bracket
            }
            if ((ch == ')' && st[top] == '(') || (ch == '}' && st[top] == '{') || (ch == ']' && st[top] == '[')) {
                pop();
            }
            else {
                return false; // Mismatched opening and closing brackets
            }
        }
    }
    return true;
}

int main() {
    string input;
    cin >> input;
    bool balanced = isBalanced(input);
    if (balanced) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    return 0;
}
