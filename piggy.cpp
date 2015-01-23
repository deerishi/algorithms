#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
class Piggy
{
	int E,F,N,weight[501][1000],data[501][2],min1;
	vector<int> v1[501];
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
	//scanf("%d",&E);
	//scanf("%d",&F);
	//scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++)
	{
		data[i][0]=getInt();// P ,value of coin
		data[i][1]=getInt(); // W, weight of coin
	}
	for(i=0;i<=N;i++) v1[i].clear(); 
	for(i=0;i<=(F-E);i++)
	v1[0].push_back(INT_MAX);
	
	for(i=1;i<=N;i++)
	v1[i].push_back(INT_MAX);
	vector<int>::iterator it1=v1[0].begin(),it2=v1[0].begin(),it3=it2=v1[0].begin();
	min1=INT_MAX;
	for(i=1;i<=N;i++)
	{
		//cout<<"data "<<i<<" is "<<data[i][1]<<"\n";
		for(j=1;j<=(F-E);j++)
		{
			if(data[i][1]<=j)
			{
				it1=v1[i-1].begin() +j;
				it2=v1[i-1].begin()+j%data[i][1];
				//cout<<"it1 = "<<*it1<<" it2 is "<<*it2<<"\n";
				if(j%data[i][1]==0 and (data[i][0]*(j/data[i][1]))<*it1)
				{
					v1[i].push_back(data[i][0]*(j/data[i][1]));
				}
				else if(j%data[i][1]!=0 and *it2!=INT_MAX and (*it2 + (data[i][0]*(j/data[i][1])))<*it1)
				{
					v1[i].push_back((data[i][0]*(j/data[i][1]))+*it2);
				}
				else
				{
					v1[i].push_back(*it1);
				}
			}
			else
			{
				v1[i].push_back(*it1);
			}
		}
		it3=v1[i].begin()+F-E;
		if(*it3<min1) min1=*it3;
	}
	
	/*for(i=0;i<=N;i++)
	{
		for(j=0;j<=(F-E);j++)
		{
			it3=v1[i].begin()+j;
			if(*it3==INT_MAX)  cout<<"N ";
			else cout<<*it3<<" ";
		}
		cout<<"\n";
	}*/
	return min1;
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
			
		
