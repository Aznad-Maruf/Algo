#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > graph;
vector < bool > isVisited;
vector < int > inDegree;
priority_queue < int, vector < int > , greater < int >  > pq;

void addEdge( int n1, int n2 ){
    graph[n1].push_back( n2 );
}

int main(){
    int a_i, b_i, noOfNodes, noOfEdges, n1, n2;
    cin>>noOfNodes>>noOfEdges;
    graph.resize( noOfNodes+1 );
    isVisited.resize( noOfNodes+1, false );
    inDegree.resize( noOfNodes+1, 0 );
    while( noOfEdges-- ){
        cin>>n1>>n2;
        addEdge( n1, n2 );
        inDegree[ n2 ]++;
    }
}
