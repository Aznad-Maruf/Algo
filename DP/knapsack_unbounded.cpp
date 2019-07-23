#include<bits/stdc++.h>
using namespace std;

vector < int > p, w, dp;
int n, W;

void printDp(){
    int a_i, b_i;
    for( a_i=0; a_i<=W; a_i++ ) cout<<a_i<<" "<<dp[a_i]<<endl;;
    cout<<endl;
}

int knapSackU( int cw ){
    if( cw <= 0 ) return 0;
    if( dp[cw] ) return dp[cw];
    for( int i =0; i<n; i++ )
    if( cw >= w[i] ) dp[cw] =  max( dp[cw], p[i]+ knapSackU( cw-w[i] ) ) ;
    return dp[cw];
}

int knapSack(){
    int a_i, b_i, c_i, temp;
    for( a_i=0; a_i<=W; a_i++ ){
        for( b_i=0; b_i<n; b_i++ ){
            dp[a_i] = max( dp[a_i], ( a_i >= w[b_i] ? p[b_i]+dp[ a_i-w[b_i] ] : 0 ) );
        }
    }
    return dp[W];
}

int main(){
    int a_i, b_i, testCase;
    cin>>testCase;
    while( testCase-- ){
        cin>>n>>W;
        p.resize( n );
        w.resize( n );
        for( a_i=0; a_i<n; a_i++ ) cin>>p[a_i];
        for( a_i=0; a_i<n; a_i++ ) cin>>w[a_i];
        dp.resize( W+1, 0 );

        cout<<knapSackU( W )<<endl;

        //printDp();
        //cout<<knapSack()<<endl;

        p.clear();
        w.clear();
        dp.clear();

    }
}
