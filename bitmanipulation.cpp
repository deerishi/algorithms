
#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);

typedef long long int ll;
int getInt()
{
    ch=getc_unlocked(stdin);
    while(ch<'-')
    {
        ch=getc_unlocked(stdin);
    }
    int sign=1,num=0;
    if(ch=='-')
    {
        sign=-1;ch=getc_unlocked(stdin);
    }
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getc_unlocked(stdin);
    }
    return num*sign;
    
}

void printn(ll n) 
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

int arr[11][11];
ll dp[11][2048];

int main()
{
    int C=getInt();
    int i,j,k,player,index;
    ll temp;

    while(C--)
    {
        
        memset(dp,0,sizeof(dp));

        for(i=0;i<11;i++)
        {
            for(j=0;j<11;j++)
            {
                arr[i][j]=-1*getInt();
                //cout<<"arr[i][j] is "<<arr[i][j]<<"\n";
            }
        }
        // Fill the 1st row of the dp table which is just for the first and only position and hence it is just the max of the score of tyhe players.  
        for(i=0;i<11;i++)
        {
            for(j=1;j<2048;j++)
            {
                player=j;
                dp[i][j]=0;
                index=0;
                if(i==0)
                {
                    dp[i][j]=INT_MAX;
                    while(player>0)
                    {
                        //here we iterate over all the possible players in the subset
       +
       
       
       
                        cout<<"player is "<<player<<" and player&1 is "<<(player&1)<<"arr["<<index<<"]["<<i<<"] is "<<arr[index][i]<<"\n";
                        if((player&1==1) and arr[index][i] < dp[i][j] and arr[index][i]!=0)
                        {
                            dp[i][j]=arr[index][i];
                        }
                        cout<<"player is "<<player<<" and player&1 is "<<(player&1)<<"arr["<<index<<"]["<<i<<"] is "<<arr[index][i]<<" and dp[i][j] is "<<dp[i][j]<<"\n";
                        player=player>>1;
                        index++;
                    }
                }
                else
                {
                    //here too we iterate over all the players in the subset but with the following recursive rule
                    //dp[i][j]=min(arr[index][i]+dp[i-1][the subset just not including player j]). by taking the min we can disregard the not incluing the zero rule
                    temp=INT_MAX;
                    while(player>0)
                    {
                        if((player & 1)==1 and arr[index][i]!=0)
                        {
                            temp=min(arr[index][i]+dp[i-1][j&(~(1<<index))],temp);//ll the playsers except he index one)
                        }
                        player=player>>1;
                        index++;
                    }
                    dp[i][j]=temp;
                }
            }
        }
        printf("%lld\n",(-1*dp[10][2047]));
    }
    
    return 0;
    
}
