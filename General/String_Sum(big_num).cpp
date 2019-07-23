#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b,s1,s2,d,n1,n2,tS,tC,a_i;
    string st,st1,st2,stS,temp;
    cin>>a>>b;
    stringstream ss;
    ss<<a;
    st1=ss.str();
    ss.str(""); // empty the ss.
    ss<<b;
    st2=ss.str();
    //cout<<st1<<endl<<st2<<endl;
    s1=st1.size();
    s2=st2.size();
    if(s2>s1)swap(st1,st2); // s1 is bigger.
    d=abs(s1-s2); //length difference.
    temp="";
    while(d--)temp+='0'; //make them equal in length.
    st2=temp+st2;
    //cout<<st1<<endl<<st2<<endl;
    reverse(st1.begin(),st1.end());
    reverse(st2.begin(),st2.end());
    s1=max(s1,s2);
    stS="";
    tC=0;
    for(a_i=0;a_i<s1;a_i++){
        tS=(st1[a_i]-'0')+(st2[a_i]-'0')+tC;
        tC=tS/10;
        tS%=10;
        stS+=(char)(tS+'0');
    }
    if(tC>0)stS+=(char)(tC+'0');
    cout<<a+b<<endl;
    reverse(stS.begin(),stS.end());
    cout<<"Sum : "<<stS<<endl;
}
