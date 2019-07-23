#include<bits/stdc++.h>
using namespace std;

// O(n) complexity . as each node will be pushed to the stack once.

int main(){
    int testCase, a_i, b_i, a_t, n, maxi=-1, tp, temp ;

    cin>>n;
    vector < int > v(n);
    for( a_i=0; a_i<n; a_i++ )cin>>v[ a_i ];

    stack < int > s;
    a_i=0;
    while( a_i<n ){

        /// If the stack is empty or new element is greater then or equal to top element push.
        /// stack is non decreasing.
        if(s.empty()|| v[ a_i ] >= v[s.top() ]){
                s.push(a_i++);
        }

        /// else calculate with the popped value.
        else{
            tp= s.top();
            s.pop();
            temp = v[tp]*( s.empty() ? a_i : a_i-s.top()-1);
            //cout<<v[tp]<<" "<<temp<<endl;
            maxi=max(temp, maxi);
        }
    }


    while( !s.empty() ){
        tp=s.top();
        s.pop();
        temp=v[tp]* ( s.empty() ? a_i : a_i-tp-1);
        maxi= max( temp, maxi );
    }
    cout<< "Maximum Area : "<<maxi <<endl;

}
