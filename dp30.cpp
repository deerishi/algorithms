#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<int> arr;
int findRes()
{
    int n=arr.size(),temp;
    vector<int> dp(100,0);
    int i,j;dp[0]=arr[0],dp[1]=max(arr[1],arr[0]);
    For(i,2,n)
    {
        temp=max(dp[i-1],arr[i]);
        dp[i]=max(dp[i-2]+arr[i],temp);
    }
    return dp[n-1];
   
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,x,i,j,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        arr.clear();
        For(i,0,n)
        {
            cin>>x;
            arr.push_back(x);
        }
        cout<<"the result is "<<findRes()<<"\n";    
    }
    return 0;
}
