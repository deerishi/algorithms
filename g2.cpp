#include "bits/stdc++.h"
using namespace std;
//SPOJ DATING RISHI
typedef unsigned long long int ll;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

int main()
{
    std::ios::sync_with_stdio(false);
    int i,k;
    char str[]="ge  eks f ";
    
    char *ptr=str;
    int count=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ') count++;
        else if(str[i]!=' ' and count>0)
        {
            ptr-count=&(str[i]);count=0;
        }
        
    }
    cout<<"\n the modified string is "<<str<<"\n";
    return 0;
    
}
