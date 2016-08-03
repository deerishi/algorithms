#include "bits/stdc++.h"
using namespace std;
#include <boost/algorithm/string.hpp>    

char temp[1<<10],ch;
#define For(i,start,end) for(i=start;i<=end;i++)

string str;
struct Node
{
    int rank[2],index;
    string suffix;
}suffixes[1005];
int P[20][1005];
bool cmp(Node a,Node b)
{
    return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]):(a.rank[0]<b.rank[0]);
}
void printSuffix()
{
    int i,j;
    For(i,0,str.length()-1)
    {
        cout<<suffixes[i].index<<"\t"<<suffixes[i].suffix<<"\t\t\t"<<suffixes[i].rank[0]<<"\t"<<suffixes[i].rank[1]<<"\n";
    }
    
    
}
int N;
void printP(int k)
{
    int i,j;
    cout<<"  ";
    for(i=0;i<=k;i++)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    for(i=0;i<=k;i++)
    {
        cout<<i<<" ";
        for(j=0;j<N;j++)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<"\n";
    }
}


bool cmp2(Node a,Node b)
{
    return a.suffix< b.suffix;
}
int findLcp(int x,int y,int k2)
{
    int i,j,step,res=0;
    for(i=k2;i>=0 and x<N and y<N;i--)
    {
        //cout<<"k="<<i<<" P["<<i<<"]["<<x<<"] is "<<P[i][x]<<" and P["<<i<<"]["<<y<<"] is "<<P[i][y]<<"\n";
        if(P[i][x]==P[i][y])
        {
            res+=1<<i;
            x+=1<<i;
            y+=1<<i;
        }
    }
    return res;
}
int  buildSuffixArray()
{
    int i,j,k;
    for(i=0;i<N;i++)
    {
        P[0][i]=str[i]-'a';
        suffixes[i].index=i;
        suffixes[i].suffix=str.substr(i,N-i);
    }
    int k2;
    for(k=1,k2=1;k/2 <N;k*=2,k2++)
    {
        for(i=0;i<N;i++)
        {
            suffixes[i].rank[0]=P[k2-1][suffixes[i].index];
            suffixes[i].rank[1]=(suffixes[i].index+k<N)?(P[k2-1][suffixes[i].index+k]):-1;
        }
    
        //cout<<"Printing suffix before with k="<<k<<"\n";
        //printSuffix();
        
        sort(suffixes,suffixes+N,cmp);  
        //cout<<"Printing suffix after with k="<<k<<"\n";
        //printSuffix();
        int cnt=0;
        for(i=0;i<N;i++)
        {
            if(i==0)
            {
                P[k2][suffixes[i].index]=cnt;
            }
            else
            {
                P[k2][suffixes[i].index]=(suffixes[i].rank[0]==suffixes[i-1].rank[0] and suffixes[i].rank[1]==suffixes[i-1].rank[1])?(cnt):(++cnt); 
                
            }
            //cout<<"P["<<k2<<"]["<<suffixes[i].index<<"] = "<<P[k2][suffixes[i].index]<<"\n";
        }
        
        
    }
    cout<<"Printing suffix final \n";
    printSuffix();
   /* cout<<"Printing P\n";
    printP(k2);
    cout<<"\nChecking for sanity check\n";
    sort(suffixes,suffixes+N,cmp2);
    printSuffix();
    cout<<"Now finding LCP\n";*/
    int res=suffixes[0].suffix.length();
    for(i=1;i<N;i++)
    {
        //cout<<"res is "<<res<<"\n";
        //cout<<"lcp of "<<suffixes[i-1].suffix<<" and "<<suffixes[i].suffix<<findLcp(suffixes[i-1].index,suffixes[i].index,k2-1)<<"\n";
        res+=(suffixes[i].suffix.length())-findLcp(suffixes[i-1].index,suffixes[i].index,k2-1);
    }
    return res;
}

int main()
{
    
    int i,j,t;

    std::ios::sync_with_stdio(false);

    cin>>t;
    while(t--)
    {
        //cout<<"t is "<<t<<"\n\n";
        cin>>str;
        boost::algorithm::to_lower(str);
        N=str.length();
        //cout<<"str is "<<str<<"\n";
        //cout<<"calling build array\n";
        cout<<buildSuffixArray()<<"\n";
    }
    
    return 0;
}
