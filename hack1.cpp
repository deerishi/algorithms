#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define For(i,start,end) for(i=start;i<=end;i++)
char current[1<<10],ch;
//This is lexicographical topological sort
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//////cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*////cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//////cout<<" in while 2 with ch as "<<ch; 
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

int main()
{
    int n,i,x,y,px,py,hor=0,ver=0;
    
    n=getInt();
    px=getInt();
    py=getInt();
    for(i=1;i<n;i++)
    {
        x=getInt();
        y=getInt();
        if(x==px)
        {
            hor++;
        }
        else if(y==py)
        {
            ver++;
        }
        px=x;
        py=y;
    }
    if(hor==n-1 or ver==n-1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
