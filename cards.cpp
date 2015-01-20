#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
#define md 1000007
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

int main()
{
	int t,n,temp1,temp2,temp3;
	t=getInt();
	while(t--)
	{
		n=getInt();
		if(n%2==0)
		{
			temp1=n/2;
			temp2=((((temp1%md)*((n-1)%md)*3)%md) + (2*(n%md)))%md) ;
		}
		else
		{
			temp1=(n-1)%md;
			temp2=((((3*(n%md)*(temp1%md))%md) + (2*(n%md)))%md);
		}
		printn(temp2);
		blank;
	}
	return 0;
}
			

