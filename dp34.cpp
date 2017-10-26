//Geek for geeks Minimize steps to reach destination .This being the better solution since it memoziazes

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int n;
unordered_map<int,int> map1;
int findRes(int position,int numStep){

    if(map1.find(position)!=map1.end()){
        if(map1[position]<=numStep){
            return INT_MAX;
        }
    }

    if(position==n){
        return 0;
    }
    if(position<-n or position>n ){
        return INT_MAX;
    }

    cout<<"For position , numStep "<<position<<","<<numStep<<"\n";
    int res1=findRes(position+numStep,numStep+1);
    int res2=findRes(position-numStep,numStep+1);

    if(res1!=INT_MAX){
        res1=1+res1;
    }
    if(res2!=INT_MAX){
        res2=1+res2;
    }
    map1.insert(make_pair(position, min(res1,res2)));
    return min(res1,res2);
}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n;
    int res=findRes(0,1);
    if(res==INT_MAX){
        cout<<"-1 Not Possible\n";
        return 0;
    }
    cout<<"res is "<<res<<"\n";

}
