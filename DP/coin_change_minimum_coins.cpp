#include<bits/stdc++.h>
using namespace std;
int cont;

int minCoins(vector<int> &coins,vector<int> & store,int noOfCoins,int money){
    cont++;
    if(money<0)return INT_MAX-1;
    if(money==0)return 0;
    if(store[money]!=-1)return store[money];
    int mini=INT_MAX;
    for(int a_i=0;a_i<noOfCoins;a_i++)
        store[money]=mini=min(mini,(minCoins(coins,store,noOfCoins,money-coins[a_i])+1));

    return store[money];
}

int main(){
    int testCase,money,a_i,b_i,noOfCoins;
    cin>>noOfCoins;
    vector<int> coins(noOfCoins);
    for(a_i=0;a_i<noOfCoins;a_i++)cin>>coins[a_i];
    while(cin>>money){
    vector<int>store(money+1,-1);
    cont=0;
    cout<<minCoins(coins,store,noOfCoins,money)<<endl;
    cout<<cont<<endl;

   // for ( a_i=0; a_i<=c; a_i++ )cout<<a_i <<" : "<<coins[a_i]<<endl;

    }
}
