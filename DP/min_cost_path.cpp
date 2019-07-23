#include<bits/stdc++.h>
using namespace std;

int mCost(vector<vector<int> > &grid,vector<vector<int> >&v,int r1,int c1,int r,int c){
    if(r1<0||c1<0)return INT_MAX;
    if(v[r1][c1]!=-1)return v[r1][c1];
    int temp= min(mCost(grid,v,r1-1,c1,r,c),(min(mCost(grid,v,r1,c1-1,r,c),mCost(grid,v,r1-1,c1-1,r,c))));
    v[r1][c1]=grid[r1][c1];
    if(temp!=INT_MAX)v[r1][c1]+=temp;
    return v[r1][c1];
    cout<<"a"<<endl;
}

int main(){
    int r,c,a_i,b_i,r1,c1;
    cin>>r>>c;
    vector<vector<int> > grid(r,vector<int>(c));
    for(a_i=0;a_i<r;a_i++)for(b_i=0;b_i<c;b_i++)cin>>grid[a_i][b_i];
    vector<vector<int> > v(r,vector<int> (c,-1));
    cin>>r1>>c1;
    cout<<mCost(grid,v,r1,c1,r,c)<<endl;;
}
