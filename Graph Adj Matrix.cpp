/*Graph - adjacency matrix representation*/
#include<iostream>
using namespace std;
int main()
{
    int V,E;
    cin>>V>>E;
    int g[V][V];
    for(int i=0;i<V;i++) 
    {
        for(int j=0;j<V;j++)
        { 
            g[i][j]=0; 
        }
    }
    string directed;
    cin>>directed;
    int u,v,w;
    for(int i=0;i<E;i++) 
    {
        cin>>u>>v>>w;
        if(directed=="yes")
        { 
            g[u-1][v-1]=w; 
        }
        else 
        {
            g[u-1][v-1]=w;
            g[v-1][u-1]=w;
        }
    }
    for(int i=0;i<V;i++) 
    {
        for(int j=0;j<V;j++)
        { 
            cout<<g[i][j]<<" "; 
        }
        cout<<endl;
    } 
    return 0;
}
