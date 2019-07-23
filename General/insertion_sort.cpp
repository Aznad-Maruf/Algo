#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a_i,b_i;
    cin>>n;
    int ara[n];
    for(a_i=0;a_i<n;a_i++)cin>>ara[a_i];
    for(a_i=1;a_i<n;a_i++){
        for(b_i=a_i-1;b_i>=0;b_i--){
            if(ara[b_i]>ara[b_i+1])swap(ara[b_i],ara[b_i+1]);
            else
                break;
        }
    }
    for(a_i=0;a_i<n;a_i++){
        cout<<ara[a_i]<<" ";
    }
}
