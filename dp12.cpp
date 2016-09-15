//Geek for geeks Tiles

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> squares;
int bsearch(int n,int start,int end)
{
    int mid=(start+end)/2;
    if(squares[mid]<n and squares[mid+1]>n)
    {
        return mid;
    }    
    if(squares[mid]<n and squares[mid+1]<n)
    {
        return bsearch(n,mid+1,end);
    }
    else
    {
        return bsearch(n,start,mid);
    }
    
    
    
}
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
    for(i=1;i<=squares.size()-1 and flag==false;i++)
    {
        dp[squares[i]]=1;
        For(j,squares[i]+1,squares[i+1])
        {
            dp[j]=1+dp[j-squares[i]];
            if(j==n)
            {
                flag=true;
            }   
        }
    }
    cout<<"\n the dp is \n";
    Forall(i,0,n)
    {
        cout<<" i = "<<i<<" and dp is "<<dp[i]<<"\n";
    }
    return 0;
}
