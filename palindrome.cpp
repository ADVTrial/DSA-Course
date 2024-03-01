/*
Palindrome Using Stack
Write a program to check whether the string is palindrome or not using Stack.
Example
Input
malayalam
Output
malayalam is palindrome

Explanation
Push the string into the stack, then invert the string by popping the characters.
Compare the two strings and print a palindrome if they are the same otherwise not a palindrome.

Input Format
Input consist of a string
Output Format
Output prints whether the string is palindrome or not

Sample Input
malayalam
Sample Output
malayalam is palindrome
Sample Input
raser
Sample Output
raser is not a palindrome
*/
#include<iostream>
using namespace std;
char stack[50];
int top=-1;
void push(char value)
{
    stack[++top] = value;
}
void pop()
{
    top--;
}
int main()
{
    string str;
    getline(cin,str);
    bool palin=true;
    int len=str.length();
    for(int i=0;i<len;i++)
        push(str[i]);
    for(int i=0;i<len;i++)
    {
        if(str[i]==stack[top])
        {
            pop();
        }
        else
        {
            palin=false;
            break;
        }

    }
    if(palin)
        cout<<str<<" is palindrome";
    else
        cout<<str<<" is not a palindrome";
    return 0;
}
