#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int n;
vector<vector<int> > dp;
int findRes(int num,int trial){
    cout<<"num,trial are "<<num<<","<<trial<<"\n";
    if(num==n){
        return 0;
    }
    if(abs(num)>n){
        return INT_MAX;
    }
    int res1,res2;
    res1=findRes(num+trial,trial+1);
    res2=findRes(num-trial,trial+1);
    if(res1!=INT_MAX){
        res1++;
    }
    if(res2!=INT_MAX){
        res2++;
    }
    return min(res1,res2);
}
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,x,k;
    cin>>n;

    int res=findRes(0,1);
    cout<<"result is "<<res<<"\n";
}
