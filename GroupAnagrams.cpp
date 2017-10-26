//Geek for geeks group amagrams
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int dp[100][100];
bool cmp(pair<string,int> a,pair<string,int> b){
    string s1=a.first,s2=b.first;
    //cout<<"before s1 is "<<s1<<" s2 is "<<s2<<"\n";
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    //cout<<"s1 is "<<s1<<" s2 is "<<s2<<"\n";
    int x=s1.compare(s2);
    if(x<0) return true;
    
    return false;
    
}
vector<pair<string,int> > arr;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j;
    string str;
    For(i,0,n){
        cin>>str;
        arr.push_back(make_pair(str,i));
    }
    sort(arr.begin(),arr.end(),cmp);
    for(auto it=arr.begin();it!=arr.end();it++){
        cout<<it->first<<",";
    }
    cout<<"\n";
    return 0;
}
