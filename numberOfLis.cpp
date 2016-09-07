#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

int dp[100][100];
int findNumberOfIncreasingSubsequences(vector<int>& arr,int k)
{
    int i,j,p;
    Forall(i,1,arr.size())
    {
        For(j,1,arr.size())
        {
            if(j!=1) dp[i][j]=0;
            else dp[i][j]=1;
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
                }
            }
        }
    }
    int res;
    cout<<"\n the DP table is \n";
    Forall(i,1,arr.size())
    {
        Forall(j,1,k)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    Forall(i,1,arr.size())
    {
        res+=dp[i][k];
    }
    return res;
}
int main()
{
    int i,j,n,x,k;
    vector<int> arr;
    cin>>n>>k;
    For(i,0,n)
    {
        cin>>x;
        arr.push_back(x);
    }
    cout<<"\n the number of increasing subsequences of length "<<k<<" is "<<findNumberOfIncreasingSubsequences(arr,k)<<"\n";
    return 0;
}
