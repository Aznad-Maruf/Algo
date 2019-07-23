#include<bits/stdc++.h>
using namespace std;

bool indexes( vector < int > & v, int* lo, int *hi, int* k ){
    int a_i, b_i, n=v.size(), sum;
    *lo=0, *hi=n-1;
    while( *lo < *hi ){
         //   cout<<*k<<endl;
            sum=v[*lo]+v[*hi];
           // cout<<*lo<<" "<<*hi<<endl;
        if( sum == *k ) return true;
        else if( sum < *k ) *lo+=1;
        else *hi-=1;
       // cout<<*lo<<" "<<*hi<<endl;

    }
    return false;
}

int main(){
    int a_i, b_i, n, temp, k, lo, hi;

    cin>>n;
    vector < int > v( n );
    for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];
    cin>>k;
    sort( v.begin(), v.end() );

    bool is = indexes( v, &lo, &hi, &k );
    if( !is ) cout<<" Not possible! " <<endl;
    else cout<<v[lo]<<" "<<v[hi]<<endl;

}
