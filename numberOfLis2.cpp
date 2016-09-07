#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
#define mod 5000000
vector<vector<int> > dp;
int findNumberOfIncreasingSubsequences(vector<int>& arr,int k)
{   
    int i,j,p;
    dp.push_back(vector<int>());
    Forall(i,1,arr.size())
    {
        dp.push_back(vector<int>());
        dp[i].push_back(0);
        For(j,1,arr.size())
        {
            if(j==1)
            {
               dp[i].push_back(1);
            }
            else
            {
                dp[i].push_back(0);
            }
        }
    }
    Forall(i,2,arr.size())
    {
        Forall(j,1,i-1)
        {
            if(arr[i-1]>arr[j-1])
            {
                Forall(p,2,k)
                {
                    dp[i][p]+=dp[j][p-1];
                    dp[i][p]%=mod;
                }
            }
        }
    }
    /*cout<<"\n the dp table is \n";
    Forall(i,1,arr.size())
    {
        Forall(j,1,k)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int res=0;
    Forall(i,1,arr.size())
    {
        res=(res+dp[i][k])%mod;
    }
    res=res%mod;
    return res;
}
int main()
{
    int i,j,n,x,k;
    vector<int> arr;
    cin>>n>>k;
    int min1=INT_MAX;
    For(i,0,n)
    {
        cin>>x;
        if(min1>x)
        {
            min1=x;
        }
        arr.push_back(x);
    }
    cout<<"the number of increasing subsequences of length "<<k<<" is "<<findNumberOfIncreasingSubsequences(arr,k)<<"\n";
    return 0;
}
