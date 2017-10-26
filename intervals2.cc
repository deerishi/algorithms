#include "bits/stdc++.h"
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
    struct Node{
        int min1,max1;
    };
    unordered_set<int> s1;
    vector<Node> arr{vector<Node>(1000000)};
    vector<int> id{vector<int>(1000000,0)},rank{vector<int>(1000000,0)};
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

        int i;
        for(i=0;i<1000000;i++){
            id[i]=i;
            arr[i].min1=i;
            arr[i].max1=i;
        }

    }
    int findRoot(int p){

        while(p!=id[p]){
            id[p]=id[id[p]];
            p=id[p];
        }
        return p;
    }

     void union1(int p,int q){
        int rp=root(p);
        int rq=root(q);
        if(rp==rq){
            return;
        }
        int min1=min(p,q);min1=min(min1,rp);min1=min(min1,rq);
        int max1=max(p,q);max1=max(max1,rp);max1=max(max1,rq);

        if(rank[rp]>rank[rq]){
            id[rq]=rp;
            arr[rp].min1=min(min1,arr[rp].min1);arr[rp].max1=max(max1,arr[rp].max1);
        }
        else{
            id[rp]=rq;
            arr[rq].min1=min(min1,arr[rq].min1);arr[rq].max1=max(max1,arr[rq].max1);
        }
        if(rank[rp]==rank[rq]) rank[rq]=rank[rq]+1;

     }

    void addNum(int val) {
        if(s1.find(val)!=s1.end()){
            return;
        }
        int r1=findRoot(val);int r2;
        if(s1.find(val+1)!=s1.end()){
            r2=findRoot(val+1);
            if(r1==r2){
                return;
            }
            union1(r2, r1);
        }
        if(s1.find(val-1)!=s1.end()){
            r2=findRoot(val-1);
            if(r1==r2){
                return;
            }
            union1(r1,r2);
        }
    }

    vector<Interval> getIntervals() {
        int i,root;
        vector<Interval> results;
        unordered_set<int> s2;
        for(i=1;i<=s1.size();i++){
            root=findRoot(i);
            if(s2.find(root)==s2.end()){
                results.push_back(Interval(arr[root].min1,arr[root].max1));
            }
        }
        return results;
        }
};

int main(){
    cout<<"hi";
    return 0;
}
