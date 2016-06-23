#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)

char current[1<<10],ch;
//This is lexicographical topological sort
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
set<int> listOfVerticesProcessed;
int result[100005];


void dfsPass1(int page)
{
    vector<int>::iterator it;
    int i,j;
    //cout<<" in pass 1 for page "<<page<<"\n";
    visited1[page]=true;
    for(it=pages[page].begin();it!=pages[page].end();it++)
    {
        if(visited1[*it]==true)
        {
            continue;   
        }
        //cout<<"calling pass1 for "<<*it<<"\n";
        dfsPass1(*it);
    }
    //cout<<"pushing on stack "<<page<<"\n";
    Pass1.push(page);
}

void dfsPass2(int page)
{
    //cout<<" Processing page in pass2 "<<page<<"\n";
    if(visited2[page]==true)
    {
        return;
    }
    visited2[page]=true;
    listOfVerticesProcessed.insert(page);
    vector<int>::iterator it;
    ForIter(it,pagesReversed[page])
    {
        dfsPass2(*it);
    }

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
    //Now traverse the graph in the order you have kept the vertices in the stack
    set<int>::iterator it2;
    int min1;
    while(!Pass1.empty())
    {
        if(visited2[Pass1.top()]==true)
        {
            Pass1.pop();
            continue;
        }
        listOfVerticesProcessed.clear();
        dfsPass2(Pass1.top());
        
        min1=*(listOfVerticesProcessed.begin());
        //cout<<"for page "<<Pass1.top()<<" min1 is "<<min1<<"\n";
        ForIter(it2,listOfVerticesProcessed)
        {
            result[*it2]=min1;
        }
        
        Pass1.pop();
    }
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
        pages[x].push_back(y);
    }
    for(i=0;i<N;i++)
    {
       visited1[i]=false;
       visited2[i]=false; 
    }
    findConnectedComponents();
    for(i=0;i<N;i++)
    {
        printn(result[i]);
        blank;
    }
    return 0;
}
