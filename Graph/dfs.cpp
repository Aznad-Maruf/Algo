#include<bits/stdc++.h>
using namespace std;

void addEdge(vector < int > *graph, int n1, int n2 ){
    graph[ n1 ].push_back( n2 );
    graph[ n2 ].push_back( n1 );
}

void dfs( vector < int > *graph, vector < bool > &isVisited, int n ){
    if( isVisited[ n ] )return;
    isVisited[ n ] = true;
    cout<<n<<" ";
    for( int x : graph[ n ] ){
        dfs( graph, isVisited, x );
    }
}

int main(){
    int noOfNodes, noOfEdges, a_i, b_i, n1, n2,n;
    cin>>noOfNodes>>noOfEdges;
    vector < int > graph[ noOfNodes+1 ];
    vector<bool> isVisited(noOfNodes+1,false);
    while( noOfEdges -- ){
        cin>>n1>>n2;
        addEdge(graph,n1,n2);
    }

    cin>>n;
    dfs( graph, isVisited, n );
}
