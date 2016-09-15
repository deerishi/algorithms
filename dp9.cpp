//Geek for geeks Minimum Initial Points to Reach Destination

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<vector<ull> > dp;

ull findRes(int lastDigit,int remainingDigits)
{
    int i,j,k;
    if(dp[lastDigit][remainingDigits]!=0)
    {
        return dp[lastDigit][remainingDigits];
    }
    if(remainingDigits==1)
    {
        return 10-lastDigit;
    }   
    ull res=0;
    Forall(i,lastDigit,9)
    {
        ull tmp=findRes(i,remainingDigits-1);
        res+=tmp;
         //cout<<"Lastdigit is "<<i<<" and remainingDigits are "<<remainingDigits<<" tmp is "<<tmp<<"\n";
    }
   
    return dp[lastDigit][remainingDigits]=res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,m,n;
    cin>>n;
    Forall(i,0,9)
    {
        dp.push_back(vector<ull>(n+1,0));
    }
    cout<<"the result is "<<findRes(0,n)<<"\n";
    return 0;
}
