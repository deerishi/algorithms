#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)

int treats[2002],dp[2002][2002];

int N;

int getInt()  
{	
    ch=getc_unlocked(stdin);
    //cout<<" in the beginning with ch as "<<ch;
    while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);}
    int sign=1,n1=0;
    if(ch=='-') sign=-1,ch=getc_unlocked(stdin);
    while(ch>'-')
    {
        //cout<<" in while 2 with ch as "<<ch;
        n1=n1*10 +ch-'0';
        ch=getc_unlocked(stdin);
    }
    return n1*sign;
}

void printn(int n)
{
    char *ptr=temp+30;
    *ptr--='\0';
    int flag=1;
    if(n)
    {
        if(n<0) n*=-1,flag=-1;
            
        while(n>0)
        {
            *ptr--=(n%10) +'0';
            n/=10;
        }
        if(flag==-1) *ptr--='-';
        
    }
    else {*ptr='0';putc_unlocked('0',stdout);return;}
    ptr++;
    while(*ptr!='\0')
    {
        putc_unlocked(*ptr++,stdout);
    }
}
int arr[50000],M[65537],n,x,y;

void fill_tree(int node,int b,int e)
{
	if(b==e)
	{
		M[node]=b;
	}
	else
	{
		fill_tree(2*node,b,(b+e)/2);
		fill_tree(2*node+1,((b+e)/2) + 1,e);
		
		if(M[2*node]>M[2*node+1])
		{
			M[node]=M[2*node+1];
		}
		else
		{
			M[node]=M[2*node];
		}
	}
}

int get_query(int node,int b,int e)
{
	if(x>e || y<b)  return -1;
	if(b>=x and e<=y) return M[node];
	
	int p1=get_query(2*node,b,(b+e)/2);
	int p2=get_query(2*node+1,((b+e)/2)+1,e);
	if(p1==-1) return arr[p2];
	else if(p2==-1) return p1;
	else if(arr[p1]<arr[p2]) return p1;
	else return p2;
}
		
		
		

int main()
{
	int i,j,b,e;
	n=getInt();
	for(i=0;i<n;i++)
	arr[i]=getInt();
	fill_tree(1,0,n-1);
	cout<<"\n enter query range \n";
	x=getInt();
	y=getInt();
	int res=get_query(1,x,y);
	cout<<"\n the min is "<<arr[res]<<"\n";
	return 0;
}	
	
	
	

	
	
	
	
		
