#include<bits/stdc++.h>
using namespace std;

int ways( int total, int n, vector < int > &v, vector < int > &dp ){
    if( total < 0 ) return 0;
    if(dp[total] != -1 ) return dp[ total ] ;

    int temp=0;
    for ( int a_i=0; a_i<n; a_i++ ){

        temp+=ways( total-v[a_i], n, v, dp );
    }
    cout<<total<<" "<<temp<<endl;
    return dp[total]=temp;
}

int main(){
    int testCase, a_i, b_i, a_t, temp, n, total ;

    cin>>n;
    vector < int > v( n );

    for ( a_i=0; a_i<n; a_i++ )cin>>v[ a_i ];

    cin>>total;
    vector < int > dp( total+1, -1 );
    dp[0] = 1;

    cout<<ways( total, n, v, dp )<<endl;
    for(a_i=0;a_i<=total;a_i++)cout<<dp[a_i]<<" ";
}
