#include<bits/stdc++.h>
using namespace std;

int main(){
    int a_i, b_i, hight, width, ans, temp, r1, r2, c1, c2, maxi;

    cin>>hight>>width;
    vector < vector < int > > grid(hight+1, vector < int > (width+1, 0 )); /// Initialize with zero .

    /// Take input
    for ( a_i=1; a_i<=hight;a_i++)for(b_i=1; b_i<=width; b_i++ ) cin>>grid[a_i][b_i];

    /// take cumulative sum of each 1d array
    //for ( a_i=1; a_i<=hight;a_i++)for(b_i=1; b_i<=width; b_i++ ) grid[a_i][b_i]+=grid[a_i][b_i-1]+grid[a_i-1][b_i]-grid[a_i-1][b_i-1];
    /// grid [a][b] contains the sum of element up to that point.


    /// printing the sum
//    for( a_i=1; a_i<=hight; a_i++ ){
//        for( b_i=1; b_i<=width; b_i++ ){
//            cout<<grid[a_i][b_i]<<" ";
//        }
//        cout<<endl;
//    }

    maxi=grid[1][1];

    for( r1=1; r1<=hight; r1++ ){
        for( r2=r1; r2<=hight; r2++ ){
                temp=0;
           for(c1=1; c1<=width; c1++ ){
            for( c2=c1; c2<=width; c2++ ){
                temp+=grid[r2][c2];
            }
           }
    }

}
