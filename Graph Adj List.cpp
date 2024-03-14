/*Graph - Adjacency List Representation*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V,E;
    cin>>V>>E;
    list<int> graph[V];
    int u,v;
    for(int i=0;i<E;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<V;i++)
    {
        cout<<i;
        for(auto val:graph[i])
        {
            cout<<"->"<<val;
        }
        /*for(auto val=graph[i].begin();val!=graph[i].end();val++)
        {
            cout<<"->"<<*val;
        }*/
        cout<<endl;
    }

    return 0;
}