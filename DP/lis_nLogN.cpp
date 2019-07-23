#include<bits/stdc++.h>
using namespace std;

vector < int > v, dp;
int n, cuLi; //current last index

void printDp(){
    for( int a_i=1; a_i<=cuLi; a_i++ ){
        cout<<a_i<<" " <<dp[a_i]<<endl;
    }
    cout<<endl;
}

int searchI( int num ){
    int lo = 0, hi = cuLi, mid, a_i, b_i, temp = -1;
    while( lo <= hi ){
        mid = ( lo+hi )/2;
        if( num <= dp[mid] ) hi = mid-1;
        else{
            temp = mid;
            lo = mid+1;
        }
    }
    return temp+1;
}

int lis(){
    int a_i, b_i, tempI;
    dp[0] = v[0];
    for( a_i=1; a_i<n; a_i++ ){
        tempI = searchI( v[a_i] );
        dp[tempI] = v[a_i];
        cuLi = max( cuLi, tempI );
        //printDp();
    }
    return cuLi+1;

}

void printLis(){
    int a_i, b_i;
    for( a_i=1; a_i<= cuLi; a_i++ ) cout<<dp[a_i]<<" ";
    cout<<endl;
}

int main(){
    int a_i, b_i, temp, testCase;

    cin>>testCase;
    while( testCase-- ){
    cuLi = 0;
    cin>>n;
    v.resize( n );
    dp.resize( n );
    for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];

    cout<<lis()<<endl;

    v.clear();
    dp.clear();
    }

    //printLis();

}
