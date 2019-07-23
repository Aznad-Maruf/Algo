/**
G1={0,1};
Gn={0Gn-1,1G(reverse)};
so G2={00,01,11,10};
*/

#include<bits/stdc++.h>
using namespace std;

void grayCode(int n,vector<string>*v){

    /**base Case*/
    if(n==1){
       (*v).push_back("0");
       (*v).push_back("1");
       return;
    }
    /**recursion call*/
    grayCode(n-1,&(*v));

    /**declaring a temporary vector and adding the previous to make the new one*/
    vector<string>vf;
    for(int a_i=0;a_i<(*v).size();a_i++){
            string st="0"+(*v)[a_i];
        vf.push_back(st);
    }
    for(int a_i=(*v).size()-1;a_i>=0;a_i--){
        string st="1"+(*v)[a_i];
        vf.push_back(st);
    }
   (*v)=vf;
   /**deleting the temporary vector*/
   vf.clear();
}

int main(){
    int n;
    vector<string>v;
    cin>>n;
    grayCode(n,&v);
    for(int a_i=0;a_i<v.size();a_i++)cout<<v[a_i]<<endl;
}
