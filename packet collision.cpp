/*
Packet Collision

A network user attempted to send multiple data packets with frame size 'k' at the same time. Due to a network fault, all packets in each frame with a higher sequence number crashed. To resend the packet, the sender must now find the maximum sequence number data packet in each frame with size 'k'.

Example

Input
6
21 34 5 6 12 23
3

Output
34 34 12 23 

Explanation

Frame size =3
First Data transmission: 21 34 5 => 34
Second Data transmission: 34 5 6 => 34
Third Data transmission: 5 6 12 => 12
Fourth Data transmission: 6 12 23 => 23

Input Format :
First input represent number of data packets to be sent
Next n number of input represents sequence number
Followed by frame size (k).

Output Format :
Refer sample output

Sample testcases :
Testcase 1 Input
6
21 34 5 6 12 23
3
Testcase 1 Output
34 34 12 23 

Testcase 2 Input
5
12 34 56 78 89
2
Testcase 1 Output
34 56 78 89 
*/
/*Packet Collision - Queue*/
#include <iostream>
using namespace std;

void printKMax(int arr[], int n, int k) {
    int j, max;
    for (int i = 0; i <= n - k; i++) {
        max = arr[i];
        for (j = 1; j < k; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;
    printKMax(arr, n, k);
    return 0;
}

/*
--------------or------------
Packet Collision - Max Priority Queue
int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    for(int i=0; i <= n-k; i++)
    {
        priority_queue<int> pq;
        for(int j=0; j<k; j++)
        {
            pq.push(arr[i+j]);
        }
        cout<<pq.top()<<" ";
    }
    return 0;
}
*/
