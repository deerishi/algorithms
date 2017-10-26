#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int n;

int findRes(int start,vector<int> &arr,int dp[1000][2],int buy){
    int i,j,k;
    if(dp[start][buy]!=-1){
        return dp[start][buy];
    }
    if(start>=arr.size()){
        return 0; //base case
    }
    //Each time we have 2 options either to buy this one or to sell this one
    int res;
    if(buy)
        res=max(-arr[start]+findRes(start+1,arr,dp,0),findRes(start+1,arr,dp,1));
    else
        res=max(arr[start]+findRes(start+1,arr,dp,1),findRes(start+1,arr,dp,0));
    return dp[start][buy]=res;

}
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,k,x;
    vector<int> arr;
    int dp[1000][2];
    memset(dp,-1,sizeof(dp));
    while(1){
        cin>>x;
        if(cin.fail()) break;
        arr.push_back(x);

    }
    n=arr.size();
    int res=max(-arr[0]+findRes(1,arr,dp,0),findRes(1,arr,dp,1));
    cout<<"the result is "<<res<<"\n";
}
