#include "bits/stdc++.h"

using namespace std;
char temp[1<<10],ch;

int getInt()
{
    ch=getc_unlocked(stdin);
    while(ch<'-')
    {
        ch=getc_unlocked(stdin);
    }
    int sign=1,num=0;
    if(ch=='-')
    {
        sign=-1;ch=getc_unlocked(stdin);
    }
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getc_unlocked(stdin);
    }
    return num*sign;
    
}

int main() 
{
	//char arr[20]="hello world";
	int n;
	while((n=getInt())>0)
	{
	    printf("%d\n",int(log2(n)+0.00000001));
	    
	}
    return 0;
}
