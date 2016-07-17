#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)   
//Note to speed up computation and to avoid the N^2 term while comparing suffixes, I have 
//removed the suffix attribute from the structure
string str;
int N;
struct Node
{
    int index,rank[2];
    //string suffix;
}suffixes[60005],tempSuffixes[60005];


int P[20][60005];
string listOfSuffixes[60005];
int k2;
int countArray[60005];
int lcp[60005];

void findlcp();

void printP()
{
    int i,j;
    cout<<"  ";
    For(i,0,N)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    For(i,0,k2)
    {
        cout<<i<<" ";
        For(j,0,N)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void printSuffix()
{
    int i,j;
    For(i,0,str.length())
    {
        cout<<suffixes[i].index<<"\t"<<listOfSuffixes[suffixes[i].index]<<"\t\t\t"<<suffixes[i].rank[0]<<"\t"<<suffixes[i].rank[1]<<"\n";
    }
}

void printTemp()
{
    int i,j;
    For(i,0,N)
    {
        cout<<tempSuffixes[i].index<<"\t"<<listOfSuffixes[tempSuffixes[i].index]<<"\t\t\t"<<tempSuffixes[i].rank[0]<<"\t"<<tempSuffixes[i].rank[1]<<"\n";
    }
}
bool cmp(Node a,Node b)
{
    return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]):(a.rank[0]<b.rank[0]);
}
int cmp2(const void * a1, const void * b1)
{
    Node a=*(Node*)a1;
    Node b=*(Node*)b1;
    //return listOfSuffixes[a.index].compare(listOfSuffixes[b.index]);
    return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]):(a.rank[0]<b.rank[0]);
}
void countSort1()
{
    int max1=max(300,N),i,j,k,min1=-1;
    memset(countArray, 0, max1*sizeof(int));
    
    max1=max1-min1;
    //cout<<"max1 is "<<max1<<"\n";
    
   // cout<<"\n in csort 1 filling the count array \n";
    For(i,0,N)
    {
        //cout<<"suffixes["<<i<<"].rank[1]-min1 is  "<<suffixes[i].rank[1]-min1<<"\n";
        countArray[suffixes[i].rank[1]-min1]++;
    }
    /*cout<<"\n before the countArray is \n";
    For(i,0,max1+1)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    For(i,0,max1+1)
    {
        cout<<countArray[i]<<" ";
    }
    cout<<"\n";*/
    For(i,1,max1+1)
    {
        countArray[i]+=countArray[i-1];
    }
    
    /*cout<<"\n the countArray is \n";
    For(i,0,max1+1)
    {
        cout<<countArray[i]<<" ";
    }
    cout<<"\n";*/
    for(i=N-1;i>=0;i--)
    {
        //cout<<"countArray["<<suffixes[i].rank[1]-min1<<"]-1 is "<<countArray[suffixes[i].rank[1]-min1]-1<<"\n";
        tempSuffixes[countArray[suffixes[i].rank[1]-min1]-1].rank[1]=suffixes[i].rank[1];
        tempSuffixes[countArray[suffixes[i].rank[1]-min1]-1].index=suffixes[i].index;
        tempSuffixes[countArray[suffixes[i].rank[1]-min1]-1].rank[0]=suffixes[i].rank[0];
        //tempSuffixes[countArray[suffixes[i].rank[1]-min1]-1].suffix=suffixes[i].suffix;
        //cout<<"tempSuffixes["<<countArray[suffixes[i].rank[1]+1]-1<<"].suffix is "<<tempSuffixes[countArray[suffixes[i].rank[1]+1]-1].suffix<<"\n";
        countArray[suffixes[i].rank[1]-min1]--;
    }
}
void countSort2()
{
    int i,j,max1=max(N,300),k;
    memset(countArray, 0, max1*sizeof(int));
    
    For(i,0,N)
    {
        countArray[tempSuffixes[i].rank[0]]++;
    }
    For(i,1,max1+1)
    {
        countArray[i]+=countArray[i-1];
    }
    /*cout<<"\n 2 the countArray is \n";
    For(i,0,max1+1)
    {
        cout<<countArray[i]<<" ";
    }
    cout<<"\n";*/
    for(i=N-1;i>=0;i--)
    {
        //cout<<"2 countArray["<<tempSuffixes[i].rank[0]<<"]-1 is "<<countArray[tempSuffixes[i].rank[0]]-1<<"\n";
        suffixes[countArray[tempSuffixes[i].rank[0]]-1].index=tempSuffixes[i].index;
        //suffixes[countArray[tempSuffixes[i].rank[0]]-1].suffix=tempSuffixes[i].suffix;
        suffixes[countArray[tempSuffixes[i].rank[0]]-1].rank[0]=tempSuffixes[i].rank[0];
        suffixes[countArray[tempSuffixes[i].rank[0]]-1].rank[1]=tempSuffixes[i].rank[1];
        
        //cout<<"suffixes["<<countArray[tempSuffixes[i].rank[0]]-1<<"].suffix is "<<suffixes[countArray[tempSuffixes[i].rank[0]]-1].suffix<<"\n";
        countArray[tempSuffixes[i].rank[0]]--;
    }
}

int findLcp(int x,int y)
{
    int i,j,res=0;
    
    for(i=k2-1;i>=0 and x<N and y<N;i--)
    {
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
    int i,j,k;
    for(i=0;i<N;i++)
    {
        P[0][i]=int(str[i]);
        suffixes[i].index=i;
        //suffixes[i].suffix=str.substr(i,N-i);
        //cout<<"suffix "<<i<<" is "<<str.substr(i,N-i)<<"\n";
        listOfSuffixes[i]=str.substr(i,N-i);
    }
    
    for(k=1,k2=1;k/2<N;k*=2,k2++)
    {
        for(i=0;i<N;i++)
        {
            suffixes[i].rank[0]=P[k2-1][suffixes[i].index];
            suffixes[i].rank[1]=(k+suffixes[i].index<N)?P[k2-1][k+suffixes[i].index]:-1;
        }
        //cout<<"printnig suffix array before with k= "<<k<<"\n";
        //printSuffix();
        countSort1();
        //cout<<"Printint temp array with k="<<k<<"\n";
        //printTemp();
        countSort2();
        //cout<<"Printing suffix array with k="<<k<<"\n";
        //printSuffix();
        //sort(suffixes,suffixes+N,cmp);
        P[k2][suffixes[0].index]=0;
        int cnt=0;
        
        for(i=1;i<N;i++)
        {
            P[k2][suffixes[i].index]=(suffixes[i].rank[0]==suffixes[i-1].rank[0] and suffixes[i].rank[1]==suffixes[i-1].rank[1])?cnt:(++cnt);
        }
    }
    k2--;
    //cout<<"Printing final suffix\n";
    //printSuffix();
    //cout<<"\n for sanity check\n";
    //sort(suffixes,suffixes+N,cmp2);
    //printSuffix();
    //cout<<"k2 is "<<k2<<" P is \n";
    //printP();
    //cout<<"Now finding the LCP ARRAY\n";
    findlcp();
    int res=listOfSuffixes[suffixes[0].index].length();
    //printSuffix();
    For(i,1,N)
    {
        
        res+=listOfSuffixes[suffixes[i].index].length() - lcp[i];
        //cout<<"Lcp of "<<listOfSuffixes[suffixes[i].index]<<" and "<<listOfSuffixes[suffixes[i-1].index]<<" is "<<lcp[i]<<"\n";
    }
    cout<<res<<"\n";
}
void findlcp()
{
    int invSa[60005];
    int i,j;
    For(i,0,N)
    {
        invSa[suffixes[i].index]=i;
    }
    int k=0;
    For(i,0,N)
    {
        if(invSa[i]==0)
        {
            k=0;
            continue;
        }
        j=suffixes[invSa[i]-1].index; //get the previous suffix index in the sorted array of suffixes
        while(i+k<N and j+k<N and str[i+k]==str[j+k])
        {
            k++;
        }       
        lcp[invSa[i]] =k;
        //cout<<"i="<<i<<" checking between "<<listOfSuffixes[j]<<" and  "<<listOfSuffixes[i]<<" with lcp "<<lcp[invSa[i]]<<"\n";
        if(k>0)
        {
            k--;
        }
    }
}


int main()
{
    int t;
    std::ios::sync_with_stdio(false);
    
    cin>>t;
    while(t--)
    {
        cin>>str;
        //convertToLowerCase();
        N=str.length();
        //cout<<"N is "<<N<<"\n";
        buildSuffixArray();
    }
    return 0;
}
