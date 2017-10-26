
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
void printA(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    std::ios::sync_with_stdio(false);
    int j,k,x,n;
    vector<int> A;
    int max1=INT_MIN,min1=INT_MAX;
    while(1){
        cin>>x;
        if(cin.fail()){
            break;
        }
        if(x>max1){
            max1=x;
        }
        if(x<min1){
            min1=x;
        }
        A.push_back(x);
    }
    n=A.size();
     for(int i=0; i<n; i++)
        A[i]-= min1;
    int newMax = max1-min1+1;
    cout<<"After making everything +ve A is \n";
    printA(A);
    //Save original negative values into new positions
    int currNegativeIndex = 0;
    for(int i=0; i<n; i++){
        if(A[i]%newMax < (-min1))
            A[currNegativeIndex++] += (A[i]%newMax)*newMax;
    }
    cout<<"After saving the original -ve values into new positions A is \n";
    printA(A);
    //Save original positive values into new positions
    int currPositiveIndex = currNegativeIndex;
    for(int i=0; i<n; i++)
        if(A[i]%newMax > (-min1))
            A[currPositiveIndex++] += (A[i]%newMax)*newMax;
    cout<<"After saving the original positive values into new positions\n";
    printA(A);
    //Recover to original value
    for(int i=0; i<n; i++){
        A[i] = A[i]/newMax + min1;
    }
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    return 0;

}
