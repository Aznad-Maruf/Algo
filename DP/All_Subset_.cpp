#include<bits/stdc++.h>
using namespace std;

int main(){
    long long s,musk,n,a_i,b_i,temp;
    cin>>n;
    vector<int> v(n);
    for(a_i=0;a_i<n;a_i++)cin>>v[a_i];
    s=pow(2,n)-1;

    for(musk=0;musk<=s;musk++){
        for(b_i=0;b_i<n;b_i++){
                temp=1;
            if(musk&(temp<<=b_i))cout<<v[b_i]<<" ";
        }
        cout<<endl;
    }
}
