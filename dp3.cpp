//Geek for geeks Find the longest path in a matrix with given constraints
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<vector<int> > dp;
vector<vector<int> >arr;
int n;
//dp state dp[i][j]:: Length of the longest increasing path at i,j

int findRes(int x,int y)
{
    vector<int> plengths;
    bool flag=false;
    if(x+1<n and arr[x+1][y]-arr[x][y]==1)
    {
        int temp=1+findRes(x+1,y);
        plengths.push_back(temp);
        flag=true;
    }
    if(x-1>=0 and arr[x-1][y]-arr[x][y]==1)
    {
         int temp=1+findRes(x-1,y);
        plengths.push_back(temp);
        flag=true;
    }
    if(y+1<n and arr[x][y+1]-arr[x][y]==1)
    {
        int temp=1+findRes(x,y+1);
        plengths.push_back(temp);
        flag=true;
    }
    if(y-1>=0 and arr[x][y-1]-arr[x][y]==1)
    {
        int temp=1+findRes(x,y-1);
        plengths.push_back(temp);
        flag=true;
    }
    if(flag==false)
    {
        return dp[x][y]=1;
    }
    else
    {
        return dp[x][y]=*max_element(plengths.begin(),plengths.end());
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,x;
    cin>>n;
    For(i,0,n)
    {
        dp.push_back(vector<int>());
        arr.push_back(vector<int>());
        For(j,0,n)
        {
            dp[i].push_back(-1);
            cin>>x;
            arr[i].push_back(x);
        }
    }
    int max1=INT_MIN;
    For(i,0,n)
    {
        For(j,0,n)
        {
            max1=max(max1,findRes(i,j));
        }
    }
    cout<<"res is "<<max1<<"\n";
    cout<<"\n the dp array is \n";
    For(i,0,n)
    {
        For(j,0,n)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
