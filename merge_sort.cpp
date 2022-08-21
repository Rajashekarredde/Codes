#include<bits/stdc++.h>
using namespace std;

void merge( int *arr, int *left, int *right, int lc, int rc )
{
    int i , j, k = 0;
    while( i < lc && j < rc )
    {
        if( left[i]<= right[j] )
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while( i < lc )
                arr[k++] = left[i++];
    while( j < rc )
                arr[k++] = right[j++];
}

void mergesort( int *arr, int n )
{
    if( n < 2 ) return ;
    
    int mid = n/2;
    
    int left[ mid ];
    int right[ n - mid ];
    
    for( int i = 0; i< mid; ++i )
        left[i] = arr[i];
    for( int i = mid; i<n; ++i )
        right[i - mid] = arr[i];
     
     mergesort( left, mid );
     mergesort( right, n-mid );
     merge( arr, left, right, mid, n-mid );
}

int main()
{
    int n; 
    std::cin >> n;
    
    int arr[n];
    
    for( int i = 0 ; i<n; ++i )
        cin>>arr[i];
        
    mergesort( arr, n);
    
    for( int i = 0; i<n ; ++i )
    {
        cout<<arr[i]<<" ";
    }
}
