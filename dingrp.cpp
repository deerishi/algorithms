#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
char current[1<<10],ch;

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
	ptr++;Bron–Kerbosch algorithm

	while(*ptr!='\0')
	{
		putc_unlocked(*ptr++,stdout);
	}
}
int N,K;
struct Node
{
    int type,number;
};

int main()
{
    Node arr[105];
    int i,j=-1;
    bool flag=false;
    char ch2;
    for(i=0;i<N;i++)
    {
        ch2=getc_unlocked(stdin);
        if(flag==false)
    }
    N=getInt();
    K=getInt();
    
}
