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
		

void 		
		
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
int arr[1001][1001];
int eulerpath[2002];
int levels[2002],firstOccurance[1001];
unordered_map<int,bool> visited;
unordered_map<int,int> numberOfChildren;

unordered_map<int,set<int>> nodesNChildNodes;

void resetVariables(int N)
{
    int i,j;
    for(i=0;i<N;i++)
    {
       //write later
    }    
}
int counter=0,N;
void makeEulerPath(int node,int Parent,int level)
{
    int i,j,k;
    eulerpath[counter++]=node;
    levels[counter-1]=level;
    cout<<node<<" ";
    if(numberOfChildren[node]==0)
    {
        //add the parent to the euler path
        eulerpath[counter++]=Parent;
        levels[counter-1]=level-1;
        cout<<Parent<<" ";
        return;
    }
    set<int>:: iterator it;
    for(it=nodesNChildNodes[node].begin();it!=nodesNChildNodes[node].end();it++)
    {
         makeEulerPath(*it,node,level+1);
    }
    if(Parent!=0)
    {
        
        eulerpath[counter++]=Parent;
        levels[counter-1]=level-1;
        cout<<Parent<<" ";
    }
    return;
}

int main()
{
    int t=getInt(),i,j,M;
    
    while(t--)
    {
        N=getInt();
        resetVariables(N);
        for(i=1;i<=N;i++)
        {
            M=getInt();
            numberOfChildren[i]=M;
            for(j=0;j<M;j++)
            {
                arr[i][j]=1;
                //arr[j][i]=1;
                nodesNChildNodes[i].insert(getInt()); //this stores the children of a node
            }
            //Now we have made the adjacency matrix
            
            //Steps to do the preprocessing for reducing the LCA Problem to RMQ
            //1)Find the euler tour or the DFS ORDER
            
        }
        makeEulerPath(1,0,0);
        //Now since we have made the euler path, we need to store the levels and the first position of the node in the euler path
        cout<<"\nNOw printing the levels\n";
        for(i=0;i<counter;i++)
        {
            cout<<levels[i]<<" ";
        }
    }
    return 0;
}
