/*Book Shelf - Stack Implementation
Problem statement

Books in a shelf are arranged in such a way that the starting letters of their titles are displayed in front of it. Based upon these letters, students can easily identify the books they are in search of. One fine day, some students find that the books are arranged in reversed order. However, they are unable to understand the process behind the arrangement.

One student suggested that since books are usually arranged in the form of stacks, the reversal will be in the LIFO format. Another student mentioned that first letters of the books formed an array of characters which is now seen in the reversed form. Help the students by writing a code by combining the two given findings to arrive at the algorithm for the rearrangement.

Example

Input

JNCAB

Output

BACNJ

Explanation

letter="JNCAB"
letter[0]="J" => push() => Stack=J
letter[1]="N" => push() => Stack=JN
letter[2]="C" => push() => Stack=JNC
letter[3]="A" => push() => Stack=JNCA
letter[4]="B" => push() => Stack=JNCAB
Now, one by one, pop() and print the top-most elements.

Input Format
A single line of input which has the original set of starting letters s.

 Output Format
Display the reversed letters that matches the rearranged set of books

 Constraints
1 < s < 100

*/
#include<iostream>
#include<cstring>
#define SIZE 100
using namespace std;
char stack[SIZE];
int top=-1;
void push(char value)
{
    stack[++top] = value;
}
void pop()
{
    cout<<stack[top--];
}
int main()
{
    string val;
    getline(cin,val);
    int len=val.length();
    for(int i=0;i<len;i++)
        push(val[i]);
    for(int i=0;i<len;i++)
        pop();
    return 0;
}
/*
INPUT
DEFG CVDF
OUTPUT
FDVC GFED
*/

