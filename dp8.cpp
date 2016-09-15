//Geek for geeks Minimum Initial Points to Reach Destination

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)



vector<vector<pair<int,int> > > dp;
vector<vector<int> > arr;
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,x,m,n;
    cin>>m>>n;
    For(i,0,m)
    {
        arr.push_back(vector<int>());
        dp.push_back(vector<pair<int,int> (make_pair(INT_MIN,INT_MAX),n));
        For(j,0,n)
        {
            cin>>x;
            arr[i].push_back(x);
        }
    }
    dp[0][0]=make_pair(arr[0][0],arr[0])
}
