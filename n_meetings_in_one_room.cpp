class Solution
{
    public:
    struct meet
    {
        int start;
        int end;
        int pos;
    };
    
    static bool comparator( struct meet m1, struct meet m2 )
    {
        if( m1.end < m2.end ) return true;
        else if( m1.end > m2.end ) return false;
        else if( m1.pos < m2.pos ) return true;
        return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        meet store[n];
        vector<int> ans;
        for( int i = 0; i<n; ++i )
        {
            store[i].start = start[i];
            store[i].end = end[i];
            store[i].pos = i+1;
        }
        sort( store, store+n, comparator);
        int limit = store[0].end;
        ans.push_back( store[0].pos );
        
        for( int i =1; i<n; ++i )
        {
            if( store[i].start > limit )
            {
                limit = store[i].end;
                ans.push_back( store[i].pos );
            }
        }
        return ans.size();
    }
};
