/*
Mr.john is doing a transport business. As he had a lot of customers for registering the car, he wants to give the preference for the person who comes first, if the car is filled with n number after that who comes with EVEN is added and the first element is removed .If  ODD means do nothing.

 Input Format 
The first line of input denotes seats N available in the car.

The next line of input contains total number of registered members M , followed by M space-separated integers.

 Output Format 
Print the members in the car separated by a space. 

﻿If M < 1 and N < 1, print -1.

 Constraints 
1 < M < N

 Sample Input  Sample Output 
5 
8 
2 4 3 5 6 1 10 12
Sample Output 
3 5 6 10 12 
 Sample Input  
2
5 
10 23 44 56 43
Sample Output 
44 56 
*/
#include <iostream>
#include <queue>
using namespace std;

void prioritizeMembers(int seats, int total, int members[]) {
    queue<int> car;
    for (int i = 0; i < total; ++i) 
    {
        if (car.size() < seats) {
            cout<<car.size()<<endl;
            car.push(members[i]);
        } 
        else {
            if (members[i] % 2 == 0) {
                car.pop();
                car.push(members[i]);
            }
        }
    }
    
    while (!car.empty()) {
        cout << car.front() << " ";
        car.pop();
    }
}

int main() {
    int seats, total;
    cin >> seats >> total;

    int members[total];
    for (int i = 0; i < total; ++i) {
        cin >> members[i];
    }

    prioritizeMembers(seats, total, members);

    return 0;
}
------------  or   ------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int carseat, tickets;
    int arr[50];
    cin >> carseat >> tickets;
    queue<int> q;
    for(int i=0; i<tickets; i++)
        cin >> arr[i];
    for(int i=0; i<carseat; i++)
        q.push(arr[i]);
    for(int i=carseat; i<tickets; i++)
    {
        if(arr[i]%2 == 0)
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}