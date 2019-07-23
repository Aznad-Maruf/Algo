#include<bits/stdc++.h>
using namespace std;

int main(){
    int base,p,m,ans=1;
    cin>>base>>p;
    while(p>0){
        if(p%2)ans*=base;
        p/=2;
        base*=base;
    }
    cout<<ans<<endl;
}
