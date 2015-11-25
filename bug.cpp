#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;

//Here we check if the graph is bipartite or not by coloring it using BFS as the criteria
#define blank putc_unlocked('\n',stdout);
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
int num;    
int adj[2001][2001];
int bugColor[2001]; //this will store the color
int visited[2001];
queue<int> que;

bool bfs()
{
int i=0;
    while(!que.empty())
    {   
        int n=que.front();
        que.pop();
        visited[n]=1;
        for(i=1;i<=num;i++)
        {
            if(adj[n][i]==1) //means there is a connection
            {
                if(bugColor[i]==bugColor[n])
                {
                    return false;
                }
                else if(bugColor[i]==0)
                {
                    (bugColor[n]==1)?(bugColor[i]=2):(bugColor[i]=1);
                }
                if(visited[i]==0)
                {
                    que.push(i);
                }
            }   
        }   
    }
    return true;
    
}

int main()
{
    int t,i,b1,b2,j,m,num2;
    bool res;
    t=getInt();
    for(m=1;m<=t;m++)
    {
        num=getInt();
        num2=getInt();
        for(i=1;i<=num;i++)
        {
            bugColor[i]=0;
            visited[i]=0;
            for(j=i;j<=num;j++)
            {
                adj[i][j]=0;
                 adj[j][i]=0;

                
            }
            
        }
        for(i=1;i<=num2;i++)
        {
            b1=getInt();
            b2=getInt();
            //cout<<"b1 "<<b1<<" b2 "<<b2<"\n";
            adj[b1][b2]=1;
            
            adj[b2][b1]=1;

        }
        
        for(j=1;j<=num;j++)
        {
            if(visited[j]==0)
            {
                bugColor[j]=1;
                que.push(j);
                res=bfs();
                if(!res)
                {
                     break;
                }
            }
        }
        if(res)
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n",m);
        }
        else
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n",m);
        }
        while(!que.empty())
        {
            que.pop();
        }
    }
}
