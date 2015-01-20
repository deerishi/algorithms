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
vector<int> v1[10001];
vector<int>::iterator it;
int visit[10001];
int start=-1;
int find_height(int node)
{
	vector<int>::iterator it;
	visit[node]=1;
	int height=0,temp2;
	for(it=v1[node].begin();it!=v1[node].end() ;it++)
	{
		if(visit[*it]==0)
		{
			cout<<"in find_height calling for "<<*it; 
			temp2=1+find_height(*it);
			if(temp2>height)height=temp2;
		}
	}
	
	cout<<"returning "<<height<<" for "<<node<<"\n";
	return height;
	
}
int main()
{

	int i=0,j,N,e1,e2,temp2;
	memset(visit,0,10001);
	N=getInt();
	while(i<(N-1))
	{
		e1=getInt();
		e2=getInt();
		if(start==-1) start=e1-1;
		v1[e1-1].push_back(e2-1);
		v1[e2-1].push_back(e1-1);
		i++;
	}
	int largest=0,second_largest=0;
	vector<int>::iterator it,it2;
	//cout<<"the vector is \n";
	for(i=0;i<N;i++)
	{
		it2=v1[i].begin();
		for(;it2!=v1[i].end();it2++)
		cout<<" "<<*it2;
		cout<<"\n";
	}
	it=v1[start].begin();
	
	visit[start]=1;
	for(;it!=v1[0].end() ;it++)
	{
		cout<<"*it is "<<*it<<" and visit is "<<visit[*it]<<"\n";
		if(visit[*it]==0)
		{
			cout<<"in main calling for "<<*it<<"\n";
			visit[*it]=1;
			temp2=1+find_height(*it);
			if(temp2>largest) second_largest=largest,largest=temp2;
			else if (second_largest<temp2<=largest) second_largest=temp2;
		}
	}
	//cout<<"\n the largest is "<<largest<<" and second_largest is "<<second_largest<<"\n";
	printn(largest+second_largest);
	blank;		
	return 0;
}
