//Geek for geeks Tiles

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<vector<int> > dp;

ull findRes(int start,int end)
{
    cout<<"calling "<<start<<","<<end<<"\n";
    int i,j,k;
    ull res1,res2,res=0;
    if(dp[start][end]!=-1)
    {
        cout<<start<<","<<end<<" is "<<dp[start][end]<<"\n"; 
        return dp[start][end];
    }
    if(start==end)
    {
        cout<<start<<","<<end<<" is "<<1<<"\n"; 
        return 1;
    }
    
    Forall(i,start,start)
    {
        if(i+2<=end)
        {
            res+=findRes(i+2,end);
        }
        if(i+1<=end)
        {
            res+=findRes(i+1,end);
        }
        
    }
    cout<<start<<","<<end<<" is "<<res<<"\n";   
    return dp[start][end]=res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,m,n;
    cin>>n;
    Forall(i,0,n+2)
    {
        dp.push_back(vector<int>(n+2,-1));
    }
    ull res=0;
    Forall(i,0,0)
    {
        if(i+2<=n)
        {
            res+=findRes(i+2,n);
        }
        if(i+1<=n)
        {
            res+=findRes(i+1,n);
        }
        
    }

    cout<<"\n res is "<<res<<"\n";
    
    return 0;
}
