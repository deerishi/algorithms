#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//cout<<" in while 2 with ch as "<<ch; 
		n=n*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n*sign; 
}
void printn(long n) 
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
char str[10000];
void swap(int i,int j)
{
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
}
void recurse(int start,int end)
{
   // cout<<"s= "<<start<<" e="<<end<<"\n";
    if(start==end)
    {
         printf("%s\n",str);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap(start,i);
        //cout<<"calling "<<"s= "<<i+1<<" e="<<end<<"\n";
      
        recurse(start+1,end);
        swap(start,i);   
    }
}
int main()
{
    cin>>str;
    recurse(0,strlen(str)-1);
    return 0;
    
}
