#include "bits/stdc++.h"
using namespace std;
//SPOJ DATING RISHI
typedef unsigned long long int ll;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr;
vector<int> dp;
int findMaxSum()
{
    int i,maxSofar=arr[0],curSum=arr[0],n=arr.size();dp.push_back(arr[0]);
    int end1=0;
    For(i,1,n)
    {
        curSum=max(curSum+arr[i],arr[i]);
        if(maxSofar<curSum) maxSofar=curSum,end1=i;
        
        dp.push_back(maxSofar);
    }
    //now we find starting and end position of the subarray
    int sum=maxSofar;
    for(i=end1;i>=0 and sum!=0;i--)
    {
        sum-=arr[i];
    }
    i++;
    cout<<"the subarray is p["<<i<<","<<end1<<"]\n";
    return maxSofar;
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
    int i,j,n,t,x;
    cin>>t;
    while(t--)
    {
        cin>>n; 
        arr.clear();dp.clear();
        For(i,0,n)
        {
            cin>>x;
            arr.push_back(x);
        }
        cout<<"the max is "<<findMaxSum()<<"\n";
        printDp();
    }
    return 0;
}
