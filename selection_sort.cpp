#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for( int i = 0; i<n; ++i )
    {
        cin>>arr[i];
    }
    
    int min_idx = 0;
    
    for( int i = 0; i<n; ++i )
    {
        min_idx = i;
        
        for( int j = i + 1; j<n; ++j )
        {
            if( arr[j] < arr[min_idx] )
            min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    
    for( int i = 0; i<n; ++i )
        cout<<arr[i]<<" ";
}
