#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
string str;
int dp[100][100];

int lrs(int i,int j)
{
    if(i<=0 or j<=0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(str[i-1]==str[j-1])
    {
        dp[i][j]=1+lrs(i-1,j-1);
        return dp[i][j];
    }
    else
    {
        if(i>j)
        {
            dp[i][j]=max(lrs(i,j-1),lrs(i-1,j-1));
            return dp[i][j];
        }
        else
        {
            dp[i][j]=max(lrs(i-1,j),lrs(i-1,j-1));
            return dp[i][j];
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int i,j;
    while(t--)
    {
        cin>>str;
        for(i=0;i<=str.length();i++)
        {
            for(j=0;j<=str.length();j++)
            {
                dp[i][j]=-1;
            }
        }
        cout<<max(lrs(str.length(),str.length()-1),lrs(str.length()-1,str.length()))<<"\n";
    }
    return 0;
}
