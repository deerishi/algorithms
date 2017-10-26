#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
bool cmp(pair<int,int> a,pair<int,int> b){
    //return double(a.first)/double(a.second) >  double(b.first)/double(b.second) ;
    if(a.second==b.second){
        return a.first>b.first;
    }
    return a.second<b.second;
}
void print(vector<pair<int,int> > arr){
    for(auto  it=arr.begin();it!=arr.end();it++){
        cout<<it->first<<","<<it->second<<"\n";
    }
}

class Order{
  public:
    bool operator()(pair<int,int>a,pair<int,int> b){
        return a.first>b.first;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    int i,j,x,n,y;
    cin>>n;
    vector<pair<int,int> > arr;
    For(i,0,n){
        cin>>x>>y;
        arr.push_back(make_pair(x,y));
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,Order> queue1;

    sort(arr.begin(),arr.end(),cmp);
    int res=0,count=0,min1=INT_MAX;
    For(i,0,arr.size()){
        if(count<arr[i].second){
            count++;
            res+=arr[i].first;
            queue1.push(arr[i]);
        }
        else if(count==arr[i].second){
            pair<int,int> t1=queue1.top();
            if(res-t1.first+arr[i].first>res){
                res=res-t1.first+arr[i].first;
                queue1.pop();
                queue1.push(arr[i]);
            }
            }

        }

    //print(arr);
    cout<<res<<"\n";
    return 0;
}
