#include<bits/stdc++.h>
using namespace std;

void quickSort(int*, int, int);

int main(){
    int total_number,a_i;
    cin>>total_number;
    int ara[total_number+1];
    for(a_i=1;a_i<=total_number;a_i++)cin>>ara[a_i];
    quickSort(ara,1,total_number);
    for(a_i=1;a_i<=total_number;a_i++)cout<<ara[a_i]<<" ";
}

void quickSort(int* ara,int lo,int hi){
    if(lo>=hi)return;
    int pivot,a_i,i;
    pivot=ara[lo];
    i=lo;
    for(a_i=lo+1;a_i<=hi;a_i++){
        if(ara[a_i]<pivot){
                swap(ara[++i],ara[a_i]);
        }
    }
    swap(ara[i],ara[lo]);
    quickSort(ara,lo,i-1);
    quickSort(ara,i+1,hi);
}
