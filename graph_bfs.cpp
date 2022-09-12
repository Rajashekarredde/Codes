#include<bits/stdc++.h>
using namespace std;
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
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    vector<int> ans;
    while( !q.empty() )
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        
        if( adj[temp].size() == 0 )
        {
            for( int i = 1; i<=n; i++ )
            {
                if( vis[i] == 0 )
                {
                    q.push(i);
                    vis[i] = 1;
                    continue;
                }
            }
        }
        
        for( auto it : adj[temp] )
        {
            if( !vis[it] )
            { 
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    for( int i = 0; i<ans.size(); ++i )
        cout<<ans[i]<<" ";
}
