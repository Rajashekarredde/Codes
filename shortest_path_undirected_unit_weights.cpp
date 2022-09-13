#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, u, v;
    cin>>n>>m;
    vector<int>adj[n];
    for( int i = 0; i<m; i++ )
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dis(n, INT_MAX);
    queue<int> q;
    q.push( 0 );
    dis[0] = 0;
    
    while( !q.empty() )
    {
        int temp = q.front();
        q.pop();
        for( auto it : adj[temp] )
        {
            if( dis[temp] + 1 < dis[it] )
            {
                dis[it] = dis[temp] + 1;
                q.push(it);
            }
        }
    }
    
    for( int i = 0; i<dis.size(); ++i )
    {
        cout<<dis[i]<<" ";
    }
}
