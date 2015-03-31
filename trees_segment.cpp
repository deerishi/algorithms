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

struct Node
{
	int best,lsuffix,rprefix,ssum;
};
typedef struct Node node;
node arr[50001],tree[65537];
node default1;
default1.ssum=INT_MIN;
default1.best=INT_MIN;
default1.rprefix=INT_MIN;
default1.lsuffix=INT_MIN;


void build(int node,int b,int e)
{
	if(b==e)
	{
		tree[node].best=arr[b];
		tree[node].lsuffix=arr[b];
		tree[node].rprefix=arr[b];
		tree[node].ssum=arr[b];
	}
	else
	{
		int mid=(b+e)/2;
		build(2*node,b,mid);
		build(2*node+1,mid+1,e);
		
		node left,right;
		left=tree[2*node];
		right=tree[2*node+1];
		
		tree[node].ssum=left.ssum+right.ssum;
		tree[node].lsuffix=max(left.suffix,left.ssum+right.rprefix);
		tree[node].rprefix=max(right.rprefix,right.ssum+left.lprefix);
		tree[node].best=max(max(left.best,right.best),left.lsuffix+right.rprefix);
		
	}
}

int query(int node,int b,inte,int x,int y)
{
	if(b>y or x>e) return INT_MIN;
	
	if(b<=x and y>=e) return tree[node].best;
	
	int mid=(b+e)/2;
	node p1=query(2*node,b,mid,x,y);
	node p2=query(2*node+1,mid+1,x,y);
	
	if(p1.ssum==INT_MIN) return p2.best;
	else if(p2.ssum==INT_MIN) return p1.best;
	else
	{
		int sum=p1.lsuffix + p2.rprefix;
		if(p1.best>p2.best and p1.best>sum) return p1.best;
		else if(p2.best>p1.best and p2.best>sum) return p2.best;
		else if(sum>p2.best and p1.best<sum) return sum;
	}
	
	
	
	
	
	
	
	
	
	
	
int main()
{
	int i,N;
	N=getInt(N);
	
	for(i=0;i<N;i++)
	arr[i]=getInt();
	
	
	
		
