#include "bits/stdc++.h"
using namespace std;
string str1,str2;
int dp[3001][3001];
int findRes(int i,int j)
{
    //cout<<"("<<i<<","<<j<<")\n";
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i==0 or j==0)
    {
        
        dp[i][j]= max(i,j);
    }
    
    else if(str1[i-1]==str2[j-1])
    {
        dp[i][j]=findRes(i-1,j-1);
        
    }
    else 
    {
        int temp=min(findRes(i-1,j-1),findRes(i-1,j));
        dp[i][j]=1+min(temp,findRes(i,j-1));
    }
    //cout<<"str1["<<i<<"] is "<<str1[i-1]<<" and str2["<<j<<"] is "<<str2[j-1]<<" returning "<<dp[i][j]<<"\n";
    return dp[i][j];
}
int  main()
{
    std::ios::sync_with_stdio(false);
    
    int t,i,j;
    
    cin>>t;
    
    while(t--)
    {
        cin>>str1>>str2;   
        for(i=0;i<=max(str1.length(),str2.length());i++)
        {
            for(j=0;j<=max(str1.length(),str2.length());j++)
            {
                dp[i][j]=-1;   
            }
        }
        cout<<findRes(str1.length(),str2.length())<<"\n";
    }
    return 0;
     
}
