#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
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
int dp[10][10],keys[3]={10,12,20},freq[3]={34, 8, 50};
int find_min_cost(int start,int end,int level)
{
	cout<<" start is "<<start<<"and end is "<<end <<"and dp is "<<dp[start][end]<<"\n";
	if(start>end) return 0;
	else if (start==end) return level*freq[start];
	else if(dp[start][end]!=-1){cout<<"returning "<<dp[start][end]<<"\n"; return dp[start][end];}
	else
	{
		int i,r,j,cost,min=INT_MAX;
		for(r=start;r<=end;r++)
		{
			cost=level*freq[r] + find_min_cost(start,r-1,level+1) + find_min_cost(r+1,end,level+1);
			if(cost<min) min=cost;
		}
		if(start>=0 and end>=0) dp[start][end]=min;
		return min;
	}
}
	

int main()
{
	
	int i,j;
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		dp[i][j]=-1;
	}
	int res=find_min_cost(0,2,1);
	cout<<"\n the min cost is "<<res<<"\n";
	return 0;
}
		
	
