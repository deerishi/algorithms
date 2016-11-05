#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)

bool findRes(int index,vector<int>& nums,vector<bool>& visited){
    //cout<<"index is "<<index<<" and index >= nums.size()-1 "<<(index >= nums.size()-1)<<"\n";
    if(index >= nums.size()-1){
        return true;
    }
    int i,j,k;
    visited[index]=true;
    if(nums[index]==0) {
        return false;
    }
    bool res=false;
    for(i=index+1;i<=index+nums[index];i++){
        if(!visited[i])
        res=res|findRes(i,nums,visited);
        
        if(res){
            return res;
        }
    }
    return res;
}
bool canJump(vector<int>& nums) {
    int i,j,k;
    if(nums.size()==1){
        return true;
    }
    bool res=false;
    vector<bool> visited(nums.size(),false);
    visited[0]=true;
    for(j=1;j<=nums[0] and j<nums.size();j++){
        if(!visited[j])
            res=res|findRes(j,nums,visited);
        
        if(res){
            return res;
        }
    }
    return res;
    
}
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,k,n,x;
    vector<int> arr;
    while(1){
        cin>>x;
        if(cin.eof()) break;
        arr.push_back(x);
    }
    bool res=canJump(arr);
    cout<<"res is "<<res<<"\n";
    
}
