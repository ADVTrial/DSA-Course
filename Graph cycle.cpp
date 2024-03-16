/*
Given a directed graph with the vertices and edges between the vertices as the input.verify it consists of cycle or not.vertex starts with 0,1,2....N-1.

Input Format :
Single line input separated by space.the first integer N1 denotes the total number of vertices(i.e. nodes).The Second integer N2 denotes the total number of Edges After that, the user wants to get the two number form the edge between the two nodes.and get next two numbers and form the edge and so on.Directed graph specified by if the input is (0 1 ) the direction of path from (0 to 1 )and not( 1 to 0).

Output Format :
Print YES or NO according to the graph.

Sample testcases :
Testcase 1 Input
4 3 0 1 1 2 2 0
Testcase 1 Output
YES
Testcase 2 Input
4 3 0 1 1 2 2 3
Testcase 2 Output
NO
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
    if(cycle)
        cout<<"YES";
    else
        cout<<"NO";
}
