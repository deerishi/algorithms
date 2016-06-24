#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
typedef long long int ll;

ll getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	ll sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//cout<<" in while 2 with ch as "<<ch; 
		n1=n1*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n1*sign; 
}
		
void printn(ll n) 
{
	char *ptr=temp+30;
	*ptr--='\0';
	ll flag=1;
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

ll dp[101][101][50];
int n,moves;
struct boardMoves
{
    int x;
    int  y;
}start,finish;

boardMoves kingKnightMoves[16]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1},{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};
bool isLegalPosition(int x,int y)
{
    if(x>=n or y>=n or x<0 or y<0)
        return false;
    
    return true;
}
ll memoUsed=0;

ll findRes(int currentx,int currenty,int movesLeft)
{
    //cout<<"curently at "<<currentx<<","<<currenty<<" with moves left as "<<movesLeft<<" and dp[currentx][currenty][movesLeft] is "<<dp[currentx][currenty][movesLeft]<<"\n";
    if(dp[currentx][currenty][movesLeft]!=-1)
    {
         memoUsed++;   
        return dp[currentx][currenty][movesLeft];
       
    }
        
    if(start.x==currentx and start.y==currenty and movesLeft==0)
    {
        return 1;
    }
    if( movesLeft<=0)
    {
        return 0;
    }
    //now traverse all the paths 
    int i;
    ll res=0;
    for(i=0;i<16;i++)
    {
        if(isLegalPosition(currentx+kingKnightMoves[i].x,currenty+kingKnightMoves[i].y))
        {
            res+=findRes(currentx+kingKnightMoves[i].x,currenty+kingKnightMoves[i].y,movesLeft-1);
        }
    }
    dp[currentx][currenty][movesLeft]=res;
   // cout<<"finished "<<currentx<<","<<currenty<<" with moves left as "<<movesLeft<<" and dp[currentx][currenty][movesLeft] is "<<dp[currentx][currenty][movesLeft]<<"\n\n";
    return res;
    
}
int main()
{
    int i,j,t,k,m;
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>start.x>>start.y>>finish.x>>finish.y>>moves;
        
        
        memset(dp,-1,sizeof(long long int)*n*n*(moves+1));
        //dp[start.x][start.y][0]=1;
        //Now we are doing a DFS over the paths 
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<moves+1;k++)
                dp[i][j][k]=-1;
            }
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<moves+1;k++)
                cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"] is "<<dp[i][j][k]<<"\n";
            }
        }*/
        cout<<"Working in getting  your result\n";
        ll res=findRes(finish.x,finish.y,moves);
        cout<<"\n res is "<<res<<"\n";
        cout<<"memoUsedis "<<memoUsed<<"\n";
    }
    return 0;
}

