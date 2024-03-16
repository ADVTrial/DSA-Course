/*
Assuming N nodes numbered 0 to N - 1, create a undirected graph taking as input the edges of the graph. Print "Graph is a Tree" if the graph is a tree i.e acyclic and connected, else print "Graph is not a Tree";

Input Format :
A number N > 0
Input the number of edges, E > 0
Input the E edges of the graph

Output Format :
If the graph is a tree print "Graph is a Tree"
else print "Graph is not a Tree";


Sample testcases :
Testcase 1 Input
3
2
0 1
1 2
Testcase 1 Output
Graph is a Tree
Testcase 2 Input
3
1
0 1
Testcase 2 Output
Graph is not a Tree
*/
#include<bits/stdc++.h>
using namespace std;
bool cycle=false;
void DFS(list<int>graph[],int node,bool visited[])
{
    visited[node]=true;
    for(auto adj:graph[node])
    {
        if(!visited[adj])
        {
        DFS(graph,adj,visited);
        }
        else
        {
            cycle=true;
            return;
        }
    }
}
bool isconnected(bool visited[],int V)
{
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false){
            return false;
        }
    }
    return true;
}
int main()
{
    int V,E,u,v;
    cin>>V>>E;
    list<int>graph[V];
    bool visited[V]={false};
    for(int i=0;i<E;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
    }
    DFS(graph,0,visited);
    if(!cycle && isconnected(visited, V))
        cout<<"Graph is a Tree";
    else
        cout<<"Graph is not a Tree";
}