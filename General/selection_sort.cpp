#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a_i,b_i,mini,indx;
    cin>>n;
    int ara[n];
    for(a_i=0;a_i<n;a_i++)cin>>ara[a_i];
    for(a_i=0;a_i<n-1;a_i++){
        mini=ara[a_i];
        indx=a_i;
        for(b_i=a_i+1;b_i<n;b_i++){
            if(ara[b_i]<mini){
                    mini=ara[b_i];
                    indx=b_i;
            }
        }
        swap(ara[a_i],ara[indx]);
    }
    for(a_i=0;a_i<n;a_i++)cout<<ara[a_i]<<"  ";
}
