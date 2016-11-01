//Geek for geeks 
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

bool allSame1(int numA,int numB,int numC,string &str)
{
    int n=str.length();
    if(numA==n or numB==n or numC==n) return true;
    
    return false;
}


int findSmallestLengthAfterReduction(string &str)
{
    int numA=0,numB=0,numC=0;
    int i;
    For(i,0,str.length())
    {
        if(str[i]=='a') numA++;
        else if(str[i]=='b') numB++;
        else numC++;
    }
    if(allSame1(numA, numB,numC,str ) ) return str.length();
    else if(numA>0 and numB>0 and numC>0)
    {
        if((numA%2==0 and numB%2==0 and numC%2==0) or (numA%2==1 and numB%2==1 and numC%2==1)) return 2;
        else return 1;
    }
    
        if(numA==0)
        {
            if(numB%2==0 and numC%2==0 ) return 2;
            return 1;            
        }
         if(numB==0)
        {
            if(numA%2==0 and numC%2==0) return 2;
            return 1;            
        }
      
            if(numB%2==0 and numA%2==0) return 2;
            return 1;            
        
    
    
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        cout<<findSmallestLengthAfterReduction(str)<<"\n";
    }
    return 0;
}
