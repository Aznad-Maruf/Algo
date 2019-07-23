#include<bits/stdc++.h>
using namespace std;

vector < int > price;
vector < int > weight;
vector < vector < int > > dp;

int knapSack( int index, int capasity ){

/// when invalid return -infinity so that it remains negative even after adding with price[index]
    if( capasity < 0 ) return INT_MIN;

/// When it crosses the index or when capacity is 0 no more value can be added
    if( index < 0 || capasity == 0 ) return 0;

    if( dp[index][capasity] != -1 ) return dp[index][capasity];

    return dp[index][capasity]=max( knapSack( index-1, capasity ), knapSack( index-1, capasity-weight[index])+price[index] );
}

int main(){

    int testCase, a_i, b_i, noOfElements, temp, capasity;

    cin>>testCase;

    while( testCase-- ){

        cin>>noOfElements>>capasity;

        price.resize( noOfElements );
        weight.resize( noOfElements );
        dp.resize( noOfElements );
        for( a_i=0; a_i<noOfElements; a_i++ )dp[a_i].resize( capasity+1, -1 );

        for( a_i=0; a_i<noOfElements; a_i++ ) cin>>price[a_i];
        for( a_i=0; a_i<noOfElements; a_i++ ) cin>>weight[a_i];

        cout<< knapSack( noOfElements-1, capasity )<<endl;

        price.clear();
        weight.clear();
        dp.clear();

    }
}
