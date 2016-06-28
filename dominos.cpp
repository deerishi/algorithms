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
int N,M,componentNumber;
unordered_map<int,int> vertice_componentNumber,component1_to_component2;
vector<int> edges[100005],edgesReversed[100005],componentsInCycle,componentElements[100005];
bool visited1[100005],visited2[100005];
int indegree[100005];
stack<int> pass1;
int result;

void resetParameters();
void dfsPass1(int domino);
void dfsPass2(int domino);
void findConnectedComponents();
void printResult();
void findInDegreeOfComponentgraph();



void resetParameters()
{
    int i,j,k;
    componentNumber=1;
    result=0;
    For(i,1,N)
    {
        visited1[i]=false;
        visited2[i]=false;
        edges[i].clear();
        edgesReversed[i].clear();
        indegree[i]=0;
    }

}

void dfsPass1(int domino)
{
    if(visited1[domino]==true)
    {
        return;
    }
    visited1[domino]=true;
    vector<int>::iterator it;
    ForIter(it,edges[domino])
    {
        if(!visited1[*it])
        {
            dfsPass1(*it);
        }
    }
    pass1.push(domino);
}

void dfsPass2(int domino)
{
    if(visited2[domino]==true)
    {
        return;
    }
    visited2[domino]=true;
    componentsInCycle.push_back(domino);
    vector<int>::iterator it;
    ForIter(it,edgesReversed[domino])
    {
        if(!visited2[*it])
        {
            dfsPass2(*it);
        }
    }
}


void findInDegreeOfComponentgraph()
{
    vector<int>::iterator it;
    int i,j,k;
    For(i,1,N)
    {
        ForIter(it,edges[i])
        {
            if(vertice_componentNumber[i]!=vertice_componentNumber[*it])
            {
                indegree[vertice_componentNumber[*it]]++;
            }
        }
        
    }
}

void findConnectedComponents()
{
    int i,j,k;
    //first dfsPass1
    For(i,1,N)
    {
        dfsPass1(i);
    }
    //now reverse the graph
    vector<int>::iterator it;
    For(i,1,N)
    {
        ForIter(it,edges[i])
        {
            edgesReversed[*it].push_back(i);
        }
    }
    int top;
    //now call the second dfs on the order of vertioces stired
    while(!pass1.empty())
    {
        top=pass1.top();
        pass1.pop();
        if(visited2[top]==true)
        {
            continue;
        }
        componentsInCycle.clear();
        dfsPass2(top);
        ForIter(it,componentsInCycle)
        {
            vertice_componentNumber[*it]=componentNumber;
            componentElements[componentNumber].push_back(*it);
        }
        componentNumber++;
    }
    
    findInDegreeOfComponentgraph();
    For(i,1,componentNumber-1)
    {
        if(indegree[i]==0)
        {
            result++;
        }
    }
}



void printResult()
{
    printn(result);
}

int main()
{
    int t=getInt();
    int i,j,k,x,y;
    while(t--)
    {
        N=getInt();
        M=getInt();
        resetParameters();
        For(i,1,M)
        {
            x=getInt();
            y=getInt();
            edges[x].push_back(y);
            //indegree[y]++;
        }
        findConnectedComponents();
        printResult();
        blank;
    }
    
}
