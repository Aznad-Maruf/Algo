#include<bits/stdc++.h>
using namespace std;

vector < string > v;

const int alphabetSize = 26;

struct node{
    node* child[alphabetSize];
    bool isWordFinished;
};

node* createNode(){
    node* temp = new node;
    for( int a_i=0; a_i<alphabetSize; a_i++ ) temp -> child[a_i] =NULL;
    temp -> isWordFinished = false;
    return temp;
}

void insertIt( node* root, string st ){
    int a_i, b_i, s = st.size(), n, index;
    node* tempR = root;
    for( a_i=0; a_i<s; a_i++ ){
        index = st[a_i] - 'a';
        if( !tempR -> child[index] ) tempR ->child[index] = createNode();
        tempR = tempR -> child[index];
    }
    tempR -> isWordFinished = true;
}

bool searchIt( node* tempR, string st ){
    int a_i, b_i, s=st.size(), n, temp;
    for( a_i=0; a_i<s; a_i++ ){
        int index = st[a_i] - 'a';
        if( !tempR -> child[index] ) return false;
        tempR = tempR -> child[index];
    }
    if( tempR -> isWordFinished ) return true;
    return false;
}


int main(){
    int a_i, b_i, n, temp, testCase;
    string st, st1, st2;

    cin>>testCase;
    while( testCase-- ){
    cin>>n;
    v.resize( n );
    for( a_i=0; a_i<n; a_i++ ) cin>> v[a_i];

    node *root = createNode();

    for( a_i=0; a_i<n; a_i++ ) insertIt( root, v[a_i] );

    cin>>st2;
    cout<<searchIt( root, st2 )<<endl;
    v.clear();
    }

}
