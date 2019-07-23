#include<bits/stdc++.h>
using namespace std;

string st1, st2, st3;
vector < vector < vector < int > > > dp;
int l1, l2, l3;

int lcs( int s1, int s2, int s3 ){
    if( s1 == l1 || s2 == l2 || s3 == l3 ) return 0;
    if( dp[s1][s2][s3] != -1 ) return dp[s1][s2][s3];
    if( st1[s1] == st2[s2]&& st1[s1] == st3[s3] ) return dp[s1][s2][s3] = 1 + lcs( s1+1, s2+1, s3+1 );
    return dp[s1][s2][s3] = max( lcs( s1, s2, s3+1 ), max( lcs( s1, s2+1, s3 ), lcs( s1+1, s2, s3 ) ) );
}

void resizeDp(){
    int a_i, b_i, c_i;
    dp.resize( l1 );
    for( a_i=0; a_i<l1; a_i++ ){
        dp[a_i].resize( l2 );
        for( b_i=0; b_i<l2; b_i++ ) dp[a_i][b_i].resize( l3, -1 );
    }
}

void printDp(){
    int a_i, b_i, c_i;
    for( a_i=0; a_i<l1; a_i++ ){
        for( b_i=0; b_i<l2; b_i++ ){
            for( c_i=0; c_i<l3; c_i++ ){
                cout<<dp[a_i][b_i][c_i]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int main(){
    int a_i, b_i, n, temp, testCase;
    cin>>testCase;
    while( testCase-- ){
        cin>>l1>>l2>>l3>>st1>>st2>>st3;

//        dp.resize( l1, vector < vector < int >  > ( l2 ) );
//        for( a_i=0; a_i<l1; a_i++ ) for( b_i=0; b_i<l2; b_i++ ) dp[a_i][b_i].resize( l3, -1 );

        resizeDp();

        cout<<lcs( 0, 0, 0 )<<endl;

        //printDp();
        dp.clear();


    }

}
