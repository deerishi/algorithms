//Geek for geeks buy and sell a stock at most k times
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr;
int dp[100][100][2];
int end1;
int findMAx(int start,int k,bool buy)
{
    cout<<"solving problem for start,k,buy = ("<<start<<","<<k<<","<<buy<<")\n";
    if(dp[start][k][int(buy)]!=-1)
    {
        return dp[start][k][int(buy)];
    }
  int res1=0,res2=0;
  if(k<1 or start>end1)
  {
    return 0;
  }
  if(start==end1)
  {
    if(buy)
      return 0;
    else
      return arr[start];
  }
  if(buy)
  {
    res1+=max(-arr[start]+findMAx(start+1,k,false),findMAx(start+1,k,true));
  }
    else
    {
      res2+=max(arr[start]+findMAx(start+1,k-1,true),findMAx(start+1,k,false));
    }
    return dp[start][k][int(buy)]=max(res1,res2);
}

int main()
{
  std::ios::sync_with_stdio(false);
  int i,j,k,m,n,x;
  cin>>n>>k;
  memset(dp,-1,sizeof(dp));
  For(i,0,n)
  {
    cin>>x;
    arr.push_back(x);
  }
  end1=n-1;
  cout<<"the result is "<<findMAx(0,k,true)<<"\n";
  return 0;
}
