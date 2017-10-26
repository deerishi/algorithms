#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)
vector<vector<int> > arr;
vector<vector<pair<double,double> > > dp;

void printDP(int m,int n){
    int i,j;
    For(i,0,m){
        For(j,0,n){
            cout<<"("<<dp[i][j].first<<","<<dp[i][j].second<<")\t ";
        }
        cout<<"\n";
    }
}



int main(){
    std::ios::sync_with_stdio(false);
    int i,j,k,n,m,x;
    cin>>m>>n;
    For(i,0,m){
        arr.push_back(vector<int>());
        dp.push_back(vector<pair<double,double> >(n+2,make_pair(0,0)));
        For(j,0,n){
            cin>>x;
            arr[i].push_back(x);
        }
    }
     double avg1,avg2;
    For(i,0,m){
        For(j,0,n){
            if(i==0 and j==0){
                dp[i][j].first=arr[i][j];
                dp[i][j].second=1;
            }
            else{
                avg1=0;avg2=0;
                if(i-1 >=0){
                    avg1=(arr[i][j]+(dp[i-1][j].first)*dp[i-1][j].second)/(1+dp[i-1][j].second);
                }
                if(j-1>=0){
                    avg2=(arr[i][j]+(dp[i][j-1].first)*dp[i][j-1].second)/(1+dp[i][j-1].second);
                }
                dp[i][j].first=max(avg1,avg2);
                if(avg1>avg2){
                    dp[i][j].second=dp[i-1][j].second+1;
                }
                else
                {
                     dp[i][j].second=dp[i][j-1].second+1;
                }
            }
        }
    }
    cout<<"MAx AVergage is "<<dp[m-1][n-1].first<<"\n";
    printDP(m,n);
    return 0;

}
