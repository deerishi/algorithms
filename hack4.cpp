#include "bits/stdc++.h"
#define For(i,start,end) for(i=start;i<end;i++)
using namespace std;

void print1(vector<int> arr,vector<int> arr2){
    int i;
    For(i,0,arr.size()){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
     For(i,0,arr.size()){
        cout<<arr2[i]<<"\t";
    }

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio(false);
    int n,i,j,k,x;
    cin>>n;
    vector<int> arr,arr2;
    For(i,0,n){
        cin>>x;
        arr.push_back(x);
    }
    int res=1;
    arr2.push_back(1);
    For(i,1,n){
        if(arr[i]>arr[i-1]){

            arr2.push_back(1+arr2[i-1]);

        }
        else{
            arr2.push_back(1);
        }
        res+=arr2[i];
    }
    for(i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1] and arr2[i]<=arr2[i+1]){
            arr2[i]++;
            res++;
        }
    }
    //print1(arr,arr2);
    cout<<res<<"\n";
    return 0;
}
