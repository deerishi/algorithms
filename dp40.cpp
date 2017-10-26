#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)

vector<int> arr;
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,k,x;
    while(1){
        cin>>x;
        if(cin.fail()){
            break;
        }
        arr.push_back(x);
    }
    int sumSoFar=0,start=0,end1=0,min1=INT_MAX;
    i=0;j=0;
    int n=arr.size();
    cout<<"n is "<<n<<"\n";
    while(i<=j and j<n){
        cout<<"sumSofar is "<<sumSoFar<<"\n";
        if(arr[j]%n==0){
            min1=1;
            start=j;end1=j;j++;i=j;sumSoFar=0;
        }
        else if(sumSoFar<n){
            sumSoFar+=arr[j];j++;
        }
        else if(sumSoFar%n==0){
            if(min1>j-i){
                min1=j-i;
                start=i;end1=j-1;
            }
            sumSoFar-=arr[i];i++;
            sumSoFar+=arr[j];
            j++;
        }
        else if(sumSoFar>n ){
            //increanment so that current window size is one less than the previous window
            cout<<"hi\n";
            if(((sumSoFar-arr[i])%n) < (sumSoFar%n)){
                sumSoFar-=arr[i];
                i++;

            }else{
                sumSoFar+=arr[j];j++;
            }
        }

        if(j==n){
             if(sumSoFar%n==0){
            if(min1>j-i){
                min1=j-i;
                start=i;end1=j-1;
            }
        }
        }
    }
    cout<<"The values we can find are \n";
    For(i,start,end1+1){
        cout<<arr[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
