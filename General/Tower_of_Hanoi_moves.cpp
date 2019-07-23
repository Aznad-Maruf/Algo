#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n,char *a,char *b,char *c,int *cont){
    /**base case
        when only one left just shift it to the destination.a to b.
    */
    if(n==1){
        cout<<++*cont<<" : "<<*a<<"-->"<<*b<<endl;
        return;
    }
    /**shift all the rest except the last to the 3rd pillar*/
    towerOfHanoi(n-1,a,c,b,cont);

    /**when done shift the left over to the destination. a to b*/
    cout<<++*cont<<" : "<<*a<<"-->"<<*b<<endl;

    /**shift all the rest except the last to the 1st pillar.following line would do that.*/
    towerOfHanoi(n-1,c,b,a,cont);

}

int main(){
    int n,cont=0;
    char a='1',b='2',c='3';
    cin>>n;
    towerOfHanoi(n,&a,&b,&c,&cont);
}
