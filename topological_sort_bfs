#include<bits/stdc++.h>
using namespace std;
//graph should be directed acyclic graph, in order to get valid for topo sort

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
    queue<int> q;
    vector<int> inDegree(n+1, 0);
    
    for( int i = 1; i<=n; ++i )
    {
        for( auto it: adj[i] )
            inDegree[it]++;
    }
    
    for( int i = 1; i<=n; i++ )
    {
        if( inDegree[i] == 0 )
            q.push(i);
    }
    
    while( !q.empty() )
    {
       int t = q.front();
       q.pop();
       cout<<t<<" ";
       for( auto it : adj[t] )
       {
           inDegree[it]--;
           if( !inDegree[it] ) q.push(it);
       }
    }
}
