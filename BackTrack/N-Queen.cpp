#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > grid;
int n;

bool isAllowed( int r, int c ){
    int a_i, b_i, temp;
    for( a_i=0; a_i<n; a_i++ ) if( grid[r][a_i] ) return false;
    for( a_i=0; a_i<n; a_i++ ) if( grid[a_i][c] ) return false;

    // diagonal
    int ulr, ulc, urr, urc, c1 = c-1, c2 = c+1;

    for( a_i= r-1; a_i>=0; a_i--, c1--, c2++ ){
        if( c1>=0 )
        if( grid[a_i][c1] ) return false;
        if( c2<n )
        if( grid[a_i][c2] ) return false;

    }
    c1 = c-1, c2 = c+1;
    for( a_i= r+1; a_i<n; a_i++, c1--, c2++ ){
        if( c1>=0 )
        if( grid[a_i][c1] ) return false;
        if( c2<n )
        if( grid[a_i][c2] ) return false;

    }
    //cout<<r<<" "<<c<<endl;
    return true;

}

bool fillIt( int r, int c, int N ){
    int a_i, b_i;
    //cout<<N<<endl;
    if( N == 0 ) return true;
    //if( r>=n || c>=n ) return false;
//cout<<r<<" "<<c<<" "<<n<<" "<<N<<endl;
    for( a_i=r; a_i<n; a_i++ ){
        for( b_i=c; b_i<n; b_i++ ){
                //cout<<a_i<<b_i<<" "<<N<<endl;
            if( isAllowed( a_i, b_i ) ){
                grid[a_i][b_i] = 1;
                //cout<<N<<endl;
                if( fillIt( a_i, b_i+1, N-1 ) ) return true;

                    grid[a_i][b_i] = 0;
                    //N--;
            }
        }
        c = 0;
    }
    //cout<<r<<" "<<c<<" "<<N<<endl;

    //fillIt( r, c+1, N+1 );
    return false;

}

int main(){
    int a_i, b_i;
    cin>>n;
    grid.resize( n, vector < int > ( n, 0 ) );

    if( fillIt( 0, 0, n ) ){
        cout<<"YES"<<endl;
        for( a_i=0; a_i<n; a_i++ ){
            for( b_i=0; b_i<n; b_i++ )cout<<grid[a_i][b_i]<<" ";
            cout<<endl;
        }
    }
    else cout<<"NO"<<endl;

}
