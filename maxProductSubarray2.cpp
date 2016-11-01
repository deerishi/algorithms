#include "bits/stdc++.h"
using namespace std;
//SPOJ DATING RISHI
typedef unsigned long long int ll;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<int> arr,dp;

int findMaxProductSubarray()
{
    int temp,i,n=arr.size(),curMax=arr[0],curMin=arr[0],max1;
    dp.push_back(arr[0]);
    For(i,1,n)
    {
        temp=max(curMax*arr[i],curMin*arr[i]);
        curMax=max(arr[i],temp);
        
        temp=min(curMax*arr[i],curMin*arr[i]);
        curMin=min(arr[i],temp);
        
        max1=max(curMax,curMin);
        dp.push_back(max1);
    }
}
void printDp()
{
    for(auto it=dp.begin();it!=dp.end();it++)
    {
        cout<<*it<<" , ";
    }
    cout<<"\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,i,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        For(i,0,n)
        {
            cin>>x;
            arr.push_back(x);
        }
        cout<<"the maxProduct in a subarray is "<<findMaxProductSubarray()<<"\n and the dp is \n";printDp();
    }
    return 0;
}
