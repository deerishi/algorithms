//SPOJ RENT 

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

struct Job
{
  int start,end,profit;
  bool operator<(Job b)
  {
    return end<b.end;
  }
  //Job():start(0),end(0),profit(0){}
  //Job(int x,int y,int z): start(x),end(y),profit(z){}
};
vector<Job> arr;
vector<vector<int> > dp;

int findMaxProfit(int prevStart,int index)
{
  //cout<<"Solving subproblem "<<prevStart<<","<<index<<"\n";
  //cout<<"dp["<<prevStart<<"]["<<index<<"] is "<<dp[prevStart][index]<<"\n";
  if(dp[prevStart][index]!=-1)
  {
    return dp[prevStart][index];
  }
  if(index<1)
  {
    return 0;
  }
  int res1=0,res2=0;
  if(arr[index].end<=prevStart)
    res1=arr[index].profit + findMaxProfit(arr[index].start,index-1);
  
  res2=findMaxProfit(prevStart,index-1);
  //cout<<"Solving subproblem "<<prevStart<<","<<index<<" with result "<<max(res1,res2)<<"\n";
  return dp[prevStart][index]=max(res1,res2);

}

int main()
{
  std::ios::sync_with_stdio(false);
  int n,i,j,k,t;
  cin>>t;
  while(t--){
  cin>>n;

  arr.push_back({0,0,0});  
  int x,y,z;
  For(i,0,1000001)
  {
    dp.push_back(vector<int>(10001,-1));
    /*For(j,0,100)
    {
      dp[i].push_back(-1);
      // cout<<"dp["<<i<<"]["<<j<<"] is "<<dp[i][j]<<" ";
      }*/
    //cout<<"\n\n";
  }
  
  Forall(i,1,n)
  {
    Job a;
    cin>>x>>y>>z;
    //cout<<"x,y,z="<<x<<","<<y<<","<<z<<"\n";
    arr.push_back({x,y+x,z});
  }
  /* cout<<"before arr is \n";
  Forall(i,1,n)
  {
    cout<<arr[i].start<<","<<arr[i].end<<","<<arr[i].profit<<"\n";
  }
  cout<<"\n";*/
  sort(arr.begin(),arr.end());
  /* cout<<"arr is \n";
  Forall(i,1,n)
  {
    cout<<arr[i].start<<","<<arr[i].end<<","<<arr[i].profit<<"\n";
  }
  cout<<"\n";*/
  int res=0;
  Forall(i,1,n)
  {
    res=max(res,arr[i].profit+findMaxProfit(arr[i].start,i-1));
  }
  cout<<res<<"\n";
  }
  return 0;
}
