#include<bits/stdc++.h>
using namespace std;

void dfs( vector<int>&ans, vector<int>&vis, int node, vector<int>adj[] )
{
    ans.push_back( node );
    vis[node] = 1;
    for( auto it : adj[node] )
    {
        if( !vis[it] )
            dfs( ans, vis, it, adj);
    }
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
        adj[v].push_back(u);
    }
    
    vector<int> vis( n+1, 0);
    vector<int> ans;
    
    for( int i = 1; i<=n; ++i )
    {
        if( !vis[i] )
        {
            dfs( ans, vis, i, adj);
        }
    }

    for( int i = 0; i<ans.size(); ++i )
        cout<<ans[i]<<" ";
}
