#include<bits/stdc++.h>
using namespace std;

vector < int > price;
vector < int > weight;
vector < vector < int > > dp;
int maxi( int n1, int n2 ){
    return n1 > n2 ? n1 : n2;
}

int knapSackRecursion( int Capasity, int index ){
    if( Capasity < 0 || index < 0 ) return 0;
    if( dp[index][Capasity] != -1 ) return dp[index][Capasity];


    /// if not possible to take
    if( Capasity-weight[index] < 0 ){
        return dp[index][Capasity] = knapSackRecursion( Capasity, index-1 ); /// na niye;
    }
    /// Otherwise return maximum with taken and without taken.
    return dp[index][Capasity] = max( knapSackRecursion( Capasity, index-1 ),
                knapSackRecursion( Capasity-weight[index], index-1 )+price[index]);

}

int main(){
    freopen( "input.txt", "r", stdin );
    int testCase, noOfElements, Capasity, a_i, b_i, temp;
    cin>>testCase;
    while(testCase--){
    cin>>noOfElements>>Capasity;
    price.resize( noOfElements );
    weight.resize( noOfElements );
    dp.resize(noOfElements);
    for( a_i=0; a_i < noOfElements; a_i++ )dp[a_i].resize( Capasity+1, -1 );
    for( a_i=0; a_i<noOfElements; a_i++ ) cin>>price[a_i];
    for( a_i=0; a_i<noOfElements; a_i++ ) cin>>weight[a_i];
    cout<< knapSackRecursion( Capasity, noOfElements-1 )<<endl;
    dp.clear();
    price.clear();
    weight.clear();
    }
}
