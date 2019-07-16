#include<bits/stdc++.h>
using namespace std;

int r, c, q;
vector < vector < int > > v;
bool is = false;

void printV(){
    int a_i, b_i;

    for( a_i=1; a_i<=r; a_i++ ){
        for( b_i=1; b_i<=c; b_i++ ){
            cout<<v[a_i][b_i]<<" ";
        }
        cout<<endl;
    }
    //cout<<endl;
}

bool isSafe( int cuR, int cuC ){
    int a_i, b_i;
    for( a_i=1; a_i<=r; a_i++ ){
        for( b_i=1; b_i<=c; b_i++ ){
            if( a_i == cuR || b_i == cuC || a_i+b_i == cuR+cuC || a_i-b_i == cuR-cuC ){
                if( v[a_i][b_i] == 1 ) return false;
            }
        }
    }
    return true;
}

void nQueen( int i, int j, int q ){
    //cout<<q<<" "<<i<<" "<<j<<endl;
    if( q == 0 || is ){
        is = true;
        return;
    }
    int a_i = i, b_i = j;
    //v[a_i][b_i] = 1;
    //q--;
    //b_i++;
    for( ; a_i<=r; a_i++ ){
        for( ; b_i<=c; b_i++ ){
                if( isSafe( a_i, b_i ) ){
                v[a_i][b_i] = 1;
                q--;
                nQueen( a_i, b_i+1, q );
                if( !is ){
                        //cout<<a_i<<" "<<b_i<<" - "<<q<<endl;
                        //printV();
                    v[a_i][b_i] = 0;
                    q++;
                }


            }
        }
        b_i = 1;

    }
}

int main(){
    int a_i, b_i, n, temp;

    //cin>>r>>c>>q;
    cin>>r;
    c = q = r;

    v.resize( r+1, vector < int > ( c+1, 0 ));

    nQueen ( 1, 1, q );
    if( !is ){
        cout<<"NO"<<endl;
        return 0;
    }
    if( is ) cout<<"YES"<<endl;
    printV();

}
