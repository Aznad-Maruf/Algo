#include<bits/stdc++.h>
using namespace std;
int cont1=0,cont2=0;

/*
// naive solution
int lcm(string st1,string st2,int s1,int s2){
    cont1++;
    if(s1==0||s2==0)return 0;
    if(st1[s1-1]==st2[s2-1])return 1+lcm(st1,st2,s1-1,s2-1);
    else return max(lcm(st1,st2,s1-1,s2),lcm(st1,st2,s1,s2-1));
}
*/

/// Dp solution
int lcm(vector<vector<int> > &grid,string st1,string st2,int s1,int s2){
    cont2++;
    if(s1==0||s2==0)return 0;
    if(grid[s1-1][s2-1]!=-1)return grid[s1-1][s2-1];
    if(st1[s1-1]==st2[s2-1])return grid[s1-1][s2-1]=1+lcm(grid,st1,st2,s1-1,s2-1);
    else return grid[s1-1][s2-1]=max(lcm(grid,st1,st2,s1-1,s2),lcm(grid,st1,st2,s1,s2-1));
}

int main(){
    int a_i,b_i,n,m,s1,s2,ans;
    string st1,st2;
    cin>>st1>>st2;
    s1=st1.size(),s2=st2.size();
    vector<vector<int> > grid(s1,vector<int> (s2,-1));
    /*
    cout<<lcm(st1,st2,s1,s2)<<endl;
    cout<<cont1<<endl;
    */
    cout<<lcm(grid,st1,st2,s1,s2)<<endl;
    cout<<cont2<<endl;
}
