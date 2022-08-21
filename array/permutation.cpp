#include<bits/stdc++.h>
using namespace std;

void permutate( int index, vector<int> &arr, vector< vector<int> > &ans )
{
    if( index == arr.size() )
    {
        ans.push_back( arr );
        return;
    }
    
    for( int i = index; i<arr.size(); ++i )
    {
        swap( arr[index], arr[i] );
        permutate( index+1, arr, ans );
        swap( arr[index], arr[i] );
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> arr;
    
    for( int i = 0; i<n ; ++i )
    {
        int k; cin>>k;
        arr.push_back( k );
    }
        
    vector<vector<int> > ans;
    permutate( 0, arr, ans );

    for( int i = 0; i<ans.size(); ++i )
    {
        for( int j = 0; j<ans[i].size(); ++j )
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
