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
int getsum1(int n)
{
	int sum=0,temp;
	while(n>0)
	{
		temp=n%10;
		sum+=(temp*temp);
		n/=10;
	}
	return sum;
}
		
	
int main()
{
	int n,sum1,count1=1,arr[1495];
	memset(arr,0,1495);
	n=getInt();
	sum1=getsum1(n);
	while(1)
	{
		if(sum1==1)
		{
			printf("%d\n",count1);
			break;
		}
		else if(arr[sum1]==1)
		{
			printf("-1\n");
			break;
		}
		else
		{
			arr[sum1]=1;
			count1++;
			sum1=getsum1(sum1);
		}
	}
	return 0;
}

