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
vector<int> important1,nonImportant;
int N,K,t,l,imp=0,non_imp=0;
bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    N=getInt();
    K=getInt();
    int i,j,x,y;
    For(i,1,N)
    {
        l=getInt();
        t=getInt();
        if(t==1)
        {
            //cout<<"pushong "<<l<<"\n";
            important1.push_back(l);
        }
        else
        {
            nonImportant.push_back(l);
        }
      
    }
    sort(important1.begin(),important1.end(),compare);
    //cout<<"the sorted is \n";
    int s=important1.size();
    int result=0;
    result+=accumulate(nonImportant.begin(),nonImportant.end(),0);
    if(N<=K)
    {
        result+=accumulate(important1.begin(),important1.end(),0);
    }
    else
    {
        if(important1.size()>K)
        {
            result+=accumulate(important1.begin(),important1.begin()+K,0);
            result-=accumulate(important1.begin()+K,important1.end(),0);
        }
        else
        {
             result+=accumulate(important1.begin(),important1.end(),0);
        }
    }
    printf("%d\n",result);
    return 0;
}
