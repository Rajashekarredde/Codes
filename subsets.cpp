#include<bits/stdc++.h>
using namespace std;
void solver( string &s, int i, string &f )
{
    if( i == s.length() )
    {
        cout<<f<<" ";
        return;
    }
    
    f = f+s[i];
    solver( s, i+1, f );
    f.pop_back();
    solver( s, i+1, f );
}
int main()
{
    string s;
    cin>>s;
    string f;
    solver(s, 0, f);
}
