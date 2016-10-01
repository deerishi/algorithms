#include "bits/stdc++.h"
using namespace std;
//geek for geeks Count of n digit numbers whose sum1 of digits equals to given sum1
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<vector<unsigned long long int> > dp;
unsigned long long int counter=0;
unsigned long long int findRes(long long int digits,long long int sum1)
{
    if(sum1<0)
    {
        return 0;
    }
    if(digits==1 or dp[digits][sum1]!=-1)
    {   
        counter++;
        return dp[digits][sum1];
    }
    unsigned long long int i,j,res=0;
    Forall(i,0,9)
    {
        res+=findRes(digits-1,sum1-i);
    }
    return dp[digits][sum1]=res;
}
int main()
{
    std::ios::sync_with_stdio(false);
     unsigned long long int i,j,k,n,sum1;
    cin>>n>>sum1;
    //cout<<"sum1="<<sum1<<"\n";
    Forall(i,0,n)
    {
        if(i==1)
            dp.push_back(vector<unsigned long long int>(sum1+1,0));
        else
        {
            dp.push_back(vector<unsigned long long int>(sum1+1,-1));
        }
    }
   //cout<<"hi\n";
    Forall(i,0,9)
    {
        dp[1][i]=1;
    }
    unsigned long long int res=0;
    Forall(i,1,9)
    {
        res+=findRes(n-1,sum1-i);
    }
    
    cout<<"the result is "<<res<<"\n memoziation was used "<<counter<<" times\n";
    
    return 0;
}
