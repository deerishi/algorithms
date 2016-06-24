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
int compare(const void * aa,const void* bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	if(a[0]<b[0]) 
	return -1;
	else if(a[0]==b[0])
	return 0;
	else
	return 1;
}
 	
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
int mountain1[1000],mountain2[1000];
int main()
{	
	int t=getInt(),m1,m2,diff,i,j,flag;
	while(t--)
	{
		diff=INT_MAX;
		flag=0;
		m1=getInt();
		for(i=0;i<m1;i++)
		{
			mountain1[i]=getInt();
		}
		m2=getInt();
		for(i=0;i<m2;i++)
		{
			mountain2[i]=getInt();
		}
		for(i=0;i<m1;i++)
		{
			for(j=0;j<m2;j++)
			{
				if(diff> int(abs(mountain1[i]-mountain2[j])))
				{
					diff=int(abs(mountain1[i]-mountain2[j]));
				}
				if(diff==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		printn(diff);
		blank;	
	}	
}
