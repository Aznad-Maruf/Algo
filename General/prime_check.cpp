#include<bits/stdc++.h>
using namespace std;

bool checkPrime(long long num);

int main(){
    long long num;
    cin>>num;
    if(checkPrime(num)){
        cout<<"Prime"<<endl;
    }
    else
        cout<<"Not Prime"<<endl;
}

bool checkPrime(long long num){
    long long checkingWith,difference;
    if(num<=1)return false;
    else if(num==2||num==3||num==5)return true;
    else if(num%2==0||num%3==0)return false;
    //num<=25 will be checked with above conditions
    else{
        checkingWith=5;
        difference=2;
        //num<25 will not get in the loop
        while(checkingWith*checkingWith<=num){
                //condition of above means that the loop will run when num>=sqrt(checkingWith). here sqrt will consume more complexity
                // so that's not been used  and * looks more smart then sqrt() anyway.
            if(num%checkingWith==0)return false;
            checkingWith+=difference;
            difference=6-difference;
            //difference will first be 2 then 4 then 2 and goes on... thus the checkingWith series will be : 5 7 11 13 17 .....
            //as %3 is taken care of here divisibility of 3 is taken care of, no num is divisible by 3 here.
        }
        return true;
        //it's prime if no number divides it upto sqrt(num)
    }
}
