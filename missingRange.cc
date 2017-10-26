#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)

int main(){
    std::ios::sync_with_stdio(false);
    int i,j,k,x;
    vector<int> nums;
    while(1){
        cin>>x;
        if(cin.fail()){
            break;
        }
        nums.push_back(x);
    }
    vector<string> results;
    int start,end1;
    start=nums[0];
    For(i,1,nums.size()){
        if(nums[i]==start+1){
            start=nums[i];
        }
        else{
            string temp;
            end1=nums[i];
            if(start+1==end1-1){
                temp=to_string(start+1);
            }
            else{
                temp=to_string(start+1)+"->"+to_string(end1-1);

            }
            results.push_back(temp);
            start=nums[i];
        }
    }
    if(start!=99){
            string temp;
            end1=99;
            if(start+1==end1){
                temp=to_string(start+1);
            }
            else{
                temp=to_string(start+1)+"->"+to_string(end1);

            }
            results.push_back(temp);
    }
    cout<<"the result is \n";
    for(auto s : results){
        cout<<s<<" , ";
    }
    cout<<"\n";
    return 0;

}
