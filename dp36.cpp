#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

int findRes(vector<int> &prices ){
    stack<int> s1;
    int maxDiff=0,bottom,diff;
    int i=0;
    while(i<prices.size()){
        if(s1.empty()){
            s1.push(prices[i]);
            bottom=prices[i];
        }
        else if(s1.top()<=prices[i]){
            s1.push(prices[i]);
        }
        else{
            diff=s1.top()-bottom;
            if(maxDiff<diff){
                maxDiff=diff;
            }
            while(!s1.empty() and s1.top()>prices[i]){
                s1.pop();
            }
            if(s1.empty()) bottom=prices[i];
            s1.push(prices[i]);

        }
        i++;
    }
    if(s1.size()>1){
        diff=s1.top()-bottom;
        if(maxDiff<diff){
            maxDiff=diff;
        }

    }
    return maxDiff;
}
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,k,n,x;
    vector<int> prices;
    while(1){
        cin>>x;
        if(cin.fail()){
            break;
        }
        prices.push_back(x);
    }
    int res=findRes(prices);
    cout<<"the result is "<<res<<"\n";
}
