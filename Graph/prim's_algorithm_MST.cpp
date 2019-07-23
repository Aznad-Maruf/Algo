#include<bits/stdc++.h>
using namespace std;

void primesMst(vector<pair<int,int>> &mst,vector<vector<pair<int,int>> > &v){
    int s=v.size();
    bool isProcessed[s]={};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    pq.push(make_pair(0,1));
    int weight[s],tw=0;
    for(int a_i=1;a_i<s;a_i++)weight[a_i]=INT_MAX;
    weight[1]=0;
    bool will;
    while(!pq.empty()){
        int cuNode=pq.top().second;
        pq.pop();
        if(isProcessed[cuNode])continue;
        isProcessed[cuNode]=true;
        will=false;
        for(auto x: v[cuNode]){
            if(weight[cuNode]+x.first<weight[x.second]){
                weight[x.second]=weight[cuNode]+x.first;
                pq.push(make_pair(weight[x.second],x.second));
                will=true;
            }
        }
        if(cuNode==pq.top().second)continue;
        if(!will)continue;
        mst.push_back(make_pair(cuNode,pq.top().second));
        tw+=pq.top().first;
    }
    cout<<tw<<endl;
}

void addEdge(int n1, int n2, int w, vector<vector<pair<int, int>> >&v){
    v[n1].push_back(make_pair(w,n2));
    v[n2].push_back(make_pair(w,n1)); //if it's an undirected graph.
}

int main(){
    int a_i,n1,n2,w,temp,noOfNodes,noOfEdges;
    cin>>noOfNodes>>noOfEdges;
    vector<vector<pair<int,int>> >v(noOfNodes+1);
    while(noOfEdges--){
        cin>>n1>>n2>>w;
        addEdge(n1,n2,w,v);
    }

    vector<pair<int,int>> mst;
    primesMst(mst,v);
    for(a_i=0;a_i<mst.size();a_i++)cout<<mst[a_i].first<<" - "<<mst[a_i].second<<endl;
}
