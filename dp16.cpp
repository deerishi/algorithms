//Geek for geeks Tiles

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int end1;
struct Job
{
  int start,end,profit;
  bool operator<( Job b)
  {
    return end<b.end;
  }
};
vector<Job> jobs;
vector<vector<int> > dp;
int findMax(int start)
{
  int i,j,k;
  int res1=0,res2=jobs[start].profit;
  
  For(i,start+1,end1)
  {
    if(jobs[start].end<=jobs[i].start)
    {
      res1=max(res1,jobs[start].profit+findMax(i));
    }
    else
    {
      res2=max(res2,findMax(i));
    }
  }
  cout<<"Returning "<<max(res1,res2)<<"for start = "<<start<<"\n";
  return max(res1,res2);
  
}
int main()
{
  int n,i,j,k,s,e,p;
  cin>>n;
  For(i,0,n)
  {
    Job j;
    cin>>j.start>>j.end>>j.profit;
    jobs.push_back(j);
    dp.push_back(vector<int>(500,0));
  }
  dp.push_back(vector<int>(500,0));
  sort(jobs.begin(),jobs.end());
  cout<<"You entered\n";
  For(i,0,n)
  {
    cout<<jobs[i].start<<","<<jobs[i].end<<","<<jobs[i].profit<<"\n";
  }
  end1=n;
  cout<<"The max is "<<findMax(0)<<"\n";
  return 0;
}
