#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<int> dp(500,-1);
vector<int> arr;
int end1;
int findRes(int start)
{
    if(dp[start]!=-1) return dp[start];
    
    if(start==end1) return dp[start]=2;
    
    if(start>end1) return dp[start]=1;
    
    
    int res=findRes(start+1) +findRes(start+2);
    
    return dp[start]=res;
    
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,i,j,x,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        end1=n-1;
        For(i,0,n+5) dp[i]=-1;
        cout<<"the result is "<<findRes(0)<<"\n";
    }
    
    return 0;
}

