#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > graph;
vector < bool > isVisited;
vector < int > previous;
vector < int > enterTime;
vector < int > leftTime;
stack < int > stk;
int t;
bool isCycle;


void addEdge( int n1, int n2 ){
    graph[n1].push_back( n2 );
}

void dfs(){
    int a_i, b_i, n, temp, cuN;
    if( stk.empty() ) return;
    cuN = stk.top();
    stk.pop();
    t++;
    enterTime[cuN]=t;
    isVisited[cuN] = true;
    for( int x : graph[cuN] ){
            cout<<x<<endl;
            if( !isVisited[x] ){
                previous[x] = cuN;
                stk.push( x );
                dfs();
            }
            else{
                if( enterTime[x] < enterTime[cuN] ) isCycle = true;
            }
    }
    t++;
    leftTime[cuN] = t;

}

int main(){
    int a_i, b_i, noOfNodes, noOfEdges, n1, n2, w;

    cin>>noOfNodes>>noOfEdges;

    graph.resize( noOfNodes+1 );
    isVisited.resize( noOfNodes+1, false);
    enterTime.resize( noOfNodes+1 );
    leftTime.resize( noOfNodes+1 );
    previous.resize( noOfNodes+1 );

    while( noOfEdges-- ){
        cin>>n1>>n2;
        addEdge( n1, n2 );
    }

    isCycle = false;

    for( a_i=1; a_i<=noOfNodes; a_i++ ){
        if( !isVisited[a_i] ){
                stk.push( a_i );
                dfs();
        }
    }

    for( a_i=1; a_i<=noOfNodes; a_i++ ) cout<<a_i<<" -> "<<enterTime[a_i]<<" "<<leftTime[a_i]<<endl;

    if( isCycle ) cout<<"Cycle"<<endl;
    else cout<<"NoCycle"<<endl;


}
