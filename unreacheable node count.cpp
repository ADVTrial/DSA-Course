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
    int s;
    cin >> s;
    DFS(graph, s, visited);
    cout <<(V-vcount);
    cout << endl;
    return 0;
}
