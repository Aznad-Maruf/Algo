


#include<bits/stdc++.h>
using namespace std;

vector < int > w, p, is;
vector < vector < int > > dp;
int W, n;

void whichOne(){
    int a_i, b_i;

    for( a_i=n; a_i>=1; ){
        for( b_i=W; b_i>=1 && a_i>=1; ){
            if( dp[a_i][b_i] == dp[a_i-1][b_i] ){
                a_i--;
            }
            else{
                is[a_i] = 1;
                a_i--;
                b_i -= w[a_i];
            }
        }
    }

}

int knapSack(){
    int a_i, b_i, temp, maxi;

    for( a_i=1; a_i<=n; a_i++ ){
        for( b_i=1; b_i<=W; b_i++ ){
            dp[a_i][b_i] = dp[a_i-1][b_i]; // initialize with the value if not taken
/*
zodi neya zay - dp[a_i][b_i] = max( naNiye( oi capasity tei tar aager element ponto niye ),
( niye( price of that element and the value for capasity-wt[a_i] for a_i-1 elements ) ) );
*/

            if( b_i >= w[a_i] ) dp[a_i][b_i] = max( dp[a_i][b_i], p[a_i]+dp[a_i-1][b_i-w[a_i]]);
        }
    }
    return dp[n][W];

}

void printDp(){
    for( int a_i=0; a_i<=n; a_i++ ){
        for( int b_i=0; b_i<=W; b_i++ ) cout<<dp[a_i][b_i]<<" ";
        cout<<endl;
    }
}

void printElements(){
    for( int a_i=1; a_i<=n; a_i++ ) if( is[a_i] ) cout<<a_i<<" ";
    cout<<endl;
}

int main(){
    int a_i, b_i, temp;
    cin>>n>>W;
    w.resize( n+1 );
    p.resize( n+1 );
    is.resize( n+1, 0 );
    dp.resize( n+1, vector < int > ( W+1, 0 ) );

    for( a_i=1; a_i<=n; a_i++ ) cin>>p[a_i];
    for( a_i=1; a_i<=n; a_i++ ) cin>>w[a_i];

    cout<<knapSack()<<endl;

    printDp();

    whichOne();

    printElements();

}
