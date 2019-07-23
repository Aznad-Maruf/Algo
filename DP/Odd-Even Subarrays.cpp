#include<bits/stdc++.h>
using namespace std;

long long ans, even, odd, n;
vector < int > v;
vector < int > vt;
unordered_map < int, int > mp;

// Naive solution n^2.
void evenOdd( int p1, int p2 ){
    if( p1 >= n || p2 >= n ) return;
    if( v[p2] % 2 == 0 ) even++;
    else odd++;
    if( even == odd ) ans+=1;
    evenOdd( p1, p2+1 );
    even = 0, odd = 0;
    if( p2 == n-1 )
    evenOdd( p1+1, p1+1 );

}

// n solution
void evenOdd(){
    int a_i, b_i, temp=0;
    for( a_i=0; a_i<n; a_i++ ){
        if( v[a_i] & 1 ) temp--;
        else temp++;
        vt[a_i] = temp;
        //cout<<vt[a_i]<<endl;
    }

    for( a_i=0; a_i<n; a_i++ ){
        ans+= mp[ vt[a_i]] ;
        mp[ vt[a_i] ]++;
    }

}

int main(){
    int a_i, b_i, temp;
    cin>>n;
    v.resize( n );
    vt.resize( n, 0 );
    for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];

    mp[0]++;

    evenOdd();
    cout<<ans<<endl;

}
