//SPOJ RENT 

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);

#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
struct Job
{
  int start,end,profit;

  //Job():start(0),end(0),profit(0){}
  //Job(int x,int y,int z): start(x),end(y),profit(z){}
};
bool cmp(Job a,Job b)
{
    return a.end<b.end;
}
vector<Job> arr;
int main()
{
  std::ios::sync_with_stdio(false);
  int n,i,j,k;
  cin>>n;
 
    arr.push_back({0,0,0});
//arr[0].start=0;arr[0].end=0;arr[0].profit=0;
  
  int x,y,z;
  Forall(i,1,n)
  {
    
    cin>>x>>y>>z;
    cout<<"x,y,z="<<x<<","<<y<<","<<z<<"\n";
arr.push_back({x,y,z});
    //arr[i].start=x;arr[i].end=y;arr[i].profit=z;
    cout<<"arr["<<i<<"] is "<<arr[i].start<<","<<arr[i].end<<","<<arr[i].profit<<"\n";
  }
  cout<<"before arr is \n";
  Forall(i,1,n)
  {
    cout<<arr[i].start<<","<<arr[i].end<<","<<arr[i].profit<<"\n";
  }
  cout<<"\n";
  sort(arr.begin(),arr.end(),cmp);
  cout<<"arr is \n";
  Forall(i,1,n)
  {
    cout<<arr[i].start<<","<<arr[i].end<<","<<arr[i].profit<<"\n";
  }
  cout<<"\n";
 
  return 0;
}
