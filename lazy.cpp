#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define For(i,start,end) for(i=start;i<=end;i++)
typedef long long int ll;
char current[1<<10],ch;

int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*//cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
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

int map1[106];
ll findFact(int  x)
{
    ll i,fact=1;
    if(x==0)
    {
        return 1;
    }
    for(i=1;i<=x;i++)
    {
        fact=fact*i;
    }
    return fact;
}

int main()
{
    int N=getInt(),i,x;
    for(i=0;i<N;i++)
    {
        map1[i]=0;
        
    }
    for(i=0;i<N;i++)
    {
        x=getInt();
        map1[x]++;
    }
    ll factN=findFact(N),temp;
    for(i=0;i<=105;i++)
    {
        temp=findFact(map1[i]);
        factN/=temp;
        //cout<<"Fact is "<<factN<<"\n";
    }
    //cout<<"Fact is "<<factN<<"\n";
    double fa2=double(factN);
    //cout<<"fa2 is "<<fa2<<"\n";
    //double res=fa2/((fa2-1)*(fa2-1));
    printf("%0.6lf\n",fa2);
    return 0;
    
}
