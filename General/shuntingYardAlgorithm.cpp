#include<bits/stdc++.h>
using namespace std;

string stInfix, stPostfix;
stack < char > stk;
map < char, int > mp;

double evaluateIt( string st ){
    int a_i, b_i, n s = st.size();

    stack < char > stk1, stk2;

    for( a_i = s-1; a_i>=0; a_i-- ) stk2.push( st[a_i] );

    while( !stk2.empty() ){

    }

}

void infixToPostfix(){
    int a_i, b_i, n, temp, l;
    char ch, ch2, cuCH, chT;
    l = stInfix.length();

    for( a_i=0; a_i<l; a_i++ ){
        cuCH = stInfix[a_i];
        if( mp[cuCH] == 0 ) stPostfix += cuCH; // is it is not an operator add it to output string.
        else{
                if( stPostfix)
            if( stk.empty() ){
                cout<<"Empty"<<endl;
                stk.push( cuCH );
            }
            else{

                if( cuCH == '(' ) stk.push( '(' );
                else if( cuCH == ')' ){
                        cout<<"Got"<<endl;
                    while( !stk.empty() ){
                        cout<<stk.top()<<endl;
                        if( stk.top() == '(' ){
                            stk.pop();
                            break;
                        }
                        else{
                            stPostfix += stk.top();
                            stk.pop();
                        }
                    }
                }

                else{
                        cout<<cuCH<<endl;

                    if( mp[cuCH] >= mp[stk.top()] ) stk.push( cuCH );



                    else{
                        while( !stk.empty() && mp[stk.top()] > mp[cuCH] ){
                            stPostfix += stk.top();
                            stk.pop();
                        }
                        stk.push(cuCH);
                }
                 cout<<stk.top()<<endl;
            }
        }
    }

    cout<<stPostfix<<endl;

    }

    while( !stk.empty() ){
        stPostfix += stk.top();
        stk.pop();
    }

}

void initializeMap(){
    mp['('] = -1;
    mp[')'] = -1;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
}

int main(){
    int a_i, b_i, n, temp;

    initializeMap();

    cin>>stInfix;

    stPostfix = "";

    infixToPostfix();
    cout<<stPostfix<<endl;

    cout<<evaluateIt( stPostfix )<<endl;

}
