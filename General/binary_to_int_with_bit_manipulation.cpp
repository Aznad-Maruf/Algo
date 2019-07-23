#include<bits/stdc++.h>
using namespace std;

int main(){
    long long num,a_i,one=1;

    while(cin>>num){
            cout<<(log10(num))/log10(2.0)<<endl;
            string binary="";
    //counting digit into converted binary.
    //taking the value to double as it shows some distortion if int is used. e.g. digit shows 3 for 8 if int is used.
    double d=((log10(num))/log10(2.0))+1;
    int digit=d;

    for(a_i=digit-1;a_i>=0;a_i--){
            //checking one by one bit if it is one or not.
        if((num&(one<<a_i))==0)binary+="0";
        else binary+="1";
    }
    cout<<binary<<endl;
    }
}
