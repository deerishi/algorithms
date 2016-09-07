#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
#define mod 5000000
vector<vector<int> > dp;

int max1;
vector<int> num(4*max1+2,0);
void resetTree()
{
    num.clear();
    for(auto i=0;i<=4*max1;i++)
    {
        num.push_back(0);
    }
}

void update(int start,int end,int node,int rangeToUpdate,int val)
{
    //cout<<"start is "<<start<<" end is "<<end<<" rangeToUpdate is "<<rangeToUpdate<<"\n";
    if(rangeToUpdate >end or rangeToUpdate<start)
    {
        return;
    }
    if(start==end and start==rangeToUpdate)
    {
        //cout<<"earlier num node was "<<num[node]<<"\n";
        num[node]+=val;
        //cout<<"node is "<<node<<" rangeToUpdate is "<<rangeToUpdate<<" now val is "<<num[node]<<"\n";
        return;
    }
    int mid=(start+end)/2;
    update(start,mid,2*node,rangeToUpdate,val);
    update(mid+1,end,2*node+1,rangeToUpdate,val);
    num[node]=num[2*node+1]+num[2*node];
}

int query(int start,int end,int node,int x,int y)
{
    //basically if we have an overlap then go both e, if there is no overlap, then return -1
    if(y<start or x>end)
    {
        return -1;
    }
    if(start >= x and end<=y)
    {
        return num[node];
    }
    int mid=(start+end)/2;
    int left=query(start,mid,2*node,x,y);
    int right=query(mid+1,end,2*node+1,x,y);
    if(left==-1)
    {
        return right;
    }
    else if(right==-1)
    {
        return left;
    }
    else
    {
        return left+right;
    }
}

int main()
{
    int i,j,n,x,k,p;
    vector<int> arr;
    cin>>n>>k;
    max1=INT_MIN;
    //arr.push_back(0);//so we can start the indexing from 1
    For(i,0,n)
    {
        cin>>x;
        if(max1<x)
        {
            max1=x;
        }
        arr.push_back(x);
    }
    Forall(i,0,arr.size())
    {
        dp.push_back(vector<int>());
        dp[i].push_back(0);
        Forall(j,1,k)
        {
            if(j==1)
            {
               dp[i].push_back(1);
            }
            else
            {
                dp[i].push_back(0);
            }
        }
    }
    Forall(p,2,k)
    {
        resetTree();
        Forall(i,1,n)
        {
            update(0,max1,1,arr[i-1],dp[i-1][p-1]);
            
            dp[i][p]=(dp[i][p]+query(0,max1,1,0,arr[i]-1))%mod;
            dp[i][p]=dp[i][p]%mod;
        }
        
    }
    /*cout<<"\n the dp table is \n";
    Forall(i,0,arr.size())
    {
        Forall(j,1,k)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int res=0;
    Forall(i,1,arr.size()-1)
    {
        //cout<<"dp[i][k] is "<<dp[i][k]<<"\n";
        res=(res+dp[i][k])%mod;
    }
    res=res%mod;
    cout<<"\n the number of increasing subsequences of length "<<k<<" is "<<res<<"\n";
    return 0;
}
