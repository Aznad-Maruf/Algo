#include<bits/stdc++.h>
using namespace std;

vector < int > v;
vector < int > dpS;
vector < int > p;
int totalN, maxi, r;

void lis(){
    int a_i, b_i, n, temp;
    maxi = 0;
    for( a_i=totalN-1; a_i>=0; a_i-- ){
            temp = 1;
        for( b_i=a_i+1; b_i<totalN; b_i++ ){

            if( v[b_i] > v[a_i] ){
                //temp = max( temp, dpS[b_i]+1 );
                if( dpS[b_i]+1 > temp ){
                    temp = dpS[b_i]+1;
                    p[a_i] = b_i;
                }
            }
        }
        dpS[a_i] = temp;
        if( temp > maxi ){
            maxi = temp;
            r = a_i;
        }
    }
}

void printLis( int n ){
    if( p[n] == -1 ){
        cout<<v[n]<<endl;
        return;
    }
    cout<<v[n]<<" ";
    printLis( p[n] );
    //cout<<endl;
}

int main(){
    int a_i, b_i, n, temp, ans;
    cin>>totalN;
    n = totalN;
    v.resize( n );
    dpS.resize( n, 1 );
    p.resize( n, -1 );
    for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];

    lis();

    //for( a_i=0; a_i<n; a_i++ ) cout<<dpS[a_i]<<" ";
    //cout<<endl;

    cout<<maxi<<endl;

    printLis(r);


}
