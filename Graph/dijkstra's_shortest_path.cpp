#include<bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
typedef vector < ii > iiv;

int noOfNodes, noOfEdges, maxi = 1e9;

vector < vector < pair < int, int > > > graph;
vector < int > dis;

void dijkstra( int src ){
    int a_i, b_i, n, temp;
    ii pp;
    vector < bool > isVisited( noOfNodes+1, false );
    dis[src] = 0;
    priority_queue < ii, iiv, greater < ii > > pq;

    pq.push( make_pair( 0, src ) );

    while( !pq.empty() ){
        pp = pq.top();
        n = pp.second;
        pq.pop();

        if( isVisited[n] ) continue;
        isVisited[n] = true;

        for( auto x: graph[n] ){
            if( dis[x.second] > dis[n]+x.first ){
                dis[x.second] = dis[n] + x.first;
                pq.push( make_pair( dis[x.second], x.second ) );
            }
        }
    }
}

int main(){
    int a_i, b_i, temp, n1, n2, d;

    cin>>noOfNodes>>noOfEdges;

    graph.resize( noOfNodes+1 ); dis.resize( noOfNodes+1, maxi );

    while( noOfEdges-- ){
        cin>>n1>>n2>>d;

        graph[n1].push_back( make_pair( d, n2 ) );

    }

    dijkstra( 1 );

    for( a_i=2; a_i<=noOfNodes; a_i++ ) cout<<dis[a_i]<<" ";
    cout<<endl;

}
