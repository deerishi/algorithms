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

int main()
{
	int arr[1000],i,j,n,sparse_table[1000][1000];
	//printf("\nenter array size \n");
	n=getInt();
	for(i=0;i<n;i++)
	{
		arr[i]=getInt();
		dp[i][0]=i;
	}
	for(j=1;pow(2,j)<=n;j++)
	{
		for(i=0;i+int(pow(2,j))<=n;i++)
		{
			cout<<"i ="<<i<<" j="<<j<<" and arr[dp[i][j-1]] "<<arr[dp[i][j-1]]<<" and arr[dp[i+int(pow(2,j-1))][j-1]] "<<arr[dp[i+int(pow(2,j-1))][j-1]];
			if(arr[dp[i][j-1]]<arr[dp[i+int(pow(2,j-1))][j-1]])
			{
				dp[i][j]=i;
			}
			else
			{
				dp[i][j]=i+pow(2,j-1);
			}
			cout<<"  dp[i][j]  "<<dp[i][j]<<"\n\n";
		}
		
	}
	cout<<"\n enter range to be searched for \n";
	int x,y,res;
	x=getInt();
	y=getInt();
	x--;
	y--;
	int range=int(ceil(log(y-x)/log(2)));
	cout<<"\n power is "<<range<<" starting point "<<x<<" and "<<y-int(pow(2,range))+1<<"\n";
	if(arr[dp[x][range]]<arr[dp[y-int(pow(2,range))+1][range]])
	{
		res=arr[dp[x][range]];
	}
	else
	{
		res=arr[dp[y-int(pow(2,range))+1][range]];
	}
	cout<<"\n the res is "<<res<<"\n";
	return 0;
}
		
	
	
		

	
	
	
	
