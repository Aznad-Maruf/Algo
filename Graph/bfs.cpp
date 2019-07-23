#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> *graph, int n1, int n2 ){
    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
}

void bfs(vector<int> *graph, vector< int > &d, vector<bool> &is ){
    int a_i,b_i,n;
    queue< int > Q;
    cin>>n;
    Q.push(n);
    is[n] = true;
    while( !Q.empty() ){
        int temp=Q.front();
        Q.pop();

        cout<<temp<<" : ---> "<<d[temp]<<endl;

        for( int x : graph[temp] ){
                if (!is[x] ){
            Q.push(x);
            is[x]=true;
            d[x]=d[temp]+1;
            }
        }
    }
}

int main(){
    int noOfNodes, noOfEdges, a_i, b_i, n1,n2,n;

    cin>> noOfNodes>>noOfEdges;

    vector < int > graph[noOfNodes+1];
    vector< int > d( noOfNodes+1, 0 );
    vector < bool > is ( noOfNodes+1, false );

    while( noOfEdges-- ){
        cin>>n1>>n2;
        addEdge( graph, n1, n2 );
    }

    bfs( graph, d, is) ;
}
