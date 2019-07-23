#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > graph;
vector < bool > isVisited;

void addEdge( int n1, int n2 ){
    graph[n1].push_back( n2 );
}

void ts( int n, stack < int > &st ){
    if( isVisited[n] ) return;
    isVisited[n]=true;
    for( int x : graph[n] ){
        ts( x, st );
    }
    st.push(n);
}

void topologicalSort(){
    int a_i, b_i, n, temp, s=graph.size();
    stack < int > st;
    for( a_i=1; a_i<s; a_i++ ){
        ts( a_i, st );
    }
    while( !st.empty() ){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main(){
    int noOfNodes, noOfEdges, a_i, b_i, n, n1, n2;

    cin>>noOfNodes>>noOfEdges;
    graph.resize( noOfNodes+1 );
    isVisited.resize( noOfNodes+1, false );

    while(noOfEdges--){
        cin>>n1>>n2;
        addEdge( n1, n2 );
    }

    topologicalSort();
}
