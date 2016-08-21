#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
#define For(i,start,end) for(i=start;i<end;i++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
//int dp[501][10001];
int findRes(int N,vector<pair<int,int> >& coins,int weight)
{
    vector<int> dp[501];
    int i,j,k;
    //Initialization of DP
    Forall(i,0,weight)
    {
        if(i==0)
        {
            dp[0].push_back(0);
        }
        else
        {
            dp[0].push_back(-1); //Here -1 signifies that it is impossible to achive this configration
        }
        
    }
    Forall(i,0,N)
    { 
     
     dp[i].push_back(0);
        
    }
    
    //Initialization Over
    Forall(i,1,N)
    {
        Forall(j,1,weight)
        {
            if(coins[i-1].second>j)
            {
                dp[i].push_back(dp[i-1][j]);
            }
            else
            {
                int minVal=INT_MAX;
                for(k=0;k*coins[i-1].second<=j;k++)
                {
                    //temp2=k*
                    if(dp[i-1][j-(k*coins[i-1].second)]==-1)
                    {
                        continue;
                    }
                    else
                    {
                        minVal=min(minVal,k*coins[i-1].first+dp[i-1][j-(k*coins[i-1].second)]);
                    }
                }
                if(minVal==INT_MAX)
                {
                    dp[i].push_back(-1); //Meaning that it is impossible
                }
                else
                {
                    dp[i].push_back(minVal);
                }
            }
        }
    }
    //cout<<"dp[0] length is "<<dp[0].size()<<"\n";
    /*Forall(i,0,N)
    {
        Forall(j,0,weight)
        {
            cout<<dp[i][j]<<" "; 
        }
        cout<<"\n";
    }*/
    return dp[N][weight];
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T,N,P,E,W,i,j,x,y,res;
    cin>>T;
    while(T--)
    {
        cin>>E>>W;
        cin>>N;
        vector<pair<int,int> > coins;
        For(i,0,N)
        {
            cin>>x>>y;
            coins.push_back(make_pair(x,y));
        }
        res=findRes(N,coins,W-E);
         if(res==-1)
        {
            cout<<"This is impossible.\n";
        }
        else
        {
            cout<<"The minimum amount of money in the piggy-bank is "<<res<<".\n";
        }
    }
    return 0;
}
