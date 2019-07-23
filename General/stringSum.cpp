#include<bits/stdc++.h>
using namespace std;

string sum( string st1, string st2 ){
    int s1, s2, a_i, b_i, temp, n1, n2, sum, c;
    string st, tS;
    char cc;
    s1= st1.size();
    s2=st2.size();
    if( s1> s2 )swap( st1, st2 );
    temp=abs( s1-s2 );
    tS="";
    while( temp-- ) tS+='0';
    st1=tS+st1;
    cout<<st1<<" "<<st2<<endl;
   s2=st2.size()-1;
    st="";
    c=0;
    while( s2>=0 ){
        n1=st1[s2]-'0';
        n2=st2[s2]-'0';
        sum=n1+n2+c;
        c=sum/10;
        sum%=10;
        cc=sum+'0';
        st+=cc;
        s2--;
    }
    cc = c+'0';
    if( cc>'0')st+=cc;
    reverse(st.begin(), st.end() );

    return st;
}

int main(){
    int n1, n2, a_i, b_i, temp;
    string st1, st2, stS, tS;
    cin>>st1>>st2;
    cout<<sum( st1, st2 )<<endl;
}
