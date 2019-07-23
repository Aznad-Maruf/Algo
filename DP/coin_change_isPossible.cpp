#include<bits/stdc++.h>
using namespace std;

vector< int > is(10e6, -1 );

bool ist;
int cont;
bool isPossible( int n, int s, vector< int > &v, vector <int > &ve ){
    cont++;
    if(ist)return true;
    if( n<0 ) return false;
    if( v[ n ]== 0 ) return false;
    if( v[n ] == 1 ) return true;
    for( int a_i=0; a_i< s; a_i++ ){
            //cout<<n-ve[a_i]<<endl;
         ist=isPossible( n-ve[a_i], s, v, ve );
    //cout<<ve[a_i]<<endl;
    }
    return v[n]= ist;
}

int main(){
    int n, a_i, b_i, temp, s ;
    ist=false;
    cin>>s;
    vector <int > ve(s);
    for( a_i=0; a_i< s; a_i++ )cin>>ve[a_i];
    while(cin>>n){
            ist=false;
            vector < int > v(n+1, -1 );
            v[0]= true;
            cont=0;
             ist=isPossible(n, s, v, ve );
             cout<<cont<<endl;
    if(ist)cout<<"Yes!"<<endl;
    else cout<<"Nah!"<<endl;
    }

}
