#include<bits/stdc++.h>
using namespace std;

// a^b=n;

double pp( double p, double num ){
    double lo = 0, hi = max( 1.0, num ), l=100, mid, temp;

    while( l-- ){
        mid = ( lo+hi)/2.0;
        temp=pow( mid, p );
        if( abs( temp - num ) < ( 10e-4) ) return mid;
        if( temp > num ) hi=mid;
        else lo=mid;
    }
}

int main(){
    int a_i, b_i, temp;
    double n, k, p, a, b;
    cin>>b>>n;

    a= pp( b, n );
    cout<<a<<endl;
    main();
}
