#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
int arr[20001];
//int compare(const 
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
	int T,N,i,j,K,diff;
	T=getInt();
	while(T--)
	{
		
		N=getInt();
		K=getInt();
		for(i=0;i<N;i++)
		arr[i]=getInt();
		if(K==1) {printn(0);blank;}
		else
		{
			sort(arr,arr+N);
			diff=arr[K-1]-arr[0];
			for(i=1,j=K;i<N and j<N;i++,j++)
			{
				if((arr[j]-arr[i])<diff) diff=arr[j]-arr[i];
			}
			printn(diff);
			blank;
		}
		
	}
	return 0;
}
					
		
		
	
