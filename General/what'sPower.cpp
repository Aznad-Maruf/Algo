#include<bits/stat.h>
using namespace std;

// a^b=n;

double pp( double a, double n ){
    double lo = 0, hi = max( 1, n ), l=100, mid, temp;

    while( lo < hi ){
        mid = ( lo+hi)/2.0;
        temp=pow( mid, a );
        if( abs( temp - n ) < ( 10e-4) ) return mid;
        if( temp > n ) hi=mid;
        else lo=mid;
    }
}

int main(){
    int a_i, b_i, n, temp;
    double n, k, p;
    cin>>a>>n;

    b= pp( a, n );
    cout<<b<<endl;
}
