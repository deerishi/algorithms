//SPOJ MINCACHE
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

class Order
{
    public:
        bool operator()(int a,int b)
        {
            return a<b;
        }
};
priority_queue<int,vector<int>,Order> minQueue;
vector<int> arr;
unordered_map<int,bool> map1;
int main()
{
    std::ios::sync_with_stdio(false);
    int x,i,j,k,size,n;
    cin>>size>>n;
    For(i,0,n)
    {
        cin>>x;
        arr.push_back(x);
    }
    int faults=0,top;
    For(i,0,n)
    {
        //cout<<"at "<<arr[i]<<"\n";
        if(map1.find(arr[i])==map1.end())
        {
            
            if(minQueue.size()==size)
            {
                top=minQueue.top();
                //cout<<"top is "<<minQueue.top()<<"\n";
                minQueue.pop();
                map1.erase(top);
                
               
            }
            faults++; 
            map1[arr[i]]=true;
            minQueue.push(arr[i]);
        }
        else
        {
            continue;
        }
    }
    cout<<faults<<"\n";
    return 0;
}
