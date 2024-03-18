/*
Write a program to implement the linear probing hashing to insert an element into hash table.

Note

Use hash function as arr[i]%n [n -number of elements]

Number of  element to be insert is same as size of hash table

Example

Input

5 // Table size and number of element to be insert

5 6 4 8 12

Output

5 6 12 8 4 

Explanation

Use above hash function to store value inside hash table. Print the value from zeroth index.

 Input Format 
First input N denotes the number of elements , next N number of input separated by space is an array elements.

 Output Format 
Single line output separated by space print the Hash table.

 Constraints 
Integers only.

 Sample Input  
5 
5 6 4 8 12
Sample Output 
5 6 12 8 4 
 Sample Input 
7
13 22 14 26 37 44 69
Sample Output 
14 22 37 44 69 26 13
*/

/*Collision Resolution using Open Addressing/Closed Hashing - Linear Probing Technique*/
#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    int a[n];
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        h[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        k=a[i]%n;
        while (h[k]!=-1)
        {
            k++;
            if(k>=n)
                k=0;
        }
        h[k]=a[i];
    }
    for(int i=0;i<n;i++)
    { 
        cout<<h[i]<<" ";
    }
    return 0;
}

/*
or
/*Hashing - Collision Resolution Technique - Linear Probing*/
#include<iostream>
using namespace std;
int main()
{
    int n, x, k;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++)
    {
        h[i]=-1;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        k = x % n;
        while ( h[k] != -1 )
        {
            k++;
            if(k >= n)
            {
               k = 0; 
            }
        }
        h[k] = x;
    }
    for(int i = 0; i < n; i++)
    {
        cout << h[i] << " ";
    }
    return 0;
}
*/
