#include<bits/stdc++.h>
using namespace std;

void findTopo( stack<int> &st, vector<int> &vis, vector<int> adj[], int node )
{
    vis[node] = 1;
    for( auto it : adj[node] )
    {
        if( !vis[it] )
            findTopo( st, vis, adj, it );
    }
    st.push(node);
}

void dfs( vector<int> &vis, vector<int> adj[], int node )
{
    cout<<node<<" ";
    vis[node] = 1;
    for( auto it : adj[node] )
    {
        if( !vis[it] )
            dfs( vis, adj, it );
    }
}

int main()
{
    int n, m, u, v;
    cin>>n>>m;
    vector<int>adj[n+1];

    for( int i = 0; i<m; i++ )
    {
        cin>>u>>v;
        adj[u].push_back( v );
    }
    
    stack<int> st;
    vector< int > vis(n+1, 0 );
    for( int i = 1; i<=n; i++ )
    {
        if( !vis[i] )
            findTopo( st, vis, adj, i);
    }
    
    vector<int> transpose[n+1];
    for( int i =1; i<=n; i++ )
    {
        vis[i] = 0;
        for( auto it : adj[i] )
           transpose[it].push_back(i); 
    }
           
    cout<<"Answer : "<<endl;
    
    while( !st.empty() )
    {
        int temp = st.top();
        st.pop();
        if( !vis[temp] )
        {
            dfs( vis, transpose, temp );
            cout<<endl;
        }
    }
}
