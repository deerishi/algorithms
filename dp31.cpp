//Geek for geeks mX PRODUCT CUTTING
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

bool checkCondition(ull max1,ull min1){
    if(2*min1>max1) return true;
    return false;
}
vector<int> dp(1000,-1);
int findRes(int x){
    int i;
    if(dp[x]!=-1) return dp[x];
    if(x==2 or x==1) return 1;
    int res=0,temp1,temp2;
    For(i,1,x){
        vector<int> v1;
        //temp1=findRes(i);
        temp2=findRes(x-i);
        v1.push_back(i*temp2);v1.push_back(i*(x-i));
        res=max(res,*max_element(v1.begin(),v1.end()));
    }
    return dp[x]=res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,t,n,start1,end1,maxsize=0;
    while(1){
        cin>>n;
        if(cin.eof()) break;
        For(i,0,n+2) {
            dp[i]=-1;
        }
        cout<<"the answer for "<<n<<" is "<<findRes(n)<<"\n";
    }
    
    
    return 0;
}
