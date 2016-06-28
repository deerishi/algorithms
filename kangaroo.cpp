#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define For(i,start,end) for(i=start;i<=end;i++)
char current[1<<10],ch;

int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*//cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
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
	char *ptr=current+30;
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
int x1,x2,m1,m2;

int main()
{
    x1=getInt();
    m1=getInt();
    x2=getInt();
    m2=getInt();
    if(x2>x1 and m2>m1)
    {
        printf("NO\n");
    }
    else
    {
        if(m1==m2 and x2==x1)
        {
            printf("YES\n");
        }
        else  if(m1==m2 and x2!=x1)
        {
             printf("NO\n");
        }
        else if((x2-x1)%(m1-m2)==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
