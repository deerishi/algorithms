//Geek for geeks palindrome partioning
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int dp[100][100];
string str;
int counter;
bool checkPalindrome(int start,int end1)
{
    int i,j;
    //cout<<"str is "<<str<<" , "<<str.length()<<"\n";    
    for(i=start,j=end1;i<=j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
    }
    return true;
}

int findMin(int start,int end1)
{
    //cout<<"in "<<start<<","<<end1<<"\n";
    if(dp[start][end1]!=-1)
    {
        counter++;
        return dp[start][end1];
    }
    int i,j;
    if(checkPalindrome(start,end1)) return dp[start][end1]=0;
    
    int minCuts=str.length()-1;
    For(i,start+1,end1)
    {
        minCuts=min(minCuts,1+findMin(start,i)+findMin(i,end1));
    }
    //cout<<"finished "<<start<<","<<end1<<" counter is "<<counter<<"\n";
    return dp[start][end1]=minCuts;
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(1){
    
        cin>>str;
        if(cin.eof()) break;
        memset(dp,-1,sizeof(dp)); 
        counter=0;
        int res=findMin(0,str.length()-1);
        cout<<"min cuts required are "<<res<<"\n";
        //cout<<"\n\n\n-------------------------------------------------------------------------------\n\n\n";
    }    
    return 0;
}
