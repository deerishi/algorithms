#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)
int n,arr[1005];
int dp[1005][1005];
int find(int start,int end)
{
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    if(end==start+1)
    {
        
        return abs(arr[end]-arr[start]);
    }
    
    int a1,a2;
    //If person 1 chooses arr[start]
    if(arr[start+1]>=arr[end])
    {
        a1=arr[start]-arr[start+1]+find(start+2,end);
    }
    else
    {
        a1=arr[start]-arr[end]+find(start+1,end-1);
    }
    
    //if person 1 choooses arr[end]
    if(arr[start]>=arr[end-1])
    {
        a2=arr[end]-arr[start]+find(start+1,end-1);
    }
    else
    {
        a2=arr[end]-arr[end-1]+find(start,end-2);
    }
    dp[start][end]=max(a1,a2);
    return max(a1,a2);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,i,j,k;
    
    k=1;
    while(1)
    {
        cin>>n;
        if(n==0)
        {
            return 0;
        }
        For(i,0,n)
        {
            cin>>arr[i];
        }
        For(i,0,n)
        {
            For(j,0,n)
            {
                dp[i][j]=-1;
            }
        }
        
        cout<<"In game "<<k<<", the greedy strategy might lose by as many as "<<find(0,n-1)<<" points.\n";
        k++;
    }
    return 0;
}
