#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr;
int main(){
    std::ios::sync_with_stdio(false);
    int x,n,i,j;
    while(1){
        cin>>x;
        if(cin.fail()){
            break;
        }
        arr.push_back(x);
    }
    n=arr.size();
    //sort(arr.begin(),arr.end());
    int res=0,sumSoFar=0;
    For(i,0,n){
        res+=i*arr[i] - sumSoFar;
        sumSoFar+=arr[i];
    }
    cout<<"res is "<<res<<"\n";
    return 0;

}
