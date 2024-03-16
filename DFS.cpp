/*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note
Use recursive approach.

Example
Input
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3

Output
0 1 2 4 3 
0 1 2 3 

Explanation

Visit all the vertices using depth first search algorithm using 0 as a source node.

 Input Format 
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E' which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E' space separated pairs u and v denoting that there is a edge from u to v .

 Output Format 
For each testcase, print the nodes while doing DFS starting from node 0.

 Constraints 
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2

Graph doesn't contain multiple edges and self loops.

 Sample Input   
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3
Sample Output
0 1 2 4 3 
0 1 2 3 
 Sample Input  
1
2 1
0 1
Sample Output
0 1 
*/
/* DFS - Depth First Search - graph */
#include <bits/stdc++.h>
using namespace std;
void DFS(list<int> graph[], int node, bool visited[]) 
{
    visited[node] = true;
    cout << node << " ";
    for (int adjacent : graph[node]) {
        if (!visited[adjacent]) {
            DFS(graph, adjacent, visited);
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
            graph[v].push_back(u); 
        }
        DFS(graph, 0, visited);
        cout << endl;
    }
    return 0;
}

