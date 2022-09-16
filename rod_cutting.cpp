#include<bits/stdc++.h>
int solver( vector<int> &cuts, int n, int index, vector<vector<int> >&dp )
    {
        if( index == 0 )
        {
            return n * cuts[0];
        }
        
        if( dp[index][n] != -1 )
            return dp[index][n];
        
        int notTake = solver( cuts, n, index - 1, dp );
        int take = INT_MIN;
        if( index+1 <= n )
            take = cuts[index ] + solver( cuts, (n - (index + 1) ) , index, dp );
        return dp[index][n] = max( notTake, take );
    }

int cutRod(vector<int> &cuts, int n)
{
    vector< vector<int> >dp( n, vector<int>(n+1, -1 ) ); 
        int ans = solver( cuts, n, n-1, dp );
        return ans;
}
