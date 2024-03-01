/*
Problem statement

Kiran collects tokens at a museum. But the visitors do not come in the order of token 
numbers and hence the tokens are always jumbled. On the back of every token, 
he has to write the next greater token number when his shift ends. 
If he could not find the appropriate number, -1 is written.

But he found this process time consuming as he has to manually find the greater number. 
Kiran is also a part-time programmer. So, he decided to implement this process in a 
program using stacks. 

Example
Input
5
2 7 10 19 1

Output
2 7
7 10
10 19
19 -1
1 -1

Explanation
For 2, the next greater is 7
For 7, the next greater is 10
For 10, the next greater is 19
For 19, there is no next greater element so -1
For 1, there is no next greater element so -1.

Input Format 
The first line of input contains the length N of array a , followed by a single space N space separated Integers in the separate line

Output Format 
Prints the next greater element for each value in array, if there is no greater element print -1.

Constraints 
1 < N < 105 
1 < a1 , a2 , a3 . . . . aN-1 < 107

Sample Input  
5
2 7 10 19 1
Sample Output 
2 7
7 10
10 19
19 -1
1 -1

Sample Input 
4
3 5 2 8 
Sample Output 
3 5
5 8
2 8
8 -1
*/

#include<iostream> 
using namespace std; 
  
void printNextGE(int arr[], int n) 
{ 
    int next, i, j; 
    for (i = 0; i < n; i++) 
    { 
        next = -1; 
        for (j = i + 1; j < n; j++) 
        { 
            if (arr[i] < arr[j]) 
            { 
                next = arr[j]; 
                break; 
            } 
        } 
        cout << arr[i] << " " << next << endl; 
    } 
} 

int main() { 
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    printNextGE(arr, n); 
    return 0; 
}

/*
or
// You are using GCC
#include<iostream>
using namespace std;
#define size 100
int st[size];
int top=-1;
void push(int n)
{
    st[++top]=n;
}
void pop()
{
    top--;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        push(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=i+1;j<n;j++)
        {
            if(st[i]<st[j])
            {
                cout<<st[i]<<" "<<st[j]<<endl;
                c=1;
                break;
            }
        }
        if(c==0)
           cout<<st[i]<<" "<<-1<<endl;
    }
}



*/

