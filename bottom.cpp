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
void resetParameters();
void dfsPass1(int node);
void dfsPass2(int node);
void findConnectedComponents();
void printResult();
bool isValidConnectedComponent();

stack<int> pass1;
int outDegree[5005];
vector<int> edges[5005],edgesReversed[5005],result,componentsInCycle,connectedComponents[5005],componentGraph[5005];

int V,E,N;
unordered_map<int,int> vertice_componentNumber,component1_to_component2;

bool visited1[5005],visited2[5005];

bool compare(int a,int b)
{
    return a<b;
}

void resetParameters()
{
    int i,j;
    vertice_componentNumber.clear();
    component1_to_component2.clear();
    
    for(i=1;i<=V;i++)
    {
        outDegree[i]=0;
        
        visited1[i]=false;
        visited2[i]=false;
        edges[i].clear();
        edgesReversed[i].clear();

    }
    result.clear();
}

void findConnectedComponents()
{
    //First DFS
    int i,j,k;
    For(i,1,V)
    {
        dfsPass1(i);
    }
    
    vector<int>::iterator it;
    //Now reverse the graph
    For(i,1,V)
    {
        ForIter(it,edges[i])
        {
            edgesReversed[*it].push_back(i);
        }
    }
    int top;
    //Now pass 2 of DFS and do the traversal in order pst order stored in the stack
    while(!pass1.empty())
    {
        top=pass1.top();
        pass1.pop();
        componentsInCycle.clear();
        if(!visited2[top])
        {
            dfsPass2(top);
        }
        else
        {
            continue;
        }
        //cout<<"componentsInCycle.size()= is "<<componentsInCycle.size()<<" and its a "<<isValidConnectedComponent()<<" component"<<"\n";
        if(isValidConnectedComponent())
        {
            ForIter(it,componentsInCycle)
            {
                //cout<<"pushing "<<*it<<" ";
                result.push_back(*it);
            }
            //cout<<"\n\n";
        }
        
    }
}

void dfsPass1(int node)
{
    //cout<<"node is "<<node<<" and visited1[node] is "<<visited1[node]<<"\n";
    if(visited1[node]==true)
    {   
        return;
    }
    visited1[node]=true;
    //cout<<"edges[node].size is "<<edges[node].size()<<"\n"; 
    vector<int>::iterator it;
    ForIter(it,edges[node])
    {
        //cout<<"node is "<<node<<" and it is "<<*it<<"\n";
        if(!visited1[*it])
        {
            dfsPass1(*it);
        }
    }
    //cout<<"pushing on the stack "<<node<<"\n";
    pass1.push(node);
}

void dfsPass2(int node)
{
    if(visited2[node]==true)
    {
        return;
    }
    visited2[node]=true;
    //cout<<"in componentGraph pushing "<<node<<"\n";
    componentsInCycle.push_back(node);
    vector<int>::iterator it;
    ForIter(it,edgesReversed[node])
    {
        if(!visited2[*it])
        {
            dfsPass2(*it);
        }
    }
}
void printResult()
{
    int i;
    //cout<<"result.size is "<<result.size()<<"\n";
    if(result.size()!=0)
    {
        For(i,0,result.size()-1)
        {
            //cout<<"i is "<<i<<"\n";
            printn(result[i]);
            putc_unlocked(' ',stdout);
        }
    }
}

bool isValidConnectedComponent()
{
    unordered_map<int,bool> map1;
    unordered_map<int,bool>::iterator it;
    int i,j;
    vector<int>::iterator it2,it3;
    if(componentsInCycle.size()>0)
    {
        ForIter(it2,componentsInCycle)
        {
            map1[*it2]=true;
        }
        //now just check if the current SCC has any edge going to any vertex other than the one in the cycle
        ForIter(it2,componentsInCycle)
        {
            ForIter(it3,edges[*it2])
            {
                //cout<<*it2<<" -> "<<*it3<<" and map1["<<*it3<<"] is "<<map1[*it3]<<"\n";
                if(map1.find(*it3)==map1.end())
                {
                    return false;
                }
            }
        }
        return true;
    }
    else if(componentsInCycle.size()==1)
    {
        if(outDegree[*(componentsInCycle.begin())]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    int i,j,k,x,y;
    while(1)
    {
        resetParameters();
        V=getInt();
        if(V==0)
        {
            return 0;
        }
        E=getInt();
        For(i,1,E)
        {
            
            x=getInt();
            y=getInt();
            //cout<<"x= "<<x<<" y is "<<y<<"\n";
            edges[x].push_back(y);
            //cout<<"edges["<<x<<"].size is "<<edges[x].size()<<"\n"; 
            outDegree[x]++;
        }
        findConnectedComponents();
        sort(result.begin(),result.end());
        printResult();
        
        blank;
    }
    return 0;
}
