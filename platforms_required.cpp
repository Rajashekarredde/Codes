class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort( arr, arr+n);
        sort( dep, dep+n );
        int platform = 1;
        int result = 1;
        int i = 1;
        int j = 0;
        // 900 940 950 1100 1500 1800
        // 910 1120 1130 1200 1900 2000 
        while( i < n && j < n )
        {
            if( arr[i] <=  dep[j] )
            {
                platform++;
                i++;
            }
            else if( arr[i] > dep[j] )
            {
                platform--;
                j++;
            }
            
            if( platform > result )
                result = platform;
        }
        return result;
    }
};
