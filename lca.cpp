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

int arr[1001][1001];
int eulerpath[4002];
int levels[4002],firstOccurance[4001];
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

int counter=1,N;
void makeEulerPath(int node,int Parent,int level)
{
    int i,j,k;
    eulerpath[counter++]=node;
    levels[counter-1]=level;
   // cout<<node<<" ";
    if(firstOccurance[node]==-1)
    {
        firstOccurance[node]=counter;
    }
    if(numberOfChildren[node]==0)
    {
        //add the parent to the euler path
        eulerpath[counter++]=Parent;
        levels[counter-1]=level-1;
        //cout<<Parent<<" ";
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
        //cout<<Parent<<" ";
    }
    return;
}

int segmentTree[4050];

int makeSegmentTree(int begin,int end,int nodeNum)
{
    if(begin>end)
    {
        return -1;
    }
    
    if(begin==end)
    {
        segmentTree[nodeNum]=begin;
        return 0;
    }
    int mid=(begin+end)/2;
    int left=makeSegmentTree(begin,mid,2*nodeNum);
    int right=makeSegmentTree(mid+1,end,2*nodeNum+1);
    
    if(left==-1)
    {
        segmentTree[nodeNum]=segmentTree[2*nodeNum+1];

    }
    else if(right==-1)
    {
        segmentTree[nodeNum]=segmentTree[2*nodeNum];

    }
    else if(levels[segmentTree[2*nodeNum]] < levels[segmentTree[2*nodeNum+1]])
    {
        segmentTree[nodeNum]=segmentTree[2*nodeNum];
    }
    else
    {
        segmentTree[nodeNum]=segmentTree[2*nodeNum+1];
    }
    //cout<<"\n left = "<<left<<" right= "<<right<<"\n";
    //cout<<"begin="<<begin<<" end = "<<end<<" and segmentTree["<<nodeNum<<"] is "<<segmentTree[nodeNum]<<"\n";
    return 0;
}

int RMQ(int begin,int end,int i ,int j,int node)
{
    //1) Check if the i and j are in the range or not
    //cout<<"begin= "<<begin<<" end "<<end<<" levels["<<node<<"] is "<<levels[node]<<"\n";
    if(i>end or j<begin or begin>end)
    {
        return -1;
    } 
    if(begin>=i and end<=j)
    {
        return segmentTree[node];
    }
    int mid=(begin+end)/2;
    int left=RMQ(begin,mid,i,j,2*node);
    int right=RMQ(mid+1,end,i,j,2*node+1);
    
    if(left==-1)
    {
        return right;
    }
    if(right==-1)
    {
        return left;
    }
    if(levels[left]< levels[right])
    {
        return left;
    }
    else
    {
        return right;
    }
}

void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int t=getInt(),i,j,M,Q,x,y,xf,yf,rmq;
    int ml=1;
    while(t--)
    {
        N=getInt();

        for(i=1;i<=N;i++)
        {
            M=getInt();
            numberOfChildren[i]=M;
            for(j=0;j<M;j++)
            {
               
                //arr[j][i]=1;
                nodesNChildNodes[i].insert(getInt()); //this stores the children of a node
            }
            //Now we have made the adjacency matrix
            
            //Steps to do the preprocessing for reducing the LCA Problem to RMQ
            //1)Find the euler tour or the DFS ORDER
            firstOccurance[i]=-1;
            
        }
        makeEulerPath(1,0,0);
        //Now since we have made the euler path, we need to store the levels and the first position of the node in the euler path
         /*cout<<"\nNow printing the levels\n";
         for(i=1;i<counter;i++)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
        for(i=1;i<counter;i++)
        {
            cout<<levels[i]<<" ";
        }
        cout<<"\nnow printing the first occurance\n";
        for(i=1;i<=N;i++)
        {
            cout<<firstOccurance[i]<<" ";
        }*/
        makeSegmentTree(1,N,1);
        Q=getInt();
        printf("Case :%d\n",ml++);
        for(i=0;i<Q;i++)
        {
            x=getInt();
            y=getInt();
            xf= firstOccurance[x];
            yf= firstOccurance[y];
            //Now we need to do a RMQ on xf and yf to find the LCA INDEX IN THE EULER PATH
            if(xf>yf)
                swap(xf,yf);
            rmq=RMQ(1,N,xf,yf,1);
            //cout<<"\n x is "<<x<<" and y is "<<y<<"\n";
            //cout<<"\n rmq is "<<rmq<<"\n";
            //cout<<"\n the lca is ";
            
            printn(eulerpath[rmq]);
            blank;            
        }
    }
    return 0;
}
