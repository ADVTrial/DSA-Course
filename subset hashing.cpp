/*
Subset using Hashing
Write a program to find whether the array is a subset or not using Hashing technique.
Example
Input
6
4
11 1 13 21 3 7
11 3 7 1

Output
Subset

Explanation
Since all of the values in the second list are also present in the first list, it is a subset.

 Input Format 
Input consists of integer 'm' followed by integer 'n' denoting the size of array arr1 and arr2 respectively, followed by 'm' number of array elements of arr1, followed by 'n' number of array elements of arr2.

 Output Format 
Output displays a message indicating whether the arr2 of subset or arr1 or not.

 Sample Input
6
4
11 1 13 21 3 7
11 3 7 1
Sample Output 
Subset
 Sample Input  
6
5
11 1 13 21 3 7
11 3 7 1 19
Sample Output 
Not a subset

*/

/*Subset using Hashing*/
#include <iostream>
using namespace std;
int main()
{
    int m,n,k,x;
    cin>>m>>n;
    int h[m];
    for(int i=0;i<m;i++)
    {
        h[i]=-1;
    }
    for(int i=0;i<m;i++)
    {
        cin>>x;
        k = x % m;
        while (h[k]!=-1)
        {
            k++;
            if(k>=m)
            {
                k=0;
            }
        }
        h[k]=x;
    }
    int t,count=0;
    for(int i=0;i<n;i++)
    {    
        cin>>t;
        k= t % m;
        if(h[k]!=-1 && h[k]==t) //direct mapping
        { 
            count++; 
        }
        else //collision occured
        {
            for(int i=0;i<m;i++)
            { 
                if(h[i]==t)
                {
                    count++;
                    break;
                }
            }
        }
    }
    if(count==n)
        cout<<"Subset";
    else
        cout<<"Not a subset";
    return 0;
}