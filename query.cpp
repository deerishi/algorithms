#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);


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

int arr2[50001],N,M;
struct Node1
{
	int ssum,lprefix,rsuffix,best;
}arr[131072];

typedef struct Node1 Node;
Node create(int ssum,int lprefix,int rsuffix,int best)
{
	Node temp;
	temp.ssum=ssum;
	temp.lprefix=lprefix;
	temp.rsuffix=rsuffix;
	temp.best=best;
	return temp;
}

void update(int node,int l,int r,int x,int val)
{
	//cout<<" l is "<<l<<" r is "<<r<<" node is "<<node<<" x is "<<x<<"\n";
	if(l==r and l==x) 
	{
		//cout<<"updating \n ";
		
		arr[node].ssum=val;
		arr[node].rsuffix=val;
		arr[node].lprefix=val;
		arr[node].best=val;
	}
	else
	{
		int mid=(l+r)/2;
		if(x<=mid) 
		{
			//cout<<"\n calling <\n";
			update(2*node,l,mid,x,val);
		}
		else if(x>mid) 
		{
			//cout<<"\n calling >\n";
			update(2*node+1,mid+1,r,x,val);
		}
		arr[node].ssum=arr[2*node].ssum+arr[2*node+1].ssum;
		arr[node].lprefix=max(arr[2*node].lprefix,arr[2*node].ssum+arr[2*node+1].lprefix);
		arr[node].rsuffix=max(arr[2*node+1].rsuffix,arr[2*node].rsuffix+arr[2*node+1].ssum);
		arr[node].best=max(max(arr[2*node].best,arr[2*node+1].best),arr[2*node].rsuffix+ arr[2*node+1].lprefix);	
	}
}
	
void build(int node,int b,int e)
{
	if(b==e)
	{
		arr[node].ssum=arr2[b];
		arr[node].rsuffix=arr2[b];
		arr[node].lprefix=arr2[b];
		arr[node].best=arr2[b];
	}	
	else 
	{
		int mid=(b+e)/2;
		build(2*node,b,mid);
		build(2*node+1,mid+1,e);
		
		arr[node].ssum=arr[2*node].ssum+arr[2*node+1].ssum;
		arr[node].lprefix=max(arr[2*node].lprefix,arr[2*node].ssum+arr[2*node+1].lprefix);
		arr[node].rsuffix=max(arr[2*node+1].rsuffix,arr[2*node].rsuffix+arr[2*node+1].ssum);
		arr[node].best=max(max(arr[2*node].best,arr[2*node+1].best),arr[2*node].rsuffix+ arr[2*node+1].lprefix);
	}
}
//



Node query(int node,int b,int e,int x,int y)
{
	Node non_node;
non_node.ssum=INT_MIN;
non_node.best=INT_MIN;
non_node.lprefix=INT_MIN;
non_node.rsuffix=INT_MIN;
	if(x>e or y<b) return non_node;
	
	if(b>=x and e<=y) return arr[node];
	
	int mid=(b+e)/2;
	Node p1=query(2*node,b,mid,x,y);
	Node p2=query(2*node+1,mid+1,e,x,y);
	
	if(p1.ssum==INT_MIN) return p2;
	
	if(p2.ssum==INT_MIN) return p1;
	
		
	Node temp;
	temp.ssum=p1.ssum + p2.ssum;
	temp.lprefix=max(p1.lprefix,p1.ssum + p2.lprefix);
	temp.rsuffix=max(p2.rsuffix,p1.rsuffix + p2.ssum);
	temp.best=max(max(p1.best,p2.best),p1.rsuffix + p2.lprefix);
	
	return temp;
}

int main()
{
	int i,j,x,y,num;
	N=getInt();
	for(i=1;i<=N;i++) 
	arr2[i]=getInt();
	build(1,1,N);
	M=getInt();
	Node res;
	for(i=0;i<M;i++)
	{
		num=getInt();
		x=getInt();
		y=getInt();
		//cout<<"x is "<<x<<" and y is "<<y<<"\n";
		if(num==1)
		{
			res=query(1,1,N,x,y);
			printn(res.best);
			blank;
		}
		else 
		update(1,1,N,x,y);
	}
	return 0;
}	
	
