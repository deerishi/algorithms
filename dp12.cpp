//Geek for geeks Tiles

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> squares;

    

int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,n;
    cin>>n;
    double lim=sqrt(n);
    vector<int> dp(1000,0);

    int m=int(lim+1);
    Forall(i,0,m)
    {
        squares.push_back(i*i);   
        //squaresCheck[i*i]=1;
    }
    dp[1]=1;
    cout<<"sqs are \n";
    Forall(i,0,m)
    {
        cout<<squares[i]<<" , ";
    }
    cout<<"\n";
    bool flag=false;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;s
    Forall(i,3,n)
    {
       dp[i]=INT_MAX;
       for(j=1;j*j<=i;j++)
       {
            dp[i]=min(dp[i],1+dp[i-j*j]);
       }
    }
    cout<<"\n the dp is \n";
    Forall(i,0,n)
    {
        cout<<" i = "<<i<<" and dp is "<<dp[i]<<"\n";
    }
    return 0;
}
