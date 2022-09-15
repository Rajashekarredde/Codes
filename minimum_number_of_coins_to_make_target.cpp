#include <bits/stdc++.h> 
int solverTab( vector<int>&nums, int x )
{
    vector<int>dp(x+1, INT_MAX);
    dp[0] = 0;
    for( int i = 1; i<=x; i++ )
    {
        for( int j = 0; j<nums.size(); j++ )
        {
            if( i-nums[j] >= 0 && dp[i-nums[j]] != INT_MAX  )
            dp[i] = min( dp[i], 1+ dp[ i - nums[j] ] );
        }
    }
    return dp[x];
}

int solver( vector<int>&nums, int x, vector<int>&dp )
{
    if( x == 0 )
        return 0;
    
    if( x < 0 )
        return INT_MAX;
    
    if( dp[x] != -1 )
        return dp[x];
    
    int mini = INT_MAX;
    for( int i = 0; i<nums.size(); ++i )
    {
        int ans = solver( nums, x-nums[i], dp );
        if( ans != INT_MAX )
            mini = min( mini, 1+ ans );
    }
    dp[x] = mini;
    return mini;
}
int minimumElements(vector<int> &nums, int x)
{
    int ans = solverTab( nums, x);
    if( ans == INT_MAX )
        return -1;
    return ans;
}
