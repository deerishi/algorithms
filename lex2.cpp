#include "bits/stdc++.h"
using namespace std;

int values[10]={2,3,4,3,4,5,4,3,5,3};
int dp[10][10];
unordered_map<int,vector<int> > legal_values;

int grid[4][3];
int count1=0;
int find_res(int N,int i)
{
    if(N==0)
    {
        return 1;
    }
    if(N==1)
    {
        return dp[N][i];
    }
    else if(dp[N][i]!=-1)
    {   
        count1++;
        return dp[N][i];
    }
    int res=0;
    vector<int>:: iterator it;
    for(it=legal_values[i].begin();it!=legal_values[i].end();it++)
    {
        res+=find_res(N-1,*it);
    }
    
    dp[N][i]=res;
    return res;
    
}

void insert_legal_values()
{
   legal_values[0].push_back(0);
   legal_values[0].push_back(8);
   
   legal_values[1].push_back(1);
   legal_values[1].push_back(2);
   legal_values[1].push_back(4);
   
   legal_values[2].push_back(1);
   legal_values[2].push_back(3);
   legal_values[2].push_back(2);
   legal_values[2].push_back(5);
   
   legal_values[3].push_back(3);
   legal_values[3].push_back(2);
   legal_values[3].push_back(6);
   
   legal_values[4].push_back(4);
   legal_values[4].push_back(5);
   legal_values[4].push_back(1);
   legal_values[4].push_back(7);
   
   legal_values[5].push_back(6);
   legal_values[5].push_back(2);
   legal_values[5].push_back(8);
   legal_values[5].push_back(4);
   legal_values[5].push_back(5);
   
   legal_values[6].push_back(6);
   legal_values[6].push_back(9);
   legal_values[6].push_back(5);
   legal_values[6].push_back(3);
   
   legal_values[7].push_back(7);
   legal_values[7].push_back(8);
   legal_values[7].push_back(4);
   
   legal_values[8].push_back(8);
   legal_values[8].push_back(9);
   legal_values[8].push_back(5);
   legal_values[8].push_back(0);
   legal_values[8].push_back(7);
   
   legal_values[9].push_back(6);
   legal_values[9].push_back(9);
   legal_values[9].push_back(8);
   
   
   
}
int main()
{
    int i,j;
    for(i=0;i<=9;i++)
    {
        dp[1][i]=values[i];
    }
    for(i=2;i<=9;i++)
    {
        for(j=0;j<=9;j++)
        {
            dp[i][j]=-1;
        }
    }
   
    insert_legal_values();
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    int t,n;
    cin>>t;
    int res=0;
    while(t--)
    {
        cin>>n;
        res=0;
        count1=0;
        for(i=0;i<=9;i++)
        {
            res+=find_res(n-1,i);
        }
        cout<<"res is "<<res<<" with count1 ="<<count1<<"\n";
        for(i=2;i<=9;i++)
    {
        for(j=0;j<=9;j++)
        {
            dp[i][j]=-1;
        }
    }
    }
    //now we have the lexographiclaly sorted string in thelist
    return 0;
}
