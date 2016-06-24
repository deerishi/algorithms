#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define For(i,start,end) for(i=start;i<=end;i++)
char current[1<<10],ch;
//This is lexicographical topological sort
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//////cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*////cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//////cout<<" in while 2 with ch as "<<ch; 
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
vector<int> nodes[1005],nodesReversed[1005],components[1005],componentGraph[1005];
stack<int> pass1;
bool visited1[1005],visited2[1005];
int n,m;
unordered_map<int,int> vertice_componentNumber,componentNumber_numElements;
vector<int> componentsInCycle;
int degreeOfComponents[1005];
vector<int> result;
int component_vertex[1005][1005];


int componentCounter=1;

void findConnectedComponents();
void dfsPass1(int i);
void dfsPass2(int i);
void resetParameters();

void findConnectedComponents()
{
    //Step 1 , find dfs of the pah and store the post order in a stack
    int i,j,k;
    For(i,1,n)
    {
        if(!visited1[i])
        {
            dfsPass1(i);
        }
    }
    vector<int>::iterator it;
    //Now reverse the graph by building a new graph
    For(i,1,n)
    {
        ForIter(it,nodes[i])
        {
            nodesReversed[*it].push_back(i);
        }
    } 
    
    //now the graph has been reversed
    //now for df2 in the order of vertices stored in the stack
    int node;
    while(!pass1.empty())
    {
        node=pass1.top();
        pass1.pop();
        if(visited2[node]==true)
        {
            continue;
        }
        componentsInCycle.clear();
        dfsPass2(node);
        ForIter(it,componentsInCycle)
        {
            components[componentCounter].push_back(*it);
            vertice_componentNumber[*it]=componentCounter;
        }
        componentCounter++;
        
    }
}

void dfsPass1(int node)
{
    if(visited1[node]==true)
    {
        return;
        
    }
    visited1[node]=true;
    vector<int>::iterator it;
    ForIter(it,nodes[node])
    {
        if(!visited1[*it])
        {
            dfsPass1(*it);
        }
    }
    pass1.push(node);
}

void dfsPass2(int node)
{
    if(visited2[node]==true)
    {
        return;
    }
    visited2[node]=true;
    componentsInCycle.push_back(node);
    vector<int>::iterator it1;
    ForIter(it1,nodesReversed[node])
    {
        if(!visited2[*it1])
        {
            dfsPass2(*it1);
        }
    }
}

void resetParameters()
{
    int i,j,k;
    result.clear();
    componentCounter=1;
    for(i=1;i<=n;i++)
    {
        nodes[i].clear();
        visited1[i]=false;
        visited2[i]=false;
        nodesReversed[i].clear();
        componentGraph[i].clear();
        components[i].clear();
        //memset(component_vertex[i],0,sizeof(int)*n);
        degreeOfComponents[i]=0;
    }
    For(i,1,n)
    {
        For(j,1,n)
        {
             component_vertex[i][j]=0;
        }
    }
}
void printComponentMAtrix()
{
    int i,j;
    For(i,1,n)
    {
        For(j,1,n)
        {
            cout<<component_vertex[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int t,i,j,k,x;
    vector<int>::iterator it;
    
    t=getInt();
    while(t--)
    {
        
        n=getInt();
        For(i,1,n)
        {
            m=getInt();
            for(j=1;j<=m;j++)
            {
                x=getInt();
                nodes[x].push_back(i); //node x can defeat i
            }
        }
        
        findConnectedComponents();
        For(i,1,n)
        {
            ForIter(it,nodes[i])
            {
                //cout<<"i is "<<i<<" it is "<<*it<<"  vertice_componentNumber[i] is "<<vertice_componentNumber[i]<<"  vertice_componentNumber[*it] is "<<vertice_componentNumber[*it]<<"\n";
                //cout<<" component_vertex[vertice_componentNumber[i]][vertice_componentNumber[*it]] is "<< component_vertex[vertice_componentNumber[i]][vertice_componentNumber[*it]]<<"\n";
                if(vertice_componentNumber[i]!=vertice_componentNumber[*it] and component_vertex[vertice_componentNumber[i]][vertice_componentNumber[*it]]==0)
                {
                    //cout<<"in if "<<" vertice_componentNumber[*it] is "<<vertice_componentNumber[*it]<<"\n";
                    component_vertex[vertice_componentNumber[i]][vertice_componentNumber[*it]]=1;
                    degreeOfComponents[vertice_componentNumber[*it]]++;
                    componentGraph[vertice_componentNumber[i]].push_back(vertice_componentNumber[*it]);
                    //cout<<"degreeOfComponents[vertice_componentNumber[*it]] is "<<degreeOfComponents[vertice_componentNumber[*it]]<<"\n";
                }
            }
        }
        
        /*For(i,1,componentCounter-1)
        {
            cout<<"Component "<<i<<" : "<<" with degree "<<degreeOfComponents[i]<<"\n";
            ForIter(it,components[i])
            {
                cout<<*it<<" ";

            }
            cout<<"\n";
        }
        cout<<"\n\ng\n";*/
        
        For(i,1,componentCounter-1)
        {
            //cout<<"i is "<<i<<" with degree "<<degreeOfComponents[i]<<"\n";
            if(degreeOfComponents[i]==0)
            {
                result.push_back(i);
            }
        }
        
        //printComponentMAtrix();
        //cout<<"the result is\n";
        if(result.size()>1)
        {
            printn(0);blank;
        }
        else if(result.size()==1)
        {
            int res=*(result.begin());
            printn(components[res].size());
            blank;
        }
        
        resetParameters();
    }
    
    
    return 0;
}
    
