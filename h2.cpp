#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
typedef long long int ll;
#define blank putc_unlocked('\n',stdout);
ll getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	ll sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//cout<<" in while 2 with ch as "<<ch; 
		n1=n1*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n1*sign; 
}

void printn(ll n) 
{
	char *ptr=temp+30;
	*ptr--='\0';
	ll flag=1;
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
ll getsum1(ll n)
{
	ll sum=0,temp;
	while(n>0)
	{
		temp=n%10;
		sum+=(temp*temp);
		n/=10;
	}
	return sum;
}
	
ll getsum2(ll n)
{
	ll sum=0,temp;
	while(n>0)
	{
		temp=n%10;
		sum+=temp;
		n/=10;
	}
	return sum;
}
	
	
int main()
{
	ll t,n,sum1,sum2,sum3,sum4,count1;
	set<ll> s1;
	int flag;
	t=32;
	while(t--)
	{
		n=getInt();
		count1=0;
		flag=0;
		s1.clear();
		sum1=getsum1(n);
		while(sum1!=1)
		{
			cout<<"sum1 is "<<sum1<<"\n";
			if(s1.count(sum1)==1)
			{
				 cout<<"not possible as sum1 repeats with "<<sum1<<"\n";
				 flag=1;
				 break;
			}
			else 
			{
				s1.insert(sum1);
				sum1=getsum1(sum1);
				count1++;
			}
		}
		if(flag==0)
		{
			printn(count1+1);blank;
		}
		else
		{
			printn(-1);blank;
		}
	}
	return 0;
}

