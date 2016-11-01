#include "bits/stdc++.h"
using namespace std;
//SPOJ DATING RISHI
typedef unsigned long long int ll;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<ll> arr;

ll findMax(int start,int end1)
{
    int i,j;
    //cout<<"in "<<start<<","<<end1<<"\n";    
    if(end1==start+1)
    {
        return min(arr[start],arr[end1]);
    }
    ll res=0,temp;
    for(i=start,j=end1;i<j;)
    {
        if(arr[i]!=arr[j])
        {
            res=max(res,(j-i)*min(arr[i],arr[j]));
            if(arr[i]<arr[j]) i++;
            else j--;
        }
        else
        {
            temp=max(findMax(i+1,j),findMax(i,j-1));
            res=max(res,temp);
            res=max(res,(j-i)*arr[i]);
            break;
        }
    }
    return res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,i,j,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        arr.clear();
        For(i,0,n)
        {
            cin>>x;
            arr.push_back(x);
        }
        cout<<findMax(0,n-1)<<"\n";
    }
}
