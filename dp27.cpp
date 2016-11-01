//Geek for geeks maximize i*arr[i]

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr;
int V=0,sum=0;
void getFirst()
{
    int i,n=arr.size();
    For(i,0,n)
    {
        V+=arr[i]*i;
        sum+=arr[i];
    }
}

int getRes()
{
    getFirst();
    int i,j,tempSum,res=INT_MIN,tempV=V,curSum,n=arr.size()-1;
    For(i,0,n)
    {
        tempSum=sum;
        curSum=arr[i]*n -(sum-arr[i]) + tempV;
        tempV=curSum;
        res=max(res,curSum);
        cout<<"curSum is "<<curSum<<"\n";
        
    }
    return res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,t,n,x;
    cin>>n;
    For(i,0,n)
    {
        cin>>x;
        arr.push_back(x);
    }
    cout<<"the max value is "<<getRes()<<"\n";
    return 0;
}
