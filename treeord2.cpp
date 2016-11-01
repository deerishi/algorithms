//SPOJ TREE ORDER
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> pre,post,in;
unordered_map<int,int> positionOfInOrder;
int precounter=0,postCounter=0;
void findRes(int start,int end1){
    int position=positionOfInOrder[pre[precounter]];
    precounter++;
    if(position-1>=start)
    findRes(start,position-1);
    
    if(position+1<=end1)
    findRes(position+1,end1);
    
    if(in[position]!=post[postCounter]){
        cout<<"no\n";exit(0);
    }
    postCounter++;
        
}
int main(){
    std::ios::sync_with_stdio(false);
    int i,n,x;
    cin>>n;
    For(i,0,n){
        cin>>x;
        pre.push_back(x);
    }
    For(i,0,n){
        cin>>x;
        post.push_back(x);
    }
    For(i,0,n){
        cin>>x;
        positionOfInOrder.insert(make_pair(x,i));
        in.push_back(x);
    }
    findRes(0,n-1);
    cout<<"yes\n";
    return 0;
    
}
