#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout)
#define For(i,start,end) for(i=start;i<end;i++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
int segtree[4000004],arr[1000001];
int build(int start,int end,int position)
{
    if(start==end)
    {
        segtree[position]=arr[start];
         //cout<<"("<<start<<","<<end<<")"<<
        return arr[start];
    }
    int mid=(start+end)/2;
    int left=build(start,mid,2*position);
    int right=build(mid+1,end,2*position+1);
    segtree[position]=max(left,right);
    
    //cout<<"("<<start<<","<<end<<")"<<" left = "<<left<<" right="<<right<<" and "<<segtree[position]<<"\n";
    return segtree[position];
}
int query(int start,int end,int qstart,int qend,int position)
{
    if(qstart<=start and qend>=end)
    {
        return segtree[position];
    }
    else if(end<qstart or qend<start)
    {
        return -1;   
    }
    else
    {
        int mid=(start+end)/2;
        int p1=query(start,mid,qstart,qend,2*position);
        int p2=query(mid+1,end,qstart,qend,2*position+1);
        if(p1==-1)
        {
            return p2;   
        }
        else if(p2==-1)
        {
            return p1;
        }
        else
        {
            return max(p1,p2);
        }   
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,x;

    cin>>n;
    int i,j,k;
    Forall(i,1,n)
    {
        cin>>x;
        arr[i]=x;
    }
    cin>>k;
    deque<pair<int,int> > q1;
    vector<int> res;
    int temp=build(1,n,1);
    Forall(i,1,n-k+1)
    {
        res.push_back(query(1,n,i,i+k-1,1));
    }
    for(auto it=res.begin();it!=res.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
    return 0;
}
