#include<bits/stdc++.h>
using namespace std;

int maxSum( vector < vector < int > > &v ){
    int a_i, b_i, r1, r2, c1, c2, r=v.size(), c=v[0].size(), maxi=v[0][0], temp;
    for( r1=0; r1<r; r1++ ){
        for( r2=r1; r2<r; r2++ ){
            for( c1=0; c1<c; c1++ ){
                for( c2=c1; c2<c; c2++ ){
                        temp=0;
                    for( a_i=r1; a_i<=r2; a_i++ ){
                        for( b_i=c1; b_i<=c2; b_i++ )temp+=v[a_i][b_i];
                    }
                maxi=max(maxi,temp);
                }
            }
        }
    }
    return maxi;
}

int main(){
    freopen("input.txt","r",stdin);
    int a_i, b_i, c_i, d_i, r, c;
    cin>>r>>c;
    vector < vector < int > > v(r, vector < int > (c));
    for( a_i=0; a_i<r; a_i++ )for( b_i=0; b_i<c; b_i++ ) cin>>v[a_i][b_i];

    cout<<maxSum(v)<<endl;

}
