//Geek for geeks Find number of solutions of a linear equation of n variables
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int dp[100][100];
int findRes(int arr[],int start,int n,int rhs)
{
   int i,j,k;
   if(dp[start][rhs]!=-1)
   {
        return dp[start][rhs];
   }
   if(start==n and rhs==0)
   {
        return 1;
   }
   else if(start==n and rhs!=0)
   {
        return 0;
   }
   int res=0;
   for(i=0;arr[start]*i<=rhs;i++)
   {
        res+=findRes(arr,start+1,n,rhs-arr[start]*i);
   }
   
   return dp[start][rhs]=res; 
}


int main()
{
    std::ios::sync_with_stdio(false);
    int n,i,j;
    cin>>n;
    int arr[n];
    int coeff;
    For(i,0,n)
    {
        cin>>arr[i];
    }
    int rhs;
    cin>>rhs;
    Forall(i,0,n)
    {
        Forall(j,0,rhs)
        {
            dp[i][j]=-1;
        }
    }
    cout<<"number of solutions of a linear equation of "<<n<<" variables is "<<findRes(arr,0,n,rhs)<<"\n";
    return 0;
}

