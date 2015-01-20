#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
#define pre 1
#define in 2
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
 
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
	char s[4];
	int leftover[3],n,temp1,pieces[3],res=0;
	n=getInt();
	for(int i=0;i<3;i++)
	{
		leftover[i]=0;
		pieces[i]=0;
	}
	while(n--)
	{
		scanf("%s",s);
		if(strcmp(s,"1/4")==0) pieces[0]++;
		else if(strcmp(s,"1/2")==0) pieces[1]++;
		else  pieces[2]++;
	}
		//cout<<"initially pieces[0]= "<<pieces[0]<<" pieces[1]= "<<pieces[1]<<" pieces[2]="<<pieces[2]<<"\n";
	if(pieces[0]>=pieces[2]) res+=pieces[2],pieces[0]-=pieces[2],pieces[2]=0;
	else if(pieces[2]>pieces[0]) res+=pieces[0],pieces[2]-=pieces[0],pieces[0]=0;
	
	if(pieces[1]>1) res+=pieces[1]/2,(pieces[1]%2==0)?(pieces[1]=0):pieces[1]=1;
	//cout<<"pieces[0]= "<<pieces[0]<<" pieces[1]= "<<pieces[1]<<" pieces[2]="<<pieces[2]<<"\n";
	if(pieces[2]>0)
	{
		res+=pieces[2];
		if(pieces[1]==1) res++;
	}
	else if(pieces[0]>0)
	{
		if(pieces[1]==1)
		{
			res++;
			if(pieces[0]<=2)
			{
				res=res;
			}
			else
			{
				pieces[0]-=2;
				res+=(pieces[0]/4);
				if(pieces[0]%4>0) res++;
			}
		}
		else
		{
			res+=(pieces[0]/4);
			if(pieces[0]%4>0) res++;
		}
	}
	printn(res+1);
	blank;
	return 0;
}
		
				
