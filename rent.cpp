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
};
vector<Job> arr;

int findMaxProfit(int prevStart,int index)
{
  //cout<<"Solving subproblem "<<prevStart<<","<<index<<"\n";
  if(index<1)
  {
    return 0;
  }
  int res1=0,res2=0;
  if(arr[index].end<=prevStart)
    res1=arr[index].profit + findMaxProfit(arr[index].start,index-1);

  res2=findMaxProfit(prevStart,index-1);
  cout<<"Solving subproblem "<<prevStart<<","<<index<<" with result "<<max(res1,res2)<<"\n";
  return max(res1,res2);

}
int main()
{
  std::ios::sync_with_stdio(false);
  int n,i,j,k;
  cin>>n;
  Job b;
  b.start=0;
  b.end=0;
  b.profit=0;
  arr.push_back({0,0,0});
  int x,y,z;
  For(i,0,n)
  {
    Job a;
    cin>>x>>y>>z;
   
    arr.push_back({x,x+y,z});
  }
  sort(arr.begin(),arr.end());
  cout<<"arr is \n";
  Forall(i,1,n)
  {
    cout<<arr[i].start<<","<<arr[i].end<<","<<arr[i].profit<<"\n";
  }
  cout<<"\n";
  int res=0;
  Forall(i,1,n)
  {
    res=max(res,arr[i].profit+findMaxProfit(arr[i].start,i-1));
  }
  cout<<"the max profit is "<<res<<"\n";
  return 0;
}
