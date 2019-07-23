#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long maxLong=ULLONG_MAX;
    unsigned long long sqrtOfMaxLong=sqrt(maxLong)+1;
    //cout<<sqrtOfMaxLong<<endl;
    vector<unsigned long long> primeVector;
    primeVector.push_back(2);
    primeVector.push_back(3);
    unsigned long long checking=5,difference=2,num=5;
    int a_i;
    bool isPrime;
    while(checking<=1000000){
            isPrime=true;
        for(a_i=0;primeVector[a_i]*primeVector[a_i]<=checking;a_i++){
            if(checking%primeVector[a_i]==0)isPrime=false;
            //cout<<isPrime<<endl;
        }
        if(isPrime)primeVector.push_back(checking);
    checking+=difference;
    difference=6-difference;
    }
    for(a_i=0;a_i<primeVector.size();a_i++){
        cout<<a_i+1<<" : "<<primeVector[a_i]<<endl;
    }


}
