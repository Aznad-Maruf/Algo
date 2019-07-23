#include<bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    int frequency;
    node* left;
    node* right;

};


 // taken from stackOverflow
//priority_queue<Node*, vector<Node*>, DereferenceCompareNode> nodesToCheck;
 // to compare based on frequency in pq.
struct comp : public std::binary_function<node*, node*, bool>
{
    bool operator()( const node* n1, const node* n2 ) const
    {
        return n1->frequency > n2->frequency;
    }
};

unordered_map < char, int > um;
unordered_map < char, string > code;
priority_queue < node *, vector< node* >, comp > pq;
node * root;


void createHuffmanTree(){

    //enter all to priority queue
    unordered_map < char, int > :: iterator it;
    for( it = um.begin(); it!= um.end(); it++ ){

        node * n = new node; // create a new node
        n->ch = it->first; // assign the character
        n->frequency = it->second; // assign frequency
        n->left = NULL;
        n->right = NULL;
        pq.push( n );
    }

    while( pq.size() > 1 ){

//        cout<< pq.top()->ch << " " << pq.top()->frequency << endl;
//        pq.pop();

        node * n1 = pq.top(); // less frequency
        pq.pop();
        node * n2 = pq.top(); // more frequency
        pq.pop();

        // create a node and make n1, n2 it's child
        node * n = new node;
        n->ch = '\0'; // null char
        n->frequency = n1->frequency+n2->frequency;
        n->left = n1;
        n->right = n2;
        pq.push( n );

    }

    root = pq.top();
    pq.pop();


}

void assignCode( node* temp, string st ){

    if( temp == NULL ) return;

    assignCode( temp->left, st+'0' );
    assignCode( temp->right, st+'1' );
    if( temp->ch != '\0' ) code[temp->ch] = st;

}


string deCode( string st ){
    int a_i, b_i, l = st.size();
    string decodedString = "";
    node* temp = root;
    for( a_i=0; a_i<l; a_i++ ){

            // when it's not a null then we found a char and we will initialize temp as root
            // and continue from next st value for new char

        if( st[a_i] == '0' ) temp = temp->left;
        if( st[a_i] == '1' ) temp = temp->right;

            if( temp ->ch != '\0' ){
                decodedString += temp->ch;
                temp = root;
                continue;
        }

    }
    return decodedString;
}


int main(){
    int a_i, b_i, n, temp, l;
    string st, codedString, decodedString;
    char c;
    getline( cin, st );
    l = st.size();

    for( a_i=0; a_i<l; a_i++ ){
        c = st[a_i];
        um[c]++;
    }

    createHuffmanTree();
    assignCode( root, "" );

    // printing the code for each char
    unordered_map < char, string > :: iterator it;
    for( it = code.begin(); it!=code.end(); it++ ) cout<<it->first<<" "<<it->second<<endl;
    cout<<endl;

    // generating encoded string
    codedString = "";
    for( a_i=0; a_i<l; a_i++ ) codedString+= code[st[a_i]];

    // printing encoded string
    cout<<codedString<<endl;

    decodedString = deCode( codedString );
    cout <<decodedString<<endl;


}
