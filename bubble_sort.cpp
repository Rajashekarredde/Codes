#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, flag;
    cin>>n;
    
    int arr[n];
    for( int i = 0; i<n; ++i )
    {
        cin>>arr[i];
    }
    
    for( int i =0; i<n-1; i++ )
    {
        flag = 0;
        for( int j = 0; j<n-i-1; j++ )
        {
            if( arr[j] > arr[j+1] )
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if( flag == 0 ) 
        {
            break;
        }
    }
    
     for( int i =0; i<n; i++ )
     {
         cout<<arr[i]<<" ";
     }
}
