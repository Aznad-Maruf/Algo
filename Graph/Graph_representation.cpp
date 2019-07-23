#include<bits/stdc++.h>
using namespace std;

void addEdge( vector< int > *graph, int n1, int n2 ){

    graph[n1].push_back(n2);
    graph[n2].push_back(n1); /// For undirected graph.
}

void addEdge( vector < pair < int, int > > *graph, int n1, int n2, int w ){
    graph[ n1 ].push_back( make_pair( n2, w ) );
    graph[ n2 ].push_back( make_pair( n1, w ) );
}

int main(){


/// Unweighted graph.------>>
//    int noOfNodes, noOfEdges, a_i, b_i, n1, n2, w ;
//    cin>>noOfNodes>>noOfEdges;
//    vector< int > graph[noOfNodes+1];
//    while(noOfEdges--){
//        cin>>n1>>n2;
//        addEdge( graph, n1, n2 );
//    }
//    for(a_i=1;a_i<=noOfNodes;a_i++){
//            cout<<a_i<<" : ";
//        for(int x : graph[a_i]) cout<<x<<" ";
//        cout<<endl;
//    }

/// Weighted graph. --------->>
int noOfNodes, noOfEdges, n1, n2, w, a_i, b_i;

cin>>noOfNodes>>noOfEdges;

vector < pair < int, int > > graph[noOfNodes+1];

for ( a_i = 1 ; a_i <=noOfEdges ; a_i++ ){
    cin>>n1>>n2>>w;
    addEdge( graph, n1, n2, w );
}
for( a_i=1; a_i <= noOfNodes; a_i++ ){
        cout<<a_i <<"------->"<<endl;
    for( pair < int, int > p : graph[ a_i ] )cout<<p.first<<" "<<p.second<<endl;
    cout<<endl;
}


}
