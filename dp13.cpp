//Geek for geeks Collect maximum value in 2 traversals

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int r,c;
int  dp[100][100][100];
vector<vector<int> > arr;
vector<int> moves;

int findRes(int x,int y1,int y2)
{
   //cout<<"x = "<<x<<" y1="<<y1<<" y2="<<y2<<"\n";
  if(dp[x][y1][y2]!=-1)
  {
    return dp[x][y1][y2];
  }
  if(x==r-1 and y1==0 and y2==c-1)
  {
    return arr[x][y1]+arr[x][y2];
  }
  if(x==r-1  and (y1!=0 or y2!=c-1))
  {
    return INT_MIN;
  }
  if(y1<0 or y2<0 or y1>=c or y2>=c)
  {
    return INT_MIN;
  }
  int result;
  if(y1==y2)
  {
    result=arr[x][y1];
  }
  else
  {
    result=arr[x][y1]+arr[x][y2];
  }
  vector<int> possibleMoves;
  for(auto const &move1 : moves)
  {
    for(auto const &move2 : moves)
    {
        
      possibleMoves.push_back(findRes(x+1,y1+move1,y2+move2));
    } 
  }
  //cout<<"*max_element(possibleMoves.begin(),possibleMoves.end()) is "<<*max_element(possibleMoves.begin(),possibleMoves.end())<<"\n";
  return dp[x][y1][y2]= result + *max_element(possibleMoves.begin(),possibleMoves.end());
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>r>>c;
    moves.push_back(-1);
    moves.push_back(0);
    moves.push_back(1);
    int i,j,k,x;
    memset(dp,-1,sizeof(dp));
    For(i,0,r)
    {
      arr.push_back(vector<int>());
      For(j,0,c)
      {
        cin>>x;
        arr[i].push_back(x);
      }
    }
    //cout<<"the dp table is \n";
    cout<<"\n res is "<<findRes(0,0,c-1)<<"\n";
    
    return 0;
}
