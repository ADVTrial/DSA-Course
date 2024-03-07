#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> queue1;
    int arr[20];
    int n,i,value;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>value;
        arr[i]=value;
    }
    sort(arr,arr+n);
    int sum=arr[0];
    for(i=1;i<n;i++)
    {
        sum+=arr[i];
        queue1.push(sum);
    }
    sum=0;
    while(!queue1.empty())
    {
        sum+=queue1.front();
        queue1.pop();
    }
    cout<<sum;
    return 0;
}
