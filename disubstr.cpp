#include "bits/stdc++.h"'
using namespace std;
#define blank putc_unlocked('\n');
char ch,temp[1<<10];

int getInt()
{
	int n;
	ch=getc_unlocked(stdin);
	while(ch<'-') ch=getc_unlocked(stdin);
	int n=0,sign=1;
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin);
	
	while(isdigit(ch))
	{
		n=n*10+ch-'0';
		ch=getc_unlocked(stdin);
	}
	return n*sign;
}

void printn(int n)
{
	int i=0;
	char *ptr=temp+30;
	*ptr='\0';
	ptr--;
	int flag=1;
	if(n)
	{
		if(n<0) n*=-1,flag=-1;
		
		while(n>0)
		{
			*ptr--=n%10;
			n/=10;
		}
		if(flag==-1) *ptr--='-';
	
		ptr++;
		while(*ptr!='\0') putc_unlocked(*ptr++,stdout);
	}
	else
	{
		putc_unlocked('0',stdout);
	}
}

int main()
{
    t=getInt();
    char str[1005];
    while(t--)
    {
        scanf("%s",str);
        
    }
}
