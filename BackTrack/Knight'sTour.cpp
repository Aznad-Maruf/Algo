#include<bits/stdc++.h>
using namespace std;

int r, c;
vector < vector < int  > > v;
vector < int > vt1, vt2; // vt1 and vt2 is to get all path of tour.
bool isPossible, isDone, isValidOne;

bool isValid( int cu_r, int cu_c ){

    cout<<cu_r<<" "<<cu_c<<" v .."<<endl;

    if( cu_r >=1 && cu_r <= r && cu_c >=1 && cu_c <= c && v[cu_r][cu_c] == -1 ) return true;
    return false;
}

void knightTour(  int cu_r, int cu_c, int cuV );

void allTour( int cu_r, int cu_c, int cuV ){
    isValidOne = false;
    int temp_r, temp_c, temp_ri, temp_ci, a_i, b_i, ta_i;
    for( a_i=1; a_i<=4; a_i++ ) {
        for( b_i=1; b_i<=2; b_i++ ){
            ta_i = a_i;
            if( a_i == 3 ) ta_i = 1;
            if( a_i == 4 ) ta_i = 2;
        temp_ri = vt2[ta_i]; temp_ci = vt1[b_i];
        if( a_i > 2 ) swap( temp_ri, temp_ci );
        temp_r = cu_r + temp_ri; temp_c = cu_c + temp_ci;
        //cout<<temp_r<<" "<<temp_c<<endl;
            if( isValid( temp_r, temp_c ) ){
                    isValidOne = true;
                    knightTour( temp_r, temp_c, cuV );
            }
        }
    }


}

void clearIt(){
    int a_i, b_i;
    for( a_i=1; a_i<=r; a_i++ ) for( b_i=1; b_i<=c; b_i++ ) v[a_i][b_i] = -1;
}

void knightTour( int cu_r, int cu_c, int cuV ){
    cout<<cuV<<" "<<cu_r<<" "<<cu_c<<endl;
    int a_i, b_i, n, temp, t_c;

    if( isDone ) return;
    if( cuV == r*c ) isDone = true;
    v[cu_r][cu_c] = cuV;
    // check all possible tour.
    allTour( cu_r, cu_c, cuV+1 );
    if( !isValidOne ){
    v[cu_r][cu_c] = -1;
    knightTour( cu_r, cu_c, cuV-=1 );
    return;
    }
}

void startFromAll(){
    int a_i, b_i, c_i, d_i;

    for( a_i=1; a_i<=r; a_i++ ) {
            for( b_i=1; b_i<=c; b_i++ ){
                clearIt();
                isDone = false;
                knightTour( a_i, b_i, 1 );

                if( !isDone ) cout<<"Not Possible!"<<endl;
        else
        cout<<"Possible!"<<endl;
        for( c_i=1; c_i<=r; c_i++ ){
            for( d_i=1; d_i<=c; d_i++ ){
                cout<<v[c_i][d_i]<<" ";
            }
            cout<<endl;
        }


            }
    }
}

int main(){
    int a_i, b_i, n, temp;


    cin>>r>>c;
    v.resize( r+1, vector < int > ( c+1, -1 ) );
    vt1.resize( 3 );
    vt2.resize( 3 );
    vt1[1] = 1; vt1[2] = -1; vt2[1] = 2; vt2[2] = -2;


    knightTour( 1, 1, 1 ); // starting with the first cell

    //startFromAll();

    if( !isDone ) cout<<"Not Possible!"<<endl;
    else
        cout<<"Possible!"<<endl;
        for( a_i=1; a_i<=r; a_i++ ){
            for( b_i=1; b_i<=c; b_i++ ){
                cout<<v[a_i][b_i]<<" ";
            }
            cout<<endl;
        }



}
