#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
char current[1<<10],ch;
//This is lexicographical topological sort
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
	ptr++;

	while(*ptr!='\0')
	{
		putc_unlocked(*ptr++,stdout);
	}
}

vector<int> pages[100005],pagesReversed[100005];
int N,M;
stack<int> Pass1;
bool visited1[100005],visited2[100005];

void dfsPass1(int page)
{
    vector<int>::iterator it;
    int i,j;
    visited1[page]=true;
    for(it=pages[page].begin();it!=pages[page].end();it++)
    {
        if(visited1[i]==true)
        {
            continue;   
        }
        dfsPass1(*it);
    }
    Pass1.push(page);
}

void findConnectedComponents()
{
    //Do the first global Dfs Pass.So, in this case dfs is a post order traversal
    int i;
    for(i=0;i<N;i++)
    {
        if(visited1[i]==true)
        {
            continue;
        }
        dfsPass1(i);
    }
    
    //Now we need to reverse the graph
    vector<int>::iterator it;
    for(i=0;i<N;i++)
    {
        for(it=pages[i].begin();it!=pages[i].end();it++)
        {
            pagesReversed[*it].push_back(i);
        }
    }
    //graph reversed
    //Now traverse the graph in the 
}

int main()
{
    int i,j,x,y;
    N=getInt();
    M=getInt();
    for(i=0;i<M;i++)
    {
        x=getInt();
        y=getInt();
        pages[x].push_back(y)
    }
    for(i=0;i<N;i++)
    {
       visited1[i]=false;
       visited2[i]=false; 
    }
    
    return 0;
}
