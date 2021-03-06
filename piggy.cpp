#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
class Piggy
{
	int E,F,N,data[501][2],min1,weight[10010];
	public:
	int run_modified_knapsack();
	friend int getInt();
	friend void printn();

};

int getInt()  
{	
    ch=getc_unlocked(stdin);
    //cout<<" in the beginning with ch as "<<ch;
    while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);}
    int sign=1,n1=0;
    if(ch=='-') sign=-1,ch=getc_unlocked(stdin);
    while(ch>'-')
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

int Piggy::run_modified_knapsack()
{
	E=getInt();
	F=getInt();
	N=getInt();
	int i,j,min_weight=INT_MAX,temp1,temp2,w;
	for(i=1;i<=N;i++)
	{
		data[i][0]=getInt();// P ,value of coin
		data[i][1]=getInt(); // W, weight of coin
		if(data[i][1]<min_weight)
		{
			min_weight=data[i][1];
		}
	}
	for(i=0;i<=min_weight;i++)
	weight[i]=INT_MAX;
	for(i=min_weight;i<=(F-E);i++)
	{
		temp1=INT_MAX;
		temp2=INT_MAX;
		for(j=1;j<=N;j++)
		{
			w=data[j][1];
			if(i>=w)
			{
				if(weight[i-w]!=INT_MAX or i==w) 
				{
					if(i==w) temp2=data[j][0];
					else temp2=data[j][0] + weight[i-w];
				}
			}
			if(temp1>temp2) temp1=temp2;
		}
		if(temp1!=INT_MAX) weight[i]=temp1;
		else weight[i]=INT_MAX;
		
		//cout<<"i= "<<i<<" and weight[i]= "<<weight[i]<<"\n";
		
	}
	return weight[F-E];
}
	
			
					
int main()
{
	int t,min1;
	//scanf("%d",&t);
	t=getInt();
	Piggy pig;
	while(t--)
	{
		min1=pig.run_modified_knapsack();
		if(min1==INT_MAX) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",min1);
	}
	return 0;
}
			
		

