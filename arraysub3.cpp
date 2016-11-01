//SPOJ ARRAYSUB USING MULTISET OR MAX HEAP. This required the usage of making a custom comparater function for the multiset
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr;
class Order
{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
            if(a.first!=b.first)
            {
                return a.first>b.first;
            }
            else
            {
                return a.second<b.second;
            }
        }
};


int main()
{
    std::ios::sync_with_stdio(false);
    int n,k,i,j,x;
    cin>>n;
    For(i,0,n)
    {
        cin>>x;
        arr.push_back(x);
    }
    cin>>k;
    k=6;
    multiset<pair<int,int>,Order > heap1;
    For(i,0,k)
    {
        heap1.insert(make_pair(arr[i],i));
    }
    
    For(i,k,n)
    {
        cout<<heap1.begin()->first<<" ";
        auto it1=heap1.find(make_pair(arr[i-k],i-k));
        heap1.erase(it1);
        heap1.insert(make_pair(arr[i],i));
    }
    cout<<heap1.begin()->first<<"\n";
    return 0;   
}
