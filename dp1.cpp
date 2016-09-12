
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int k;
int findMinimumSize(vector<int>& arr)
{
    int i,j;
    cout<<"with arr \n";
    For(i,0,arr.size())
    {
        cout<<arr[i]<<",";        
    }
    cout<<"\n";
    if(arr.size()<3)
    {
        return arr.size();
    }
    
    int res=arr.size(),temp3;vector<int> temp2;
    For(i,2,arr.size())
    {
        temp2.clear();
        if(arr[i-1]-arr[i-2]==k and arr[i]-arr[i-1]==k)
        {
            cout<<"at i="<<i<<"\n";
            For(j,0,i-2)
            {
                cout<<"j="<<j<<" with element "<<arr[j]<<" \n";
                temp2.push_back(arr[j]);
            }
            For(j,i+1,arr.size())
            {   
                //cout<<"i+1 is "<<i+1<<"\n";
                cout<<"2 ,j="<<j<<" with element "<<arr[j]<<" \n";
                temp2.push_back(arr[j]);
            }
            temp3=findMinimumSize(temp2);
            if(temp3<res)
            {
                res=temp3;
            }
        }
    }
    cout<<"returned res="<<res<<"\n";
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int x,n,i,j;
    cin>>n>>k;
    vector<int> arr;
    For(i,0,n)
    {
        cin>>x;
        arr.push_back(x);
    }
    cout<<"the minimum possible size is "<<findMinimumSize(arr)<<"\n";
    return 0;

}
