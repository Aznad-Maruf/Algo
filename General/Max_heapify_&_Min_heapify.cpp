#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int *ara,int n,int i){
    if(i<1)return;
    int root=i,left=2*i,right=2*i+1;
    if(left<=n){
        if(ara[left]>ara[root])swap(ara[left],ara[root]);
    }
    if(right<=n){
        if(ara[right]>ara[root])swap(ara[right],ara[root]);
    }
    maxHeapify(ara,n,--i);
}

void minHeapify(int *ara,int n,int i){
    if(i<1)return;
    int root=i,left=2*i,right=2*i+1;
    if(left<=n){
        if(ara[left]<ara[root])swap(ara[left],ara[root]);
    }
    if(right<=n){
        if(ara[right]<ara[root])swap(ara[right],ara[root]);
    }
    minHeapify(ara,n,--i);
}

int main(){
    int n,a_i,b_i;
    cin>>n;
    int ara[n+1];
    for(a_i=1;a_i<=n;a_i++)cin>>ara[a_i];
    for(a_i=n/2;a_i>=1;a_i--)
        maxHeapify(ara,n,n/2);

        cout<<"Max Heap -----> ";
        for(a_i=1;a_i<=n;a_i++)cout<<ara[a_i]<<" ";
        cout<<endl;

        for(a_i=n/2;a_i>=1;a_i--)
        minHeapify(ara,n,n/2);

        cout<<"Min Heap -----> ";
        for(a_i=1;a_i<=n;a_i++)cout<<ara[a_i]<<" ";
        cout<<endl;
}
