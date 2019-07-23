#include<bits/stdc++.h>
using namespace std;

void pop();
void push(int);
int top();

int topi;
const int MAX_VALUE=1000000;
int ara[MAX_VALUE];

int main(){
    push(2);
    push(33);
    for(int a_i=1;a_i<=topi;a_i++)cout<<ara[a_i]<<" ";
    cout<<endl;
    pop();
    cout<<top()<<endl;
}

void pop(){
    if(topi==0){
        cout<<"Stack Underflow!"<<endl;
    }
    else topi--;
}
void push(int n){
    if(topi+1>MAX_VALUE)cout<<"Stack Overflow!"<<endl;
    else
        ara[++topi]=n;
}
int top(){
    return ara[topi];
}
