#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
int dp[1001][1001],arr[1001];

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

int opt_cost(int start,int end)
{
	int start1,end1,start2,end2,sum1,sum2,sum3;
	if(dp[start][end]!=-1) return dp[start][end];
	else if(end==start+1) return abs(arr[start]-arr[end]);
	if(arr[start+1] > arr[end]) sum1=arr[start]-arr[start+1]+opt_cost(start+2,end);
	else sum1=arr[start]-arr[end]+opt_cost(start+1,end-1);
	
	if(arr[start]>arr[end-1]) sum2=arr[end]-arr[start]+opt_cost(start+1,end-1);
	else sum2=arr[end]-arr[end-1]+opt_cost(start,end-2);
	int res=max(sum1,sum2);
	dp[start][end]=res;
	return dp[start][end];
}

int main()
{
	int i,res, N=getInt();
	while(N)
	{
		for(i=0;i<N;i++)
		arr[i]=getInt();
		for(i=0;i<N;i++)
		{
			dp[i][i]=arr[i];
			if(i+1<N) dp[i][i+1]=abs(arr[i]-arr[i+1]),dp[i+1][i]=dp[i][i+1];
		}
		res=opt_cost(0,N-1);
		printf	
	return 0;
}

