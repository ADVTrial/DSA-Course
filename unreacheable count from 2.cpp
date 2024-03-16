/*
An undirected graph is given.write a program to count the number of unreachable nodes. vertex starts from 0 to N-1.

Input Format :
Single line input separated by space.the first integer N1 denotes the total number of vertices(i.e. nodes).The Second integer N2 denotes the total number of Edges After that, the user wants to get the two number form the edge between the two nodes.and get next two numbers and form the edge and so on.

Output Format :
Print the total number of unreachable nodes.

Sample testcases :
Testcase 1 Input
4 2 0 1 1 2
Testcase 1 Output
1
Testcase 2 Input
4 2 0 1 1 3
Testcase 2 Output
3
*/
#include <bits/stdc++.h>
using namespace std;
int vcount = 0;
void DFS(list<int> graph[], int node, bool visited[])
{
    visited[node] = true;
    vcount++;
    for (int adj : graph[node])
    {
        if (!visited[adj])
        {
            DFS(graph, adj, visited);
        }
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    list<int> graph[20];
    bool visited[20] ={false};
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(graph, 2, visited);
    cout <<(V-vcount);
    cout << endl;
    return 0;
}