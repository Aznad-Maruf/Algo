#include<bits/stdc++.h>
using namespace std;

/**
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 6

*/

int maxSum( vector < int > &tv ){
    int temp=-10e7, maxi=tv[0], a_i, b_i, s=tv.size();
    //cout<<s<<endl;
    for( a_i=0; a_i<s; a_i++ ){
        temp=max( tv[a_i], temp+tv[a_i] );
        maxi=max( temp, maxi );
        //cout<<maxi<<endl;
    }
    return maxi;
}

int main(){
    freopen( "input.txt", "r", stdin );
    int r, c, a_i, b_i, c_i, temp, maxi;
    cin>>r>>c;
    vector < vector < int > > v( r, vector < int > ( c ));
    for( a_i=0; a_i<r; a_i++ ) for( b_i=0; b_i<c; b_i++ ) cin>>v[a_i][b_i];

    maxi=v[0][0];
    vector < int > tv(c);
    for( a_i=0; a_i<r; a_i++ ){
            fill(tv.begin(),tv.end(), 0 );
        for( b_i=a_i; b_i<r; b_i++ ){
                //cout<<b_i<<"a"<<endl;
                for( int c_i=0; c_i<c; c_i++ )tv[c_i]+=v[b_i][c_i];

                temp=maxSum( tv );
                //cout<<maxi<<endl;
                maxi=max( temp, maxi );
        }
    }
    cout<<maxi<<endl;

}
