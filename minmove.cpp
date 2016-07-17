#include "bits/stdc++.h"

#define For(i,start,end) for(i=start;i<end;i++)   
using namespace std;



struct Node
{
    int rank[2],index;
    string suffix;
}suffixes[200005],tempSuffixes[200005];
int N,k2,countArray[200005];
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
    cout<<"\n";
    for(i=0;i<k2;i++)
    {
        cout<<i<<" ";
        for(j=0;j<N;j++)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void printSuffix()
{
    int i,j;
    For(i,0,N)
    {
        cout<<suffixes[i].index<<"\t"<<suffixes[i].suffix<<"\t\t\t"<<suffixes[i].rank[0]<<"\t"<<suffixes[i].rank[1]<<"\n";
    }
    cout<<"\n\n";
    
}

bool cmp2(Node a,Node b)
{
    return a.suffix<b.suffix;
}

void countSort1()
{
    int i,j,k;
    int max1=INT_MIN;
    
    For(i,0,N)
    {
        if(max1<suffixes[i].rank[1])
        {
            max1=suffixes[i].rank[1];
        }
        
    }

    max1=max1+1;
    For(i,0,max1+1)
    {
        countArray[i]=0;
    }
    For(i,0,N)
    {
        countArray[suffixes[i].rank[1]+1]++;
    }
    For(i,1,max1+1)
    {
        countArray[i]+=countArray[i-1];
    }
    //cout<<"Count 1 array is \n";
    //For(i,0,max1+1)
    //{
     //   cout<<countArray[i]<<" ";
   // }
    
    for(i=N-1;i>=0;i--)
    {
        //cout<<"suffixes["<<i<<"].rank[1]+1 is "<<suffixes[i].rank[1]+1<<"\n";
        //cout<<"countArray[suffixes[i].rank[1]+1]-1 is "<<countArray[suffixes[i].rank[1]+1]-1<<"\n";
        tempSuffixes[countArray[suffixes[i].rank[1]+1]-1].rank[1]=suffixes[i].rank[1];
        tempSuffixes[countArray[suffixes[i].rank[1]+1]-1].index=suffixes[i].index;
        tempSuffixes[countArray[suffixes[i].rank[1]+1]-1].rank[0]=suffixes[i].rank[0];
        tempSuffixes[countArray[suffixes[i].rank[1]+1]-1].suffix=suffixes[i].suffix;
        
        //cout<<"tempSuffixes["<<countArray[suffixes[i].rank[1]+1]-1<<"].suffix is "<<tempSuffixes[countArray[suffixes[i].rank[1]+1]-1].suffix<<"\n";
        countArray[suffixes[i].rank[1]+1]--;
    }
}
void countSort2()
{
    //Over here we will sort on the rank[0], which is aways greater than 0
    int i,j,k;
    int max1=INT_MIN;
    //cout<<"In count sort 2 \n\n";
    For(i,0,N)
    {
        if(max1<tempSuffixes[i].rank[0])
        {
            max1=tempSuffixes[i].rank[0];
        }
        
    }

    For(i,0,max1+1)
    {
        countArray[i]=0;
    }
    For(i,0,N)
    {
        countArray[tempSuffixes[i].rank[0]]++;
    }
    For(i,1,max1+1)
    {
        countArray[i]+=countArray[i-1];
    }
    //cout<<"Count 1 array is \n";
    //For(i,0,max1+1)
    //{
       // cout<<countArray[i]<<" ";
    //}
    for(i=N-1;i>=0;i--)
    {
        //cout<<"countArray["<<tempSuffixes[i].rank[0]<<"]-1 is "<<countArray[tempSuffixes[i].rank[0]]-1<<"\n";
        suffixes[countArray[tempSuffixes[i].rank[0]]-1].rank[0]=tempSuffixes[i].rank[0];
        suffixes[countArray[tempSuffixes[i].rank[0]]-1].rank[1]=tempSuffixes[i].rank[1];
        suffixes[countArray[tempSuffixes[i].rank[0]]-1].index=tempSuffixes[i].index;
        suffixes[countArray[tempSuffixes[i].rank[0]]-1].suffix=tempSuffixes[i].suffix;
        //cout<<"suffixes["<<countArray[tempSuffixes[i].rank[0]]-1<<"].suffix is "<<suffixes[countArray[tempSuffixes[i].rank[0]]-1].suffix<<"\n"; 
        countArray[tempSuffixes[i].rank[0]]--;
        
    }
}

void printTemp()
{
    int i,j;
    For(i,0,N)
    {
        cout<<tempSuffixes[i].index<<"\t"<<tempSuffixes[i].suffix<<"\t\t\t"<<tempSuffixes[i].rank[0]<<"\t"<<tempSuffixes[i].rank[1]<<"\n";
    }
}
int findLcp(int x,int y)
{
    int i,j;
    int res=0;
    
    for(i=k2;i>=0 and x<N and y<N;i--)
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
    //cout<<"buildSuffixArray called for "<<N<<"\n";
    for(i=0;i<N;i++)
    {
        P[0][i]=str[i]-'a';
        suffixes[i].index=i;
        suffixes[i].suffix=str.substr(i,N*2-i);
        //cout<<"suffixes[i].suffix is "<<suffixes[i].suffix<<"\n";
    }
    int k;
    for(k=1,k2=1;k/2<N;k*=2,k2++)
    {
        for(i=0;i<N;i++)
        {
            suffixes[i].rank[0]=P[k2-1][suffixes[i].index];
            suffixes[i].rank[1]=(k+suffixes[i].index<N)?(P[k2-1][k+suffixes[i].index]):-1;
        }
        //cout<<"Printing suffix array before with k="<<k<<"\n";
        //printSuffix();
        //cout<<"\ndone\n";
        countSort1();
        //cout<<"Printing tempSuffixes after count sort 1\n";
        //printTemp();
        countSort2();
        //cout<<"Printing suffixes after count sort 2\n";
        //printSuffix();
        //sort(suffixes,suffixes + N,cmp);
        P[k2][suffixes[0].index]=0;
        int cnt=0;
        for(i=1;i<N;i++)
        {
            P[k2][suffixes[i].index]=(suffixes[i].rank[0]==suffixes[i-1].rank[0] and suffixes[i].rank[1]==suffixes[i-1].rank[1])?cnt:(++cnt);
        }
        
    }
    /*cout<<"printing suffix array\n";
    printSuffix();
    cout<<"for sanity check we have\n";
    sort(suffixes,suffixes+N,cmp2);
    printSuffix();*/
    k2--;
    //cout<<"\nK2 is "<<k2<<"\n";
}

void findPassword()
{
    int i,j;
    //cout<<"\n in findpassowrd K2 is "<<k2<<"\n";
    //cout<<"printing P\n";
    //printP();
    for(i=0;i<N;i++)
    {
        //cout<<"trying Suffix is "<<suffixes[i].suffix<<" with length "<<suffixes[i].suffix.length()<<"\n";
        if(suffixes[i].suffix.length()>=(N) and suffixes[i].index<(N))
        {
           

            int prefixLength=N,currentIndex=i,res=suffixes[i].index;
            j=i+1;
             //cout<<"1second try for Suffix is "<<suffixes[currentIndex].suffix<<" with length "<<suffixes[currentIndex].suffix.length()<<"\n";
            while(prefixLength>=(N) and j<N)
            {
                
                //cout<<" third second try for Suffix is "<<suffixes[j].suffix<<" with length "<<suffixes[j].suffix.length()<<"\n";
               if(suffixes[j].index>=N)
               {
                j++;
                continue;
               }
               
               prefixLength=findLcp(res,suffixes[j].index);
               //cout<<"current prefixLength is "<<prefixLength<<"\n";
               if(prefixLength>=N and suffixes[j].index<res)
               {
                   res=suffixes[j].index;
               }
               j++;
            }
            //cout<<"suffixes["<<j<<".suffix is "<<suffixes[j].suffix<<"\n";
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
   
        cin>>str;
        convertToLowerCase();
        N=str.length();
        str=str+str;
        
        buildSuffixArray();
       
        findPassword();        
    
    return 0;
    
}
