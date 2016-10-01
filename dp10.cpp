#include "bits/stdc++.h"
using namespace std;
//geek for geeks 
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
typedef long long int ll;
vector<vector<int> > dp;
vector<vector<char> > arr;
vector<vector<bool> > isVisited;
int m,n;
unordered_map<char,pair<int,int> > map1;
bool isvalidPoint(int x,int y)
{
    if(x>=0 and x<m and y>=0 and y<n)
    {
        return true;
    }
    return false;
}
int findRes(int x,int y)
{
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    int maxPath=1,i,j;
    isVisited[x][y]=true;
    Forall(i,-1,1)
    {
        Forall(j,-1,1)
        {
            if(i==0 and j==0) continue;
            
            if(isvalidPoint(x+i,y+j) and arr[x+i][y+j]-arr[x][y]==1 and isVisited[x+i][y+j]==false)
            {
                maxPath=max(maxPath,findRes(x+i,y+j)+1);
            }
        }
    }
    return dp[x][y]=maxPath;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>m>>n;
    int i,j,k;
    char x;
    For(i,0,m)
    {
        arr.push_back(vector<char> ());
        dp.push_back(vector<int>(n+1,-1));
        isVisited.push_back(vector<bool>(n+1,false));
        For(j,0,n)
        {
            cin>>x;
            arr[i].push_back(x);
            map1[x]=make_pair(i,j);
        }
    }  
    char start;
    cin>>start;
    
    cout<<"\n the final res is "<<findRes(map1[start].first,map1[start].second)<<"\n";
    cout<<"dp is \n";
    For(i,0,m)
    {
        For(j,0,n)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
