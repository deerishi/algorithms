#include "bits/stdc++.h"
using namespace std;
#define dgetc() getc_unlocked(stdin);
#define dputc(ch) putc_unlocked(ch,stdout);
#define blank putc_unlocked('\n',stdout);
typedef long long int ll;
char TEMP[1<<10],CH;

int getInt()
{
	CH=getc_unlocked(stdin);
	while(CH<'-') CH=dgetc();
	
	int n=0,sign=1;
	if(CH=='-')
	{
		sign=-1;CH=dgetc();
		
	}
	
	while(isdigit(CH))
	{
		n=n*10+CH-'0';
		CH=dgetc();
	}
			
	return n*sign;
}

void printn(int n)
{
	//cout<<"n is "<<n<<"\n";
	int sign=1;
	char *ptr=TEMP+ 30;
	*ptr--='\0';
	if(n<0)
	{
		sign=-1;
		n*=-1;
	}
	
	while(n>0)
	{
		*ptr--=n%10+'0';
		n/=10;
		//cout<<"*ptr is "<<*ptr+1<<"\n";
	}
	if(sign==-1)
	{
		*ptr--='-';
	}
	ptr++;
	while(*ptr!='\0')
	{
		dputc(*ptr++);
	}
}

int main()
{
	int n,m,temp,i;
	ll id_bobf,id_fof;
	set<ll> s1;
	n=getInt();
	temp=n;
	while(temp--)
	{
		scanf("%lld",&id_bobf);
		s1.insert(id_bobf);
		m=getInt();
		for(i=0;i<m;i++)
		{
			scanf("%lld",&id_fof);
			s1.insert(id_fof);
		}
		
	}
	//cout<<"size is "<<s1.size()<<"\n";
		printn(s1.size()-n);
		blank;
	return 0;
}

