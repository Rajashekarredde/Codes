#include<bits/stdc++.h>
using namespace std;
//graph should be directed acyclic graph, in order to get valid for topo sort

void dfs( vector<int>&vis, stack<int>&st, int node, vector<int>adj[] )
{
    vis[node] = 1;
    
    for( auto it: adj[node] )
    {
        if( !vis[it] )
        {
            dfs(vis, st, it, adj );
        }
    }
    st.push(node);
}

int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<int> adj[n+1];
    int u, v;
    for( int i = 1; i<=m; i++ )
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    vector<int> vis( n+1, 0);
    stack<int> st;

    for( int i = 1; i<=n; ++i )
    {
        if( !vis[i] )
        {
            dfs(vis, st, i, adj);     
        }
    }
    
    while( !st.empty() )
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
