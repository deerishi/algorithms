#include "bits/stdc++.h"
using namespace std;
//geek for geeks 
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

bool canJump(vector<int> &nums){
    int i,j,k;
    int max1=0;
    for(i=0;i<nums.size();i++){
        if(i+arr[i]>max1){
            max1=i+arr[i];
        }
        if(max1==i){
            if(nums.size()==1){
                return true;
            }
            return false;
        }
        if(max1 >= nums.size()-1){
            return true;
        }
    }
    return false;
}

int main(){
    std::ios::sync_with_stdio(false);
    int i,j,k,x;
    vector<int> arr;
    while(1){
        cin>>x;
        if(cin.fail()){
            break;
        }
        arr.push_back(x);
    }
    bool
}
