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
int a[182][182],n,m;

int bfs(int x,int y)
{
	int res,temp,i,j;
	queue<pair<int,int> > q1;
	set<int> s1;
	q1.push(make_pair(x,y));
	q1.push(make_pair(-1,-1));
	//cout<<"\n calling for "<<x<<" and "<<y<<"\n";
	while(!q1.empty())
	{
		i=q1.front().first;j=q1.front().second;
		if(i==-1 and j==-1) q1.pop() ;
		else if(a[i][j]==1)
		{
			s1.insert(i*n+j);
			res=abs(x-i)+abs(y-j);
			while(q1.front().first!=-1)
			{
				i=q1.front().first;
				j=q1.front().second;
				//cout<<"i="<<i<<" and j="<<j<<"\n";
				if(a[i][j]==1)
				temp=abs(x-i)+abs(y-j);
				if(temp<res) res=temp;
				//cout<<"i="<<i<<" and j="<<j<<" res="<<res<<" and x="<<x<<" and y="<<y<<"\n";
				q1.pop();
			}
			return res;
		}
		else
		{
			s1.insert(i*n+j);
			q1.pop();
			if(i+1<n and s1.count((i+1)*n+j)==0) q1.push(make_pair(i+1,j));
			if(j+1<n and s1.count(i*n+j+1)==0) q1.push(make_pair(i,j+1));
			if(i+1<n and (j+1)<m and s1.count((i+1)*n+j+1)==0) q1.push(make_pair(i+1,j+1));
			if(i+1<n and j-1>=0 and s1.count((i+1)*n+j-1)==0) q1.push(make_pair(i+1,j-1));
			if(i-1>=0 and s1.count((i-1)*n+j)==0) q1.push(make_pair(i-1,j));
			if(i-1>=0 and j+1<m and s1.count((i-1)*n+j+1)==0) q1.push(make_pair(i-1,j+1));
			if(j-1>=0 and s1.count((i)*n+j-1)==0) q1.push(make_pair(i,j-1));
			if(i-1>=0 and j-1>=0 and s1.count((i-1)*n+j-1)==0) q1.push(make_pair(i-1,j-1));
			q1.push(make_pair(-1,-1));
		}
	}


}		
		
int main()
{
	int t,i,j,k,temp,res[182][182];
	string str;
	t=getInt();
	char s[183];
	while(t--)
	{
		
		n=getInt();m=getInt();k=0;
		temp=n;
		while(temp--)
		{
			scanf("%s",s);
			for(i=0;i<m;i++)
				a[k][i]=s[i]-'0';
			k++;
		}
		cout<<"a is \n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			cout<<a[i][j]<<" ";
			cout<<"\n";
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]==1)
				res[i][j]=0;
				else res[i][j]=bfs(i,j);
			} 
		}
		cout<<"\n the result is\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printn(res[i][j]);
				putc_unlocked(' ',stdout);
			}
			putc_unlocked('\n',stdout);
		}			
	}
	return 0;
}
