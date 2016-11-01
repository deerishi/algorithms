//Geek for geeks Find minimum sum such that one of every three consecutive elements is taken
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr;
int n;
int dp[100][100];
int findRes(int start,int end1){
    //cout<<"in "<<start<<","<<end1<<"\n";
    int i,j,res=INT_MAX,temp;
    if(end1<0 or start>=n or start>end1 or end1-start+1<3){
         //cout<<"ret 0\n";           
         return 0;
    }
    if(dp[start][end1]!=-1){
        //cout<<"dp is "<<dp[start][end1]<<"\n";
        return dp[start][end1];
    }
    
    For(i,start,end1+1){
        temp=arr[i]+findRes(start,i-1)+findRes(i+1,end1);
        //cout<<"temp is "<<temp<<"\n";
        res=min(res,temp);
        //cout<<"res is "<<res<<"\n\n";
    }
    //cout<<"returning "<<res<<" for "<<start<<","<<end1<<"\n\n";
    return dp[start][end1]=res;
}
int  main(){
    std::ios::sync_with_stdio(false);
    int t,i,j,x;
    while(1){
        cin>>x;
        if(cin.eof()) break;
        arr.push_back(x);
    }
    n=arr.size();
    memset(dp,-1,sizeof(dp));
    cout<<"the answer is "<<findRes(0,n-1)<<"\n";
    return 0;
}
