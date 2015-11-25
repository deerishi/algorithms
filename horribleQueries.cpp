#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
char ch,temp[1<<10];
int begin,end;
int value;
typedef long long int ll;
int getInt()
{

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

void printn(ll n) 
{
	char *ptr=temp+30;
	*ptr--='\0';
	ll flag=1;
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
int segmentTree[4*100000],lazyTree[4*100000];
void build(int position,int start,int stop)
{
	////cout<<" in build start ="<<start<<" ad stop is "<<stop<<"\n";
	if(start==stop)
	{
		segmentTree[position]=0;
		lazyTree[position]=0;
		//cout<<"build start="<<start<<" stop="<<stop<<" position = "<<position<<" returning = "<<segmentTree[position]<<"\n";
	}
	else
	{
		int mid=(start+stop)/2;
		build(2*position,start,mid);
		build(2*position+1,mid+1,stop);
		segmentTree[position]=segmentTree[2*position]+segmentTree[2*position+1];
		lazyTree[position]=0;
		//cout<<"build start="<<start<<" stop="<<stop<<" position = "<<position<<" returning = "<<segmentTree[position]<<"\n";
	}
}

void add(int position,int start,int stop)
{
	//NOw we take 2 cases 
	// 1) If its a fully overlapping interval , update the value in the lazy tree and move on
	//2) If its a partially overlapping interval , then move to the desired chiren and then update the lazy tree if need be.	
	int mid=(start+stop)/2;
	//cout<<"in add start="<<start<<" and stop is "<<stop<<" segment["<<"]"<<position<<" is "<<segmentTree[position]<<"\n";
	if(end < start or begin>stop )
	{
		return;
	}
	if(start>=begin and stop<=end)
	{
		lazyTree[position]+=value;//complete Overlap
		//cout<<"lazyTree["<<position<<"] is "<<lazyTree[position]<<" start="<<start<<" and stop is "<<stop<<"\n";;
		return;
	}

	
		//also check updates from the previous step
		segmentTree[position]+=value* (min(stop,end)-max(start,begin) +1 ); //Ie is numner of overlapping elements
		//cout<<"segmentTree["<<position<<"] is "<<segmentTree[position]<<" start="<<start<<" and stop is "<<stop<<"\n";;
		add(2*position,start,mid);
		add(2*position+1,mid+1,stop);
	
	
}

ll getSum(int position,int start,int stop)
{
	ll sum=0;
	int mid=(start+stop)/2;
	//cout<<"in getsum start="<<start<<" and stop is "<<stop<<"\n";
	if(start> end or stop< begin)
	{
		return 0;
	}
	if(lazyTree[position]!=0)
	{
		segmentTree[position] += lazyTree[position] * (stop-start+1);
		if(start!=stop)
		{
			lazyTree[2*position]+=lazyTree[position];
			lazyTree[2*position+1]+=lazyTree[position];
				
		}
		lazyTree[position]=0;
		
		
	}
	//cout<<"in add start="<<start<<" and stop is "<<stop<<" segment["<<""<<position<<"] is "<<segmentTree[position]<<"\n";
	if(start>=begin  and stop<=end)
	{
		return segmentTree[position];
	}
	sum += getSum(2*position,start,mid) + getSum(2*position+1,mid+1,stop);
	return sum;
	
}
int main()
{
	int n,v,t,i,c,x,res;
	t=getInt();
	while(t--)
	{
		n=getInt();
		c=getInt();
		build(1,1,n);
		for(i=1;i<=c;i++)
		{
			x=getInt();
			switch(x)
			{
				case 0: 
					begin=getInt();
					end=getInt();
					value=getInt();
					add(1,1,n);
					break;
				case 1:
					begin=getInt();
					end=getInt();
					res=getSum(1,1,n);
					//////cout<<"res is "<<res;
					printn(res);
					blank;
					
					break;
			}
			
		}
		
		
	}
}
