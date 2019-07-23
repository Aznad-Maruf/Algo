#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long maximumLimit,a_i,b_i,minimumLimit;
    //The output will be the primes between these two.
    cin>>minimumLimit>>maximumLimit;
    bool isCross[maximumLimit+1];
    vector<long long>primes;

    //1 indicates primes and 0 indicates not prime.
    //setting all to primes
    for(a_i=1;a_i<=maximumLimit;a_i++)isCross[a_i]=1;

    //2 is prime
    if(minimumLimit<=2)
    primes.push_back(2);

    //we will avoid even numbers
    for(a_i=3;a_i*a_i<=maximumLimit;a_i+=2){
        if(isCross[a_i]){

                // if it's prime then the loop will start from a_i*a_i. because all less then a_i*a_i has already been cut by previous primes
                for(b_i=a_i*a_i;b_i<=maximumLimit;b_i+=a_i){
                    isCross[b_i]=0;
                }
        }
    }

    //minimumLimit must start with odd as we are avoiding even
    if(minimumLimit%2==0)minimumLimit+=1;
    if(minimumLimit<=1)minimumLimit=3;

    for(a_i=minimumLimit;a_i<=maximumLimit;a_i+=2){
        if(isCross[a_i])primes.push_back(a_i);
    }

    //output
    for(a_i=0;a_i<primes.size();a_i++)cout<<a_i+1<<" : "<<primes[a_i]<<endl;
}
