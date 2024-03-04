/*
Length of longest balanced parenthesis

Write a program to find the longest length of balanced parenthesis.

 Input Format 
The input consists of a parenthesis of type string.

 Output Format 
The output consists of the longest length of a balanced parenthesis.

 Sample Input  Sample Output 
()()
Sample Output 
4
 Sample Input  
((()()()()))
Sample Output 
12
*/
/*Length of longest balanced parenthesis*/
#include<iostream>
#include<cstring>
#define SIZE 100
using namespace std;
char stack[SIZE];
int top=-1;
int IsEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(char value)
{
   stack[++top] = value;
}
bool pop()
{
    if(IsEmpty())
    {
        return false;
    }
    else{
        top--;
        return true;
    }
}
int findmaxlen(string s)
{
    int maxLength = 0;
    int newLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            push(s[i]);
        }
        else
        {
            if(pop()) // Remove the top '(' from stack for ')'
                maxLength=maxLength+2;
            else
	    {
                newLen=max(newLen,maxLength);
		maxLength = 0;
	    }	
        }
    }
    maxLength=max(newLen,maxLength);
    return maxLength;
}
int main()
{
    char val[100];
    cin>>val;
    int len=findmaxlen(val);
    cout<<len;
    return 0;
}


