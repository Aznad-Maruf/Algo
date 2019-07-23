#include<bits/stdc++.h>
using namespace std;

vector < vector < pair < int, int > > > graph;
vector < int > d;
int noOfNodes, maxi = 10e7;

bool bellmanFord( int s ){
    int a_i, b_i, c_i, temp, w, n;
    d[s] = 0; // starting node's distance is initially zero.
    bool is = false;

    // if it got negative cycle it would reduce distance in last round.
    for( a_i=1; a_i<=noOfNodes; a_i++ ){
        for( b_i=1; b_i<=noOfNodes; b_i++ ){
            for( pair < int, int > x : graph[b_i] ){
                    w = x.second, n = x.first;
                if( d[b_i]+w < d[n] ){
                    d[n] = d[b_i]+w;
                    if( a_i == noOfNodes ) is = true;
                }
            }
        }
    }

    return is;
}

void addEdge( int n1, int n2, int w ){
    graph[n1].push_back( make_pair( n2, w ) );
}

int main(){
    int a_i, b_i, noOfEdges, n1, n2, w, s;
    cin>>noOfNodes>>noOfEdges;
    graph.resize( noOfNodes+1 );
    d.resize( noOfNodes+1, maxi );
    while( noOfEdges-- ){
        cin>>n1>>n2>>w;
        addEdge( n1, n2, w );
    }

    cin>>s;
    if( bellmanFord(s) ) cout<<"Negative Cycle!"<<endl;

    else
    for( a_i=1; a_i<=noOfNodes; a_i++ ) cout<<s<<" - "<<a_i<<" : "<<d[a_i]<<endl;

}
