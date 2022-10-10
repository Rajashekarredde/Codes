#include<bits/stdc++.h>
using namespace std;

int solver( vector< vector<int> >&grid, int r, int c, int d_r[], int d_c[], int rows, int cols ) 
{
    int maxi = 0;
    int next_row = 0;
    int next_col = 0;
    
    for( int k = 0; k<4; k++ )
    {
        int t_r = d_r[k] + r;
        int t_c = d_c[k] + c;
        if( t_r >= 0 && t_r < rows && t_c >= 0 && t_c < cols )
        {
            if( grid[t_r][t_c] > maxi )
            {
                maxi = grid[t_r][t_c];
                next_row = t_r;
                next_col = t_c;
            }
        }
    }
    
    int ans = grid[r][c];
    grid[r][c] = 0;
    
    if( maxi > 0  )
        ans += solver( grid, next_row, next_col, d_r, d_c, rows, cols );
    return ans;
}

pair<int, int> find_center( vector< vector<int> >&grid )
{
    int row_options [] = { grid.size()/2, grid.size()/2};
    int col_options [] = { grid[0].size()/2, grid[0].size()/2};
    
    if( grid.size()%2 == 0 )
        row_options[0] -= 1;
    
    if( grid[0].size()%2 == 0 )
        col_options[0] -= 1;
    
    int maxi = 0;
    pair<int, int >pr;
    
    for( int i = 0; i<2; i++ )
    {
        for( int j = 0; j<2; j++ )
        {
            if( grid[ row_options[i] ][ col_options[j] ] > maxi )
            {
                maxi = grid[ row_options[i] ][ col_options[j] ];
                pr.first = row_options[i];
                pr.second = col_options[j];
            }
        }
    }
    return pr;
}

int main()
{
    int n;
    int m;
    cin>>n>>m;
   
     //4 5
     
     //5 7 8 6 3
     //0 0 7 0 4
     //4 6 3 4 9
     //3 1 0 5 8
  
    vector< vector<int> >grid(n, vector<int>(m, 0) );
    
    for( int i = 0; i<n; i++ )
        for( int j = 0; j<m; j++ )
            cin>>grid[i][j];
        
    auto it = find_center( grid );
    cout<<it.first<<it.second<<endl;
    int d_r[] = { -1, 0, 1, 0 };
    int d_c[] = { 0, 1, 0, -1};
    
    cout<<solver( grid, it.first, it.second, d_r, d_c, n, m  );
}
