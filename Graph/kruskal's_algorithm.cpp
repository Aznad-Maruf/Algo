#include<bits/stdc++.h>
#include<tuple>
using namespace std;

void addEdge(vector<tuple<int,int,int> >& graph, int a, int b,int w){
    graph.push_back(make_tuple(a,b,w));
}

bool comp(tuple<int,int,int> n1,tuple<int,int ,int> n2){
    return get<2>(n1)<get<2>(n2);
}

int root(vector<int>&point,int n){
    while(point[n]!=n){
        n=point[n];
    }
    return n;
}

void unite(vector<int>&point,vector<int>&treeSize,int r1,int r2){
        if(treeSize[r1]>treeSize[r2])swap(r1,r2);
        point[r2]=r1;
        treeSize[r2]+=treeSize[r1];
    }

int main(){
    vector<tuple<int,int,int> >edges;

    edges.push_back(make_tuple(0,0,-1));

    int a,b,w,n=3,temp=3;
    while(temp--){
            cin>>a>>b>>w;
    addEdge(edges,a,b,w);  /// graph as edge list here.
    }


    sort(edges.begin(),edges.end(),comp);  /// sort the edges according to their weight.
    //for(int a_i=0;a_i<edges.size();a_i++)cout<<get<0>(edges[a_i])<<" "<<get<1>(edges[a_i])<<" "<<get<2>(edges[a_i])<<endl;
   vector<int>point(n+1,0);  /// indicates the node where it is pointing to.
   vector<int>treeSize(n+1,0); /// indicates the tree size whose parent is index.

   for(int a_i=1;a_i<=n;a_i++)point[a_i]=a_i; ///initially all nodes points to itself.
   for(int a_i=1;a_i<=n;a_i++)treeSize[a_i]=1; /// initially all tree has just a single element

   //KruskalsMinimumSpanningTree------>
   vector<pair<int,int>> mst; /// vector to store the minimum spanning tree.
           int totalWeight=0;
   for(int a_i=1;a_i<=n;a_i++){
        int n1=get<0>(edges[a_i]); ///first node
        int n2=get<1>(edges[a_i]); ///second node
        int r1=root(point,n1); ///root of first node
        int r2=root(point,n2); /// root of second node

        if(r1!=r2){ ///when the nodes are not in the same tree
                unite(point,treeSize,r1,r2); /// take them into the tree
                if(r1>r2)swap(n1,n2); /// just to make the list good.
                totalWeight+=get<2>(edges[a_i]);
            mst.push_back(make_pair(n1,n2)); /// adding a edge to mst.
        }
   }

cout<<"Weight : "<<totalWeight<<endl<<"Edges : "<<endl;
 for(auto x: mst){
        cout<<x.first<<" "<<x.second<<endl;
     }

}
