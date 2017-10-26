
//Geek for geeks maximize i*arr[i]

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
string str;
int end1;
vector<int> dp(200,-1);
int count=0;
int findRes(int start)
{
    int i,j,t,num=0,res=0;
    //cout<<"start is "<<start<<" end1 is "<<end1+1<<"\n";
    if(dp[start]!=-1){ count++;return dp[start]; }
    if(start>=end1 ) return dp[start]=1;


    res+=findRes(start+1);
    num=(str[start]-'0')*10+str[start+1]-'0';
    if(num>0 and num<27)
    {
        res+=findRes(start+2);
    }

    return dp[start]=res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,t,n,x;

    cin>>str;
    end1=str.length()-1;
    cout<<"the result is "<<findRes(0)<<"\n";
    return 0;
}
