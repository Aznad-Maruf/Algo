#include<bits/stdc++.h>
using namespace std;

vector < int > v;
int n, target, cont;

bool isIt( int p, int num ){
    cont++;
    if( num == target ) return true;
    if( p >= n ) return false;
    //cout<<p<<" "<<num<<endl;
    return ( isIt( p+1,num+v[p]) || isIt( p+1, num ) );
}

int main(){
    int a_i, b_i, temp, num;
    cin>>n;
    v.resize( n );
    for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];
    while(cin>>target){
    if( isIt( 0, 0 ) ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<cont<<endl;
    cont=0;
}
}
