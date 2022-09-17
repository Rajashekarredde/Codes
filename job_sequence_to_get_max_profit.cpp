class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator( struct Job m1, struct Job m2 )
    {
        return m1.profit > m2.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort( arr, arr+n, comparator);
        int maxi = INT_MIN;
        for( int i =0; i<n; i++ )
            maxi = max( maxi, arr[i].dead );
        vector<int> store( maxi, -1);
        int profit = 0;
        int count = 0;
        for( int i =0; i<n; ++i )
        {
            for( int j = arr[i].dead - 1 ; j >= 0; j-- )
            {
                if( store[j] == -1 )
                {
                    profit += arr[i].profit;
                    count ++;
                    store[j] = arr[i].id;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back( count );
        ans.push_back( profit );
        return ans;
    } 
};
