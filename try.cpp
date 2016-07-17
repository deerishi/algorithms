#include "bits/stdc++.h"
using namespace std;
string str;

void getStr()
{
    char ch;
    ch=getc_unlocked(stdin);
    while(ch<'-')
    {
        ch=getc_unlocked(stdin);
    }
    while(isalpha(ch))
    {
        str+=ch;
        ch=getc_unlocked(stdin);
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
   
        getStr();
        
        str=str+str;
        int N=str.length();
        
        cout<<"str is "<<str.length()<<"\n";

    
    return 0;
    
}
