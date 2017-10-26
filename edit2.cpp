#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
string str1,str2;
int dp[100][100];
int findRes(int i,int j){
    if(i<0 or j<0){
        return max(max(i,j),0);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res;
    if(str1[i]==str2[j]){
        return dp[i][j]=findRes(i-1,j-1);
    }
    int temp=min(findRes(i-1,j)+1,findRes(i,j-1)+1);
    return dp[i][j]=min(temp,findRes(i-1,j-1)+1);
}
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,n;
    memset(dp,-1,sizeof(dp));
    cin>>str1>>str2;
    int res=findRes(str1.length()-1,str2.length()-1);
    cout<<"res is "<<res<<"\n";
    return 0;
}
