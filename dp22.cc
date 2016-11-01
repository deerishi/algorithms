
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<int> arr,arr2;
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,n,x;
    cin>>n;
    int countZeros=0;
    For(i,0,n)
    {
        cin>>x;
        (x==0)?countZeros++:x;
        (x==0)?(arr2.push_back(-1)):(arr2.push_back(1));
        arr.push_back(x);
    }
    int maxSoFar=arr2[0],m=0,n=0;
    int curSum=arr2[0];
    For(i,1,n)
    {

        if(arr[i]>0 and curSum<0)
        {
            m=i;n=i;
            curSum=arr[i];
        }
        else if(arr[i]<0 and curSum+arr[i])
    }
    
    
}
