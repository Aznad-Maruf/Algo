#include<bits/stdc++.h>
using namespace std;

int bitOn(int n,int r){
    int temp=1;
    temp<<=r;
    return n|temp;
}

bool bitCheck(int n,int r){
    int temp=1;
    temp<<=r;
    if(n&temp==0)return false;
    else return true;
}

int bitOff(int n,int r){
    if(!bitCheck(n,r))return n;
    int temp=1;
    temp<<=r;
    return n^temp;
}

int main(){
    int n,n1,n2,r;
    cin>>n;
    n1=n;
    string st="",stOn="",stOff="";
    while(n>0){
        if(n%2==0)st+='0';
        else st+='1';
        n/=2;
    }
    reverse(st.begin(),st.end());
    cout<<st<<endl;

/*
    ///Bit on
    cin>>r;
    n2=bitOn(n1,r);
    cout<<n2<<endl;
    n=n2;
    stOn="";
        while(n>0){
        if(n%2==0)stOn+='0';
        else stOn+='1';
        n/=2;
    }
    reverse(stOn.begin(),stOn.end());
    cout<<stOn<<endl;

    ///Bit off
    cin>>r;
    n2=bitOff(n1,r);
    cout<<n2<<endl;
    n=n2;
    st="";
        while(n>0){
        if(n%2==0)st+='0';
        else st+='1';
        n/=2;
    }
    reverse(st.begin(),st.end());
    cout<<st<<endl;

    */

    /// count no. of ones
    /*
    __builtin_popcount = int
    __builtin_popcountl = long int
    __builtin_popcountll = long long
    */
    cout<<__builtin_popcount(n1)<<endl; //

    main();
}
