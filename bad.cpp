#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;

int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//cout<<" in while 2 with ch as "<<ch; 
		n=n*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n*sign; 
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
class  BadNeighbours
{
	public:
		int res,size;
		int maxDonations(int donations[1000]);
};
int BadNeighbours :: maxDonations(int donations[1000])
{
	int i,j,ans;
	//cout<<"\n enter size\n";
	size=getInt();
	for(i=0;i<size;i++)
	{
		donations[i]=getInt();
	}
	int dp1[1000],dp2[1000];
	memset(dp1,0,1000);
	memset(dp2,0,1000);
	dp1[0]=donations[0];
	
	for(i=2;i<size-1;i++)
	{
		dp1[i]=max(dp1[i-2]+donations[i],dp1[i-1]);
		cout<<"dp1[i="<<i<<"] is "<<dp1[i]<<"dp1[i-2] + donations[i] is "<<dp1[i-2]+donations[i]<<" and dp[i-1[ is"<<dp1[i-1]<<"\n";	
	}
	dp2[1]=donations[1];
	for(i=2;i<size;i++)
	{
		dp2[i]=max(dp2[i-2]+donations[i],dp2[i-1]);
		cout<<"dp2[i="<<i<<"] is "<<dp2[i]<<"dp2[i-2] + donations[i] is "<<dp2[i-2]+donations[i]<<" and dp2[i-1[ is"<<dp2[i-1]<<"\n";	
	}
	ans=max(dp1[size-2],dp2[size-1]);
	return ans;
}			
int main()
{
	BadNeighbours b1;
	int arr[1000],t=getInt();
	while(t--)
	{
		b1.res=b1.maxDonations(arr);
		cout<<"\n res is "<<b1.res<<"\n";
	}
	return 0;
}
	
