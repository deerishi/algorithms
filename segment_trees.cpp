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

int arr[50000],M[65537],n,x,y,x2,y2;

void initialize(int node,int b,int e)
{
	//cout<<" node is "<<node<<" b is "<<b<<" e is "<<e<<"\n";
	if(b==e)
	{
		M[node]=b;
		//cout<<" node is "<<node<<" and M[node] is "<<M[node]<<"\n\n";
	}
	else
	{
		initialize(2*node,b,(b+e)/2);
		initialize(2*node+1,((b+e)/2)+1,e);
		
		if(arr[M[2*node]]<arr[M[2*node+1]])
		{
			M[node]=M[2*node+1];
		}
		else
		{
			M[node]=M[2*node];
		}
	//cout<<" node is "<<node<<" M[2*node]] is "<<M[2*node]<<" arr[M[2*node+1]] is "<<M[2*node+1]<<" and M[node] is "<<M[node]<<"\n\n";
	}

}

int query(int node,int b,int e)
{
	if(x>e or y<b){
		//cout<<"returning -1 for b="<<b<<" and e="<<e<<"\n"; 
		return -1;}
	
	if(b>=x and e<=y){
	//cout<<"returning M[node]= "<<M[node]<<" for b="<<b<<" e="<<e<<"\n"; 
	return M[node];
	}
	
	int p1=query(2*node,b,(b+e)/2);
	int p2=query(2*node+1,((b+e)/2)+1,e);
	//cout<<" p1 = "<<p1<<" and p2="<<p2<<" and b="<<b<<" and e="<<e<<"\n";
	if(p1==-1) return p2;
	else if(p2==-1) return p1;
	else if(arr[p1]<arr[p2]) return p2;
	else return p1;
} 

void update(int node,int b,int e)
{
	if(b==e and b==x)
	{
		arr[x]=y;
		//cout<<"now changing to arr[x="<<x<<"] to "<<arr[x]<<"\n";
		//M[node]=y2;
		return;
	}
	else
	{
		int mid=(b+e)/2;
		 if(x>mid) update(2*node+1,mid+1,e);
		else update(2*node,b,mid);
		
		if(arr[M[2*node]]>arr[M[2*node+1]])
		{
			M[node]=M[2*node+1];
		}
		else
		{
			M[node]=M[2*node];
		}
		//cout<<" node is "<<node<<" M[2*node]] is "<<M[2*node]<<" arr[M[2*node+1]] is "<<M[2*node+1]<<" and M[node] is "<<M[node]<<"\n\n";
	}	
}
	
int main()
{
	
	n=getInt();
	int i,j,res,m,bit;
	for(i=0;i<n;i++) arr[i]=getInt();
	
	initialize(1,0,n-1);
	//cout<<"\n enter query range\n ";
	m=getInt();
	while(m--)
	{
		bit=getInt();
		x=getInt();
		y=getInt();
		if(bit==0)
		{
			//cout<<"now updating \n";
			update(1,0,n-1);
		}
		else
		{
	//cout<<" x="<<x<<" and y="<<y<<"\n";
		res=query(1,0,n-1);
		//cout<<"\n\t res is ";
		printn(arr[res]);
		blank;
		}
	}
	
	return 0;
}
	
	
