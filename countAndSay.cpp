#include "bits/stdc++.h"
using namespace std;
//geek for geeks 
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
string NextOne(string prev){
    int i,j,k,count=1;
    string next="";
    char digit=prev[0],pdigit;
    i=1;
    while(i<prev.length()){
        
        pdigit=digit;
        while(digit==prev[i]){
            count++;
            i++;
            
        }
        digit=prev[i];
        next=next+to_string(count);
       
        next=next+pdigit;
        //cout<<"1next is "<<next<<"\n";
        count=0;
    }
    return next;
    
}

int main(){
    std::ios::sync_with_stdio(false);
    int i,j,n,k;
    cin>>n;string str="11",start="1";
    For(i,2,n){
        str=NextOne(str);
        cout<<"next is "<<str<<"\n\n";
    }
    return 0;
}
