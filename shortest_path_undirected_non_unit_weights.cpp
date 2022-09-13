#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, u, v, w;
    cin>>n>>m;
    vector< pair<int, int> >adj[n+1];

    for( int i = 0; i<m; i++ )
    {
        cin>>u>>v>>w;
        adj[u].push_back( {v, w} );
        adj[v].push_back( {u, w} );
    }
    
    vector<int> dis(n+1, INT_MAX );
    dis[1] = 0;
    
    priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > >pq;
    pq.push({0, 1});
    
    while( !pq.empty() )
    {
        int fir = pq.top().first;
        int sec = pq.top().second;
        pq.pop();
        for( auto it : adj[sec] )
            {
                if( dis[sec] + it.second < dis[it.first] )
             {  
                 dis[it.first] = it.second + dis[sec];
                 pq.push({ dis[it.first], it.first} );
             }
            }
    }
    cout<<endl;
    for( int i = 1; i<=n; ++i )
    {
        cout<<dis[i]<<" ";
    }
}
