#include<bits/stdc++.h>
using namespace std;

int mul( int n1, int n2 ){
    int a_i, b_i, temp = 0, extra = 0, b = 1, c;
    c = (int) (log2(2));
    n1 <<= c;
    temp = n2;
    cout<<n1<<endl;
    for( a_i=0; a_i<=c; a_i++ ){
            cout<<temp<<endl;
        if( temp & 1 ){
            temp += n1;
        }
        temp >>= 1;
    }
    return temp;
}

int main(){
    int a_i, b_i, n, temp, n1, n2;
    cin>>n1>>n2;

    cout<<mul( n1, n2 )<<endl;

}
