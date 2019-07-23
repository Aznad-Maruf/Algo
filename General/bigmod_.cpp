#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef for(int a,a<=n;a++);

long long po(long long n,long long p,long long m){
    if(p==1)return n%m;
    if(p==0)return 1;
    long long temp= po(n,p/2,m);
    temp*=temp;
    temp%=m;
    if(p%2!=0)temp*=n;
    return temp%m;

}

int main(){
    long long n,p,m=1000000007;
    cin>>n>>p;
    cout<<po(n,p,m)<<endl;
    main();
}
