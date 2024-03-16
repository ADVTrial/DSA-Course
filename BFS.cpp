/*
Problem statement
Given a directed graph. The task is to do a Breadth-First Search of this graph.
Example
Input
1
5 4
0 1 0 2 0 3 2 4
Output
0 1 2 3 4 
Explanation
V = 5, E = 4
0 1
0 2
0 3
2 4

For the given graph, the BFS is
0 1 2 3 4

 Input Format 
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of test cases is as follows: The First line of each test case contains two integers 'N' and 'E' which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E' space-separated pairs u and v denoting that there is an edge from u to v.

 Output Format 
For each test case, print the BFS of the graph starting from 0.

 Constraints 
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2

 Sample Input  
2
5 4
0 1 0 2 0 3 2 4
3 2
0 1 0 2
Sample Output 
0 1 2 3 4 
0 1 2 
 Sample Input  
3
3 2
0 1 0 2
5 4
0 1 0 3 0 3 1 2
6 5
0 2 0 3 0 1 0 4 2 5
0 1 2 
Sample Output 
0 1 3 2 
0 2 3 1 4 5 
*/
/* BFS - Breadth First Search - graph */
#include <bits/stdc++.h>
using namespace std;
void BFS(list<int> graph[], int start, bool visited[]) 
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (int adjacent : graph[current]) 
	{
            if (!visited[adjacent]) 
		{
		visited[adjacent] = true;                
		q.push(adjacent); 
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int V, E;
        cin >> V >> E;
        list<int> graph[V];
        bool visited[V]={false};
        for (int i = 0; i < E; ++i) 
	{
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        BFS(graph, 0, visited);
        cout << endl;
    }
    return 0;
}
