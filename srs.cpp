//Geek for geeks 
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)



void reduce(string &str)
{
    int i,j;
    if(str.length()==0) return;
    For(i,0,str.length()-1)
    {
        if(str[i]==str[i+1])
        {
            str=str.substr(0,i)+str.substr(i+2,string::npos);
            reduce(str);
            break;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    string str;
    cin>>str;
    //cout<<"Initial length is "<<str.length();
    reduce(str);
    if(str.length()==0)
    cout<<"Empty String\n";
    else
    cout<<str<<"\n";
    return 0;
}
