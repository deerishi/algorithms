#include "bits/stdc++.h"
using namespace std;
//SPOJ DATING RISHI
typedef unsigned long long int ll;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr,arr2,dp;
void findSubarray()
{
    int i,n=arr.size(),end1=0,maxSofar=arr[0],curSum=arr[0];
    For(i,1,n)
    {
        curSum=max(curSum+arr[i],arr[i]);
        if(maxSofar<curSum) maxSofar=curSum,end1=i;
    }
    int sum=maxSofar;
    for(i=end1;i>=0 and sum!=0;i--)
    { 
        sum-=arr[i];
    }
    i++;
    cout<<"the subarray to flip is ["<<i<<","<<end1<<"]\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,i,x,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        arr.clear();dp.clear();
        For(i,0,n)
        {
            cin>>x;
            (x==1)?arr.push_back(-1):arr.push_back(1);
        }
        cout<<"the subarray is ";findSubarray();cout<<"\n";
    }
    return 0;
    
}
