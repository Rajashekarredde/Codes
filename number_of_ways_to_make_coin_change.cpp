#include<bits/stdc++.h>
long solver( int *a, int index, int target, vector< vector<long> >&dp )
{
    if( index == 0 )
        return ( target%a[0] == 0);
    
   if( dp[index][target] != -1 )
       return dp[index][target];
    
   long nonTake = solver(a , index-1, target, dp );
   long take = 0;
   if( a[index] <= target )
   {
       take = solver( a, index, target-a[index], dp );
   }
   dp[index][target] = take+nonTake;
   return take+nonTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector< vector<long> >dp( n, vector<long>(value+1, -1) );
    return solver( denominations, n-1, value, dp );
}
