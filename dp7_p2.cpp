//Geek for geeks Count total number of N digit numbers such that the difference between sum of even and odd digits is 1
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<vector<ull> > dpOdd,dpEven;
vector<vector<bool> > bEven,bOdd;
ull dp[100][100][100][100];
bool bdp[100][100][100][100];
ull findRes(int oddLeft,int evenLeft,int oddSum,int evenSum,int position)
{
    //cout<<"oddsum is "<<oddSum<<"\n";
    if(bdp[oddLeft][evenLeft][oddSum][evenSum]==true)
    {
        return dp[oddLeft][evenLeft][oddSum][evenSum];
    }
    if(oddLeft==0 and evenLeft==1)
    {
        if(1-(evenSum-oddSum)>=0 and 1-(evenSum-oddSum)<=9)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    if(oddLeft==1 and evenLeft==0)
    {
        if((evenSum-oddSum-1)>=0 and (evenSum-oddSum-1)<=9)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int i,j,k;
    ull res=0;
    if(position%2==1)
    {
        Forall(i,0,9)
        {
            res+=findRes(oddLeft-1,evenLeft,oddSum+i,evenSum,position+1);
        }
    }
    else if(position%2==0)
    {
        Forall(i,0,9)
        {
            res+=findRes(oddLeft,evenLeft-1,oddSum,evenSum+i,position+1);
        }
    }
    //cout<<"res is "<<res<<" position = "<<position<<" for oddSum = "<<oddSum<<" for oddLeft = "<<oddLeft<<" and evensum = "<<evenSum<<" for evenLeft = "<<evenLeft<<"\n";
    bdp[oddLeft][evenLeft][oddSum][evenSum]=true;
    return dp[oddLeft][evenLeft][oddSum][evenSum]=res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,n,m;
    cin>>n;
    ull res=0;
    /*Forall(i,0,n)
    {
        dpOdd.push_back(vector<ull>(n*9+1,0));  
        dpEven.push_back(vector<ull>(n*9+1,0)); 
        bOdd.push_back(vector<bool>(n*9+1,false));
        bEven.push_back(vector<bool>(n*9+1,false));
    }*/
    memset(dp,-1,sizeof(dp));
    int numEven=(n%2==0)?(n/2):((n+1)/2);
    int numOdd=(n%2==0)?((n/2)):((n-1)/2);
    Forall(i,1,9)
    {
        res+=findRes(numOdd,numEven-1,0,i,1);  
    }
    /*cout<<"dpOdd array is \n";
    For(i,0,n)
    {
        For(j,0,n*9)
        {
            cout<<dpOdd[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\ndpEven array is \n";
    For(i,0,n)
    {
        For(j,0,n*9)
        {
            cout<<dpEven[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<"the final answer is "<<res<<"\n";
}
