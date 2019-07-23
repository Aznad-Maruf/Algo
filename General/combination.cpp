#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a_i,b_i,p;
    cin>>n;
    char ara[n],bi[n];
    //initialize
    for(a_i=0;a_i<n;a_i++){
            ara[a_i]='0';
            bi[a_i]='0';
    }
    //ara[0]='1';

    //total combination
    int l=pow(2,n);

    for(a_i=1;a_i<=l;a_i++){
        for(b_i=0;b_i<n;b_i++){
                p=pow(2,b_i);

                //changing value
                if(a_i%p==0){
                       bi[b_i]=ara[b_i];
                    if(ara[b_i]=='1')ara[b_i]='0';
                    else ara[b_i]='1';
            }
            else
            bi[b_i]=ara[b_i];
        }
        //reversing string
       for(int c_i=n-1;c_i>=0;c_i--)cout<<bi[c_i];
       cout<<endl;
    }
}
