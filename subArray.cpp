#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	////cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*//cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		////cout<<" in while 2 with ch as "<<ch; 
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
int arr1[1000000], segTree[4000000];
void build(int position,int start,int stop)
{
    if(start==stop)
    {
        segTree[position]=arr1[start];
        return;
    }
    int mid=(start+stop)/2;
    build(2*position,start,mid);
    build(2*position+1,mid+1,stop);
    segTree[position]=max(segTree[2*position],segTree[2*position+1]);
    return;
    
}
int begin,end;
int query(int position,int start,int stop)
{
    //cout<<"start "<<start<<" stop "<<stop<<"\n";
    if(stop< begin or start> end)
    {
        //cout<<"returning 0\n";
        return 0;
    }
    
    if(start>=begin and stop<=end)
    {
            //cout<<"returning   "<<segTree[position]<<"\n";
        return segTree[position];
    }
    int mid=(start+stop)/2;
    if(stop>=begin and start<=end )
    {
        int temp=max(query(2*position,start,mid),query(2*position+1,mid+1,stop));
                    //cout<<"returning   "<<temp<<"\n";
        return temp;
    }
}
int main()
{
    int n,len1,len2,i,j=0,maxVal,k;
    n=getInt();
    maxVal=INT_MIN;
    //getc_unlocked(stdin);
    for(i=1;i<=n;i++)
    {
        arr1[i]=getInt();
    }
    build(1,1,n);
    k=getInt();

    for(i=1;i+k-1<=n;i++)
    {
        begin=i;
        end=i+k-1;
        printn(query(1,1,n));
        putc_unlocked(' ',stdout);
       
    }
    
    blank;
    return 0;
}
