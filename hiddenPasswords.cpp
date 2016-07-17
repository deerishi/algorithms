#include "bits/stdc++.h"

#define For(i,start,end) for(i=start;i<end;i++)   
using namespace std;



struct Node
{
    int rank[2],index;
    string suffix;
}suffixes[200001];
int N,k2;
string str;
int  P[20][200001];
bool cmp(Node a,Node b)
{
    return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]):(a.rank[0]<b.rank[0]);
}
void printP()
{
    int i,j;
    cout<<"  ";
    for(i=0;i<N;i++)
    {
        cout<<i<<" ";
    }
    for(i=0;i<k2;i++)
    {
        cout<<i<<" ";
        for(j=0;j<k2;j++)
        {
            cout<<P[i][j]<<" ";
        }
    }
}
void printSuffix()
{
    int i,j;
    For(i,0,str.length()-1)
    {
        cout<<suffixes[i].index<<"\t"<<suffixes[i].suffix<<"\t\t\t"<<suffixes[i].rank[0]<<"\t"<<suffixes[i].rank[1]<<"\n";
    }
    
    
}

bool cmp2(Node a,Node b)
{
    return a.suffix<b.suffix;
}

int findLcp(int x,int y)
{
    int i,j;
    int res=0;
    
    for(i=k2;i>=0 and x<N/2 and y<N/2;i--)
    {
        //cout<<" i is "<<i<<" P[i][x] is "<<P[i][x]<<" P[i][y] is "<<P[i][y]<<"\n";
        if(P[i][x]==P[i][y])
        {
            res+=1<<i;
            x+=1<<i;
            y+=1<<i;
        }
    }
    return res;
}
void buildSuffixArray()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        P[0][i]=str[i]-'a';
        suffixes[i].index=i;
        suffixes[i].suffix=str.substr(i,N-i);
    }
    int k;
    for(k=1,k2=1;k/2<N/2;k*=2,k2++)
    {
        for(i=0;i<N;i++)
        {
            suffixes[i].rank[0]=P[k2-1][suffixes[i].index];
            suffixes[i].rank[1]=(k+suffixes[i].index<N)?(P[k2-1][k+suffixes[i].index]):-1;
        }
        sort(suffixes,suffixes + N,cmp);
        P[k2][suffixes[0].index]=0;
        int cnt=0;
        for(i=1;i<N;i++)
        {
            P[k2][suffixes[i].index]=(suffixes[i].rank[0]==suffixes[i-1].rank[0] and suffixes[i].rank[1]==suffixes[i-1].rank[1])?cnt:(++cnt);
        }
        
    }
    //cout<<"printing suffix array\n";
    //printSuffix();
    //cout<<"for sanity check we have\n";
    //sort(suffixes,suffixes+N,cmp2);
    //printSuffix();
    k2--;
    //cout<<"\nK2 is "<<k2<<"\n";
}

void findPassword()
{
    int i,j;
    //cout<<"\n in findpassowrd K2 is "<<k2<<"\n";
    for(i=0;i<N;i++)
    {
        //cout<<"trying Suffix is "<<suffixes[i].suffix<<" with length "<<suffixes[i].suffix.length()<<"\n";
        if(suffixes[i].suffix.length()>=(N/2) and suffixes[i].index<(N/2))
        {
           

            int prefixLength=N/2,currentIndex=i,res=suffixes[i].index;
            j=i+1;
             //cout<<"1second try for Suffix is "<<suffixes[currentIndex].suffix<<" with length "<<suffixes[currentIndex].suffix.length()<<"\n";
            while(prefixLength>=(N/2) and j<N)
            {
                
                //cout<<" third second try for Suffix is "<<suffixes[j].suffix<<" with length "<<suffixes[j].suffix.length()<<"\n";
               
               
               prefixLength=findLcp(res,suffixes[j].index);
               //cout<<"current prefixLength is "<<prefixLength<<"\n";
               if(prefixLength>=N/2 and suffixes[j].index<res)
               {
                   res=suffixes[j].index;
               }
               j++;
            }
            cout<<res<<"\n";
            return;
            
        }
    }
}
void convertToLowerCase()
{
    int i;
    for(i=0;i<str.length();i++)
    {
        if(str[i]>='A' and str[i]<='Z')
        {
            str[i]=tolower(str[i]);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int l;
    while(t--)
    {
        cin>>l;
        cin>>str;
        convertToLowerCase();
        str=str+str;
        N=str.length();
        buildSuffixArray();
       
        findPassword();        
    }
    return 0;
    
}
