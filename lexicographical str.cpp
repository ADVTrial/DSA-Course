/*
Problem Statement
Give a string, remove duplicate letters from the string s such that each letter appears just once using Stack. The lexicographical order of your result must be the least of all feasible outcomes.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

 Input Format 
The Input is a String

 Output Format 
The Output is the lexicographical order of string with unique characters.

Refer to the sample input and output for formatting specifications.

 Constraints 
1 <= s.length <= 104
s consists of lowercase English letters.

Input: asdfghjklpoiuyrhfbnghwieyrtgvhbvcfdghystrgbcksldkh
Output: adfghjklpoiubnwertvcys

Input: xmnmcnvnjsudhfsdnfsdsjdfjdfum
Output: xcnvdhfsjum

Input: aslkddjfkdkfjidjnfjdsnf
Output: aldfkijns
*/
#include <iostream>
#include <stack>
using namespace std;
string removeDuplicateLetters(string s) 
{
    stack<char> stk;
    int lastOccurrence[26];
    bool visited[26] ={false};
    
    // Count the last occurrence of each character in the string
    for (int i = 0; i < s.length(); ++i) 
    {
        lastOccurrence[s[i]-'a'] = i;
    }
    
    for (int i = 0; i < s.length(); ++i) 
    {
        char currChar = s[i];
        
        // Skip if the character is already visited
        if (visited[currChar-'a']) 
            continue;
        
        // Pop characters from the stack if:
        // 1. The stack is not empty
        // 2. The current character is less than the top of the stack
        // 3. The last occurrence of the character in the string is greater than the current index
        while (!stk.empty() && currChar < stk.top() && lastOccurrence[stk.top()-'a'] > i) 
        {
            visited[stk.top()-'a'] = false;
            stk.pop();
        }
        
        // Push the current character onto the stack and mark it as visited
        stk.push(currChar);
        visited[currChar-'a'] = true;
    }
    // Construct the result string from the stack
    string result = "";
    while (!stk.empty()) 
    {
        result = stk.top() + result;
        stk.pop();
    }
    return result;
}

int main() {
    string str;
    cin >> str;
    cout << removeDuplicateLetters(str);
    return 0;
}
