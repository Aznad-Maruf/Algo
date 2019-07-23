#include<bits/stdc++.h>
using namespace std;

vector < int > dp;
vector < int > coins;
vector < int > p;
int noOfCoins, maxi = 10e7;
bool is;

int minCoins( int s ){
    int a_i, b_i, temp, mini = maxi;
    if( s < 0 ) return maxi;
    if( dp[s] != -1 ) return dp[s];


    for( a_i=0; a_i<noOfCoins; a_i++ ){
        temp = minCoins( s-coins[a_i] ) + 1;
        //mini = min( temp, mini );
        if( temp < mini ){
            mini = temp;
            p[s] = coins[a_i];
        }
    }
    return dp[s]=mini;

}

void printCoins( int s ){
    if( !is ) {
            cout<<"Not Possible!"<<endl;;
            return;
    }
    while( s > 0 ){
        cout<<p[s]<<" ";
        s-=p[s];
    }
    cout<<endl;
}

int main(){
    int sum, a_i, b_i, n, temp;
    is = true;
    cin>>noOfCoins;
    coins.resize( noOfCoins );
    for( a_i=0; a_i<noOfCoins; a_i++ ) cin>>coins[a_i];
    cin>>sum;
    dp.resize( sum+1, -1 );
    p.resize( sum+1, -1 );
    dp[0] = 0;

    int ans = minCoins(sum);

    if( ans >= maxi ) is = false;
    else cout<<ans<<endl;

    printCoins( sum );

}
