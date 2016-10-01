//Geek for geeks Minimum Possible Size of an array

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr;
int dp[100][100];
int n,k;
int findMin(int start,int end)
{
  int i,j,l,res=0;
  if(start>end)
  {
    return 0;
  }
  if(end-start+1<3)
  {
    return end-start+1;
  }
  if(end-start +1 ==3  and arr[end]==arr[end-1]+k and arr[end-1]==arr[start]+k)
  {
    return 0;
  }
  else if(end-start +1 ==3  and (arr[end]!=arr[end-1]+k or arr[end-1]!=arr[start]+k))
  {
    return 3;
  }
  For(i,start,end-2)
  {
    For(j,i+1,end-1)
    {
      For(l,j+1,end)
      {
        if(arr[j]==arr[i]+k and arr[l]==arr[j]+k and findMin(i+1,j-1)==0 and findMin(j+1,k-1)==0)
        {
          
        }
      }
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  int i,j,x;
  cin>>n>>k;
  
  For(i,0,n)
  {
    cin>>x;
    arr.push_back(x);
  }
  memset(dp,-1,sizeof(dp));
  
}
