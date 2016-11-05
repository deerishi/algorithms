#include "bits/stdc++.h"
#define For(i,start,end) for(i=start;i<end;i++)
using namespace std;

int findRes(){
    multiset<int> heap1;
    int x,i,j,k,n;
    cin>>n>>k;
    vector<int> arr;
    For(i,0,n){
        cin>>x;
        arr.push_back(x);
    }
    For(i,0,k){
        heap1.insert(arr[i]);
    }
    auto it=heap1.begin();
    int med1;
    med1=(k%2==1)?(*(it+(k/2))):((*(it+k/2))+ (*(it+k/2 -1 ))/2);
    int res=0;
    For(i,k,n){
        if(arr[i]>2*med1){
               res++;
        }
        heap1.remove(arr[i-k]);
        heap.insert(arr[i]);
        it=heap1.begin();
        med1=(k%2==1)?(*(it+(k/2))):((*(it+k/2)+*(it+k/2 -1 ))/2);
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios::sync_with_stdio(false);
    int res=findRes();
    cout<<res<<"\n";
    return 0;
}

