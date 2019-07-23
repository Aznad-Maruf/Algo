#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > dis;
vector < vector < int > > parent;
int noOfNodes, maxi = 10e7;

// prints in reverse order
/*
void pathPrint( int src, int des ){
    int a_i, b_i, temp;
    cout<<des<<" ";
    if( parent[src][des] == src ){
        cout<<src<<" ";
        return;
    }
    des = parent[src][des];
    pathPrint( src, des );


}

*/
void pathPrint( int src, int des ){
    //cout<<des<<"";
    int a_i, b_i, n;
    if( src == des ){
        cout<<src<<" ";
        return;
    }
    pathPrint(src, parent[src][des] );
    cout<<des<<" ";
}

void floyedWarshall(){
    int a_i, b_i, c_i, temp, d;
    for( a_i=1; a_i<=noOfNodes; a_i++ ){
        for( b_i=1; b_i<=noOfNodes; b_i++ ){
            for( c_i=1; c_i<=noOfNodes; c_i++ ){
                //dis[b_i][c_i] = min( dis[b_i][c_i], dis[b_i][a_i]+dis[a_i][c_i] );
                if( dis[b_i][a_i]+dis[a_i][c_i] < dis[b_i][c_i] ){
                    dis[b_i][c_i] = dis[b_i][a_i]+dis[a_i][c_i];
                    parent[b_i][c_i] = a_i;
                }
            }
        }
    }
}

int main(){
    int a_i, b_i, n, temp, n1, n2, w, noOfEdges;
    cin>>noOfNodes>>noOfEdges;
    dis.resize( noOfNodes+1, vector < int > ( noOfNodes+1, maxi ));
    parent.resize( noOfNodes+1, vector < int > ( noOfNodes+1, -1 ));

    // initialized
    for( a_i=0; a_i<=noOfNodes; a_i++ ){
        dis[a_i][a_i] = 0;
        parent[a_i][a_i] = a_i;
    }

    while( noOfEdges-- ){
        cin>>n1>>n2>>w;
        dis[n1][n2] = w;
        parent[n1][n2] = n1;
    }

    floyedWarshall();
    cin>>n1>>n2;
    cout<<dis[n1][n2]<<endl;

    pathPrint( n1, n2 );

}
