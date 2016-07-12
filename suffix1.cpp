#include "bits/stdc++.h"
using namespace std;
#include <boost/algorithm/string.hpp>    

char temp[1<<10],ch;
#define For(i,start,end) for(i=start;i<=end;i++)
#define blank putc_unlocked('\n',stdout);
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//cout<<" in while 2 with ch as "<<ch; 
		n1=n1*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n1*sign; 
}
string str;
struct Node
{
    int rank[2],index;
    string suffix;
}suffixes[100];
int P[20][100];
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
bool cmp2(Node a,Node b)
{
    return a.suffix< b.suffix;
}
void buildSuffixArray()
{
    int i,j,k;
    for(i=0;i<N;i++)
    {
        P[0][i]=str[i]-'a';
        suffixes[i].index=i;
        suffixes[i].suffix=str.substr(i,N-i);
    }
    int k2;
    for(k=1,k2=1;2*k<N;k*=2,k2++)
    {
        for(i=0;i<N;i++)
        {
            suffixes[i].rank[0]=P[k2-1][suffixes[i].index];
            suffixes[i].rank[1]=(suffixes[i].index+k<N)?(P[k2-1][suffixes[i].index+k]):-1;
        }
    
        //cout<<"Printing suffix before with k="<<k<<"\n";
        //printSuffix();
        sort(suffixes,suffixes+N,cmp);  
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
            cout<<"P["<<k2<<"]["<<suffixes[i].index<<"] = "<<P[k2][suffixes[i].index]<<"\n";
        }
        
    }
    cout<<"Printing suffix final \n";
    printSuffix();
    cout<<"\nChecking for sanity check\n";
    sort(suffixes,suffixes+N,cmp2);
    printSuffix();
}
int main()
{
    getline(cin,str);
    boost::algorithm::to_lower(str);
    N=str.length();
    cout<<"calling build array\n";
    buildSuffixArray();
    return 0;
}
