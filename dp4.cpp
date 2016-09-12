//Geek for geeks Count even length binary sequences with same sum of first and second half bits
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

int main()
{
    std::ios::sync_with_stdio(false);
    int n,i,j,k;
    cin>>n;
    //calcualte sum(nCk^2), 0<=k<=n
    int res1=1,res2=1;
    Forall(i,1,n)
    {
        res1=res1*(n-i+1)/i;
        res2+=res1*res1;
    }
    cout<<"the result is "<<res2<<"\n";
    return 0;
    
}
