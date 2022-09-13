#include<bits/stdc++.h>
using namespace std;

bool dfs( vector<int>&vis, vector<int>&dfsVis, int node, vector<int>adj[] )
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for( auto it: adj[node] )
    {
        if( !vis[it] )
        {
            if( dfs(vis, dfsVis, it, adj ) )
                return true;
        }
        else if( dfsVis[it] )
            return true;
    }
    dfsVis[node] = 0;
    return false;
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
    vector<int> dfsVis(n+1, 0);

    for( int i = 1; i<=n; ++i )
    {
        if( !vis[i] )
        {
            if( dfs(vis, dfsVis, i, adj) )
            {
                cout<<"cycle exists";
                break;
            }
        }
    }
}
