#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCase, a_i, b_i, n, temp, maxArea, l, r,tp, areaWithTop;
    cin>>testCase;
    while(testCase--){
        cin>>n;
        vector < int > v(n);
        for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];

        maxArea=0;
        a_i=0;
        stack < int > st;
        while( a_i < n ){

                /// If stack is empty or current value is greater then top's value push.
            if( st.empty() || v[st.top()] <= v[a_i] ){
                st.push(a_i++);
            }
            else{

                tp=st.top();
                st.pop();
            /// Calculate area with the top as it can't go to right anymore.
            /// And the covered area at left if stack is empty then
            /// it's just the index+1(+1 is done in the if part)
            /// Otherwise it's index-previous top-1
            /// as everything greater then tp will be popped out
                areaWithTop = v[tp]*( st.empty() ? a_i : a_i-st.top()-1 );
                maxArea = max( maxArea, areaWithTop );
            }
        }
        /// now a_i=n;
        /// the elements which don't have any smaller value after them will survive.
        /// and they all will cover till nth index as they will stay in increasing order.
        while( !st.empty() ){
            tp=st.top();
            st.pop();

            areaWithTop = v[tp]*( st.empty() ? a_i : a_i-st.top()-1 );
            maxArea = max( maxArea, areaWithTop );
        }
        cout<<maxArea<<endl;

    }
}
