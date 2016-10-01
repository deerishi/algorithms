//SPOJ IS IT A TREE?
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
void createSet();
int findSet(int x);
int unionMerge(int x,int y);

int N,M;
vector<int> parent,ranks;
vector<pair<int,int> > edges;

void createSet()
{
  int i,j;
  Forall(i,0,N)
  {
    parent.push_back(i);
    ranks.push_back(0);
  }
}

int findSet(int x)
{
  if(x!=parent[x])
    parent[x]=findSet(parent[x]);
  return parent[x];
}


int unionMerge(int x,int y)
{
  int px=findSet(x);
  int py=findSet(y);
  if(px==py)
  {
    return 0;
  }
  if(ranks[px]>ranks[py])
  {
    parent[py]=px;
  }
  else
  {
    parent[px]=py;
  }
  if(ranks[px]==ranks[py])
  {
    ranks[py]=ranks[py]+1;
  }
  return 1;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin>>N>>M;
  int i,j,k,x,y;
  For(i,0,M)
  {
    cin>>x>>y;
    edges.push_back(make_pair(x,y));
  }
  createSet();
  ForIter(it1,edges)
  {
    x=it1->first;
    y=it1->second;
    if(!unionMerge(x,y))
    {
      cout<<"NO\n";
      return 0;
    }
  }
  cout<<"YES\n";
  return 0;
  
}
