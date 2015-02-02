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

void  get_inp()
{
	//N=getInt();
	int i,j;
	for(i=0;i<N;i++)
	treats[i]=getInt();
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
		dp[i][j]=-1;
	}
}
int get_min(int treat,int start,int end,int age)
{
	int res,temp1,temp2;
	cout<<"\n\n\t treat "<<treats[treat]<<" start= "<<start<<" end ="<<end<<" dp[treat][age]"<<dp[treat][age]<<"\n";
	if(dp[treat][age]!=-1)
	return dp[treat][age];
	
	if(start>end)
	{
		cout<<"treat= "<<treats[treat]<<" start= "<<start<<" and end= "<<end<<" returning "<<treats[treat]*age<<"\n";
		dp[treat][age]=treats[treat]*age;
		return treats[treat]*age;
	}
	else
	{
		temp1=get_min(start,start+1,end,age+1);
		temp2=get_min(end,start,end-1,age+1);
		res= max(temp1,temp2);
		dp[treat][age]=res+ treats[treat]*age;
		cout<<"2)treat= "<<treats[treat]<<" start= "<<start<<" and end= "<<end<<" returning "<< dp[treat][age]<<"\n";
		return res+ treats[treat]*age;
	}
}
	
int main()
{
	
	N=getInt();
	get_inp();
	int i,j;
	int temp1=get_min(0,1,N-1,1);
	//cout<<"\nin main temp1 is "<<temp1<<"\n";
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
		dp[i][j]=-1;
	}
	int temp2=get_min(N-1,0,N-2,1);
	int res=max(temp1,temp2);
	printn(res);
	blank;
	return 0;
}
		
