#include "bits/stdc++.h"
using namespace std;
//geek for geeks 
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)


string str1,str2;
int dp[1001][1001];
int findRes(int end1,int end2)
{
    //cout<<"dp["<<end1<<"]["<<end2<<"] is "<<dp[end1][end2]<<"\n";
    if(dp[end1][end2]!=-1)
    {
        return dp[end1][end2];
    }
    if(end1<1)
    {
        if(end2>=1) return dp[end1][end2]=(end2)*30;
        return dp[end1][end2]=0;
    }
    else if (end2<1)
    {
        if(end1>=1) return dp[end1][end2]=(end1)*15;
        return dp[end1][end2]=0;
    }
    else if(str1[end1-1]==str2[end2-1]) 
    {
        return dp[end1][end2]=findRes(end1-1,end2-1);
    }
    else 
    {
        int res1=min(15+findRes(end1-1,end2),30+findRes(end1,end2-1));
        //int res2=min(res1,45+findRes(end1-1,end2-1));
        return dp[end1][end2]=res1;
    }
}
void printDp(int m,int n)
{
    int i,j;
    For(i,0,m)
    {
        For(j,0,n)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k;
    while(1)
    {
        cin>>str1;
        if(str1[0]=='#') break;
        cin>>str2;
        int m=str1.length()+1;
        int n=str2.length()+1;
        //cout<<"sizeof dp is "<<sizeof(dp)<<" and other is "<<m*n*sizeof(int)<<"\n";
        memset(dp,-1,sizeof(dp));
        //printDp(m,n);
        cout<<findRes(str1.length(),str2.length())<<"\n";
    }
    return 0;
}
