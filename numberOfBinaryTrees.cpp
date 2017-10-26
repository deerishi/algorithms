#include "bits/stdc++.h"
using namespace std;
//Leetcode Valid Binary Trees
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
#define long long int ll;


class Solution {
public:
    int  findRes(int n,vector<int>&dp){
    int i;
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n<2){
        return 1;
    }
    int res=0;
    For(i,1,n+1){
        res+=findRes(i-1)*findRes(n-i);
    }
    return dp[n]=res;
}
    int numTrees(int n) {
        vector<int> dp(1000,-1);
        return findRes(n,dp);
    }
};
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,n,x,y;
    cin>>n;
    ull res=findRes(n);
    cout<<"Res is "<<res<<"\n";
    return 0;
}
