/*
Count the frequency of alphabetical characters in the given string using hashing technique. Special characters and white spaces are not taken into account. Make sure that time complexity of your code does not exceed O(N). Where, N is the length of the string. Capital and small alphabets are treated as same.

Example

Input

APple

Output

a - 1

e - 1

l - 1

p - 2

Explanation

In chronological order, display the character and the frequency of occurrence of each character.

 Input Format 
Input consists of a string.

 Output Format 
Output displays the frequency of each character in the string.

 Sample Input 
APple
Sample Output 
a - 1
e - 1
l - 1
p - 2
 Sample Input  
Placement Season
Sample Output 
a - 2
c - 1
e - 3
l - 1
m - 1
n - 2
o - 1
p - 1
s - 2
t - 1
*/
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string str;
    getline(cin, str);
    int frequency[26]={0};
    for (char ch : str) 
    {
        if (isalpha(ch)) 
        {
            ch = tolower(ch); // Convert to lowercase to treat capital and small letters as the same
            int index = ch - 'a';
            frequency[index]++;
        }
    }
    for (int i=0; i<26; i++) 
    {
        if (frequency[i] > 0) 
        {
            char ch = 'a' + i;
            cout << ch << " - " << frequency[i] << endl;
        }
    }
    return 0;
}