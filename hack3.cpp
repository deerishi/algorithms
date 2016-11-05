#include "bits/stdc++.h"
#define For(i,start,end) for(i=start;i<end;i++)
using namespace std;


class Order1{
    public:
        bool operator()(double a,double b){
            return a<b;
        }
};
class Order2{
    public:
        bool operator()(double a,double b){
            return a>b;
        }
};
multiset<double,Order1> minHeap;
multiset<double,Order2> maxHeap;
unordered_map<double,int> map1;//To store which element is in which heap
void printHeaps(){
    cout<<"the maxheap is \n";
    for(auto it=maxHeap.begin();it!=maxHeap.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    cout<<"the minheap is \n";
    for(auto it=minHeap.begin();it!=minHeap.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
}
void balanceHeaps(){
    //cout<<"\n in balancing";    
    int s1=maxHeap.size();
    int s2=minHeap.size();
    if(s1-s2>=2){
        double top=*(maxHeap.begin());
        maxHeap.erase(maxHeap.begin());
        minHeap.insert(top);
        map1[top]=2;
    }
    else if(s2-s1>=2){
        double top=*(minHeap.begin());
        minHeap.erase(minHeap.begin());
        maxHeap.insert(top);
        map1[top]=1;//for maxHeap
    }
}
void insert(double val){
    //cout<<"in insert "<<val<<" s1 "<<maxHeap.size()<<" s2 "<<minHeap.size()<<"\n";
    if(maxHeap.empty() and minHeap.empty()){
        maxHeap.insert(val);
        return;
    }
    if(maxHeap.empty() and !minHeap.empty()){
        if(val>*(minHeap.begin())){
            minHeap.insert(val);
        }
        else{
            maxHeap.insert(val);
        }
    }
    else if(!maxHeap.empty() and minHeap.empty()){
        if(val<=*(maxHeap.begin())){
            maxHeap.insert(val);
        }
        else{
            minHeap.insert(val);
        }
    }
        
    else{
        if(val<=*(maxHeap.begin())){
            maxHeap.insert(val);
        }
        else{
            minHeap.insert(val);
        }
    }
    balanceHeaps();
}
void remove(double val){
    if(maxHeap.find(val)!=maxHeap.end()){
        maxHeap.erase(maxHeap.find(val));
    }
    else{
        minHeap.erase(minHeap.find(val));
    }
    balanceHeaps();
}
double getMedian(){
    if(maxHeap.size()==minHeap.size()){
        double t1=*(maxHeap.begin());
        double t2=*(minHeap.begin());
        return (t1+t2)/2;
    }
    else if(maxHeap.size()>minHeap.size()){
        return *(maxHeap.begin());
    }
    else{
        return *(minHeap.begin());
    }
    
}
int findRes(){
   
    int i,j,k,n,d;
    cin>>n>>d;
    //cout<<"d is "<<d<<"\n";
    double x,med1;
    vector<double> arr;
    For(i,0,n){
        cin>>x;
        arr.push_back(x);
    }
    For(i,0,d){
        insert(arr[i]);
    }

    int res=0;
    For(i,d,n){
        //cout<<"the heaps are \n";
        //printHeaps();
        med1=getMedian();
        //cout<<"median is "<<med1<<"\n";
        if(arr[i]>=2*med1){
            res++;
        }
        remove(arr[i-d]);
        insert(arr[i]);
        
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

