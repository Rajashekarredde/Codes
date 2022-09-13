#include<bits/stdc++.h>
using namespace std;

bool bfs( vector<int>&vis, int node, vector<int>adj[] )
{
    queue< pair<int, int> > q;
    vis[node] = 1;
    q.push({node, -1});
    while( !q.empty() )
    {
        int par = q.front().second;
        int ele = q.front().first;
        q.pop();
        for( auto it : adj[ele ] )
        {
            if( !vis[it] )
            {
                q.push({it, ele});
                vis[it] = 1;
            }
            else if( par != it )
            {
                return true;
            }
        }
    }
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
        adj[v].push_back(u);
    }
    
    vector<int> vis( n+1, 0);
    vector<int> ans;
    
    for( int i = 1; i<=n; ++i )
    {
        if( !vis[i] )
        {
            if( bfs(vis, i, adj) )
            {
                cout<<"cycle exists";
                break;
            }
        }
    }
}
