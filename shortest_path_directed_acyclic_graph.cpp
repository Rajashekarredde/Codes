#include<bits/stdc++.h>
using namespace std;

void findTopo( stack<int> &st, vector< pair<int, int> >adj[], int node, vector<int>&vis )
{
    vis[node] = 1;
    for( auto it : adj[node] )
    {
        if( !vis[it.first] )
            findTopo( st, adj, it.first, vis );
    }
    st.push( node );
}

int main()
{
    int n, m, u, v, w;
    cin>>n>>m;
    vector< pair<int, int> >adj[n];
    
    vector<int>vis(n, 0);
    
    for( int i = 0; i<m; i++ )
    {
        cin>>u>>v>>w;
        adj[u].push_back( {v, w} );
    }
    
    stack<int> st;
    
    for( int i =0; i<n; i++ )
    {
        if( !vis[i] )
            findTopo( st, adj, i, vis );
    }
    
    vector<int> dis(n, INT_MAX );
    dis[0] = 0;
    
    while( !st.empty() )
    {
        int t = st.top();
        st.pop();
        //this condition make sures traversal start from the source
        if( dis[t] != INT_MAX )
        for( auto it : adj[t] )
        {
                if( dis[t] + it.second < dis[it.first] )
                    dis[it.first] = dis[t] + it.second;
        }
    }
    
    for( int i = 0; i<n; ++i )
    {
        cout<<dis[i]<<" ";
    }
}
