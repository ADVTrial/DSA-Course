/*
Create a directed graph with N number of vertices and E number of edges.In the graph, S is a source vertex and D is a destination vertex.Write a program to print all paths from given source to destination.

 Input Format 
Single line input separated by space.the first integer N denotes the total number of vertices(i.e. nodes).The Second integer E denotes the total number of Edges.After that E*2 number of integers is a Edges.
node name should be in 0 to N-1.The last two number is source vertex S and destination vertex D.

 Output Format 
Print the possible path from source vertex S to destination vertex D.

 Constraints 
Integers only.

 Sample Input  
4 6 0 1 0 2 0 3 2 0 2 1 1 3 2 3
Sample Output 
2 0 1 3 
2 0 3 
2 1 3 

Input
5 8 3 0 0 2 1 2 3 2 4 3 1 3 1 4 0 1 1 2
Output
1 2 
1 3 0 2 
1 3 2 
1 4 3 0 2 
1 4 3 2 

Input
5 8 3 0 0 2 1 2 3 2 4 3 1 3 1 4 0 1 1 0
Output
1 3 0 
1 4 3 0 

Input
6 8 3 0 0 2 1 2 3 5 4 3 1 3 1 4 0 1 1 2
Output
1 2 
1 3 0 2 
1 4 3 0 2 
*/
#include <bits/stdc++.h>
using namespace std;
void printAllPaths(int s, int d, list<int> graph[], bool visited[], vector<int> path) 
{
    visited[s] = true;
    path.push_back(s);
    if (s == d) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    } 
    else     
    {
        for (int v : graph[s]) {
            if (!visited[v])  {
                printAllPaths(v, d, graph, visited, path);
            }
        }
    }
    visited[s] = false;
    path.pop_back();
}

int main() 
{
    int N, E;
    cin >> N >> E;
    list<int> graph[N];
    for (int i = 0; i < E; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    bool visited[N] ={false};
    vector<int> path;
    int S, D;
    cin >> S >> D;
    printAllPaths(S, D, graph, visited, path);
    return 0;
}
