#include<bits/stdc++.h>
using namespace std;

void mergeSort(int*,int,int);
int main(){
    int n,a_i,b_i,lo,hi;
    cin>>n;
    int ara[n+1];
    for(a_i=1;a_i<=n;a_i++)cin>>ara[a_i];
    mergeSort(ara,1,n);
    for(a_i=1;a_i<=n;a_i++)cout<<ara[a_i]<<" ";
}

void mergeSort(int* ara, int lo, int hi){
    if(lo==hi)return;
    int mid,a_i,b_i;
    mid=(lo+hi)/2;
    mergeSort(ara,lo,mid);
    mergeSort(ara,mid+1,hi);
    vector<int>temp;
    for(a_i=lo,b_i=mid+1;a_i<=mid&&b_i<=hi;){
        if(ara[a_i]<ara[b_i]){
            temp.push_back(ara[a_i]);
            a_i++;
        }
        else{
            temp.push_back(ara[b_i]);
            b_i++;
        }
    }
    while(a_i<=mid){
        temp.push_back(ara[a_i]);
        a_i++;
    }
    while(b_i<=hi){
        temp.push_back(ara[b_i]);
        b_i++;
    }
    for(a_i=lo,b_i=0;a_i<=hi;a_i++,b_i++)ara[a_i]=temp[b_i];
    temp.clear();
}
