#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
#define mod 5000000
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
vector<vector<int> > dp;
int max1;
vector<int> nums,arr;
void resetTree()
{
    fill(nums.begin(),nums.end(),0);
}

void update(int start,int end,int node,int rangeToUpdate,int val)
{
    if(rangeToUpdate<start or rangeToUpdate>end)
    {
        return;
    }
    if(start==end and start==rangeToUpdate)
    {
        nums[node]+=val;
        nums[node]%=mod;
        return;
    }
    int mid=(start+end)/2;
    update(start,mid,2*node,rangeToUpdate,val);
    update(mid+1,end,2*node+1,rangeToUpdate,val);
    nums[node]=(nums[2*node]+nums[2*node+1])%mod;
}

int query(int start,int end,int node,int x,int y)
{
    if(x>end or y<start)
    {
        return -1;
    }
    if(start>=x and end<=y)
    {
        return nums[node];
    }
    int mid=(start+end)/2;
    int left=query(start,mid,2*node,x,y);
    int right=query(mid+1,end,2*node+1,x,y);
    if(left==-1)
    {
        return right%mod;
    }
    else if(right==-1)
    {
        return left%mod;
    }
    else
    {
        return (left%mod+right%mod)%mod;
    }
}

int main()
{
    int i,j,k,p,n,x;
    n=getInt();
    k=getInt();
    
    max1=INT_MIN;
    For(i,0,n)
    {
        x=getInt();
        //x=x%mod;
        if(x>max1)
        {
            max1=x;
        }
        arr.push_back(x);
    }
    For(i,0,n)
    {
        dp.push_back(vector<int>());
        Forall(p,0,k)
        {
            if(p==1)
            {
                dp[i].push_back(1);
            }
            else
            {
                dp[i].push_back(0);
            }
        }
    }
    Forall(i,0,4*max1+2)
    {
        nums.push_back(0);
    }
    Forall(p,2,k)
    {
        if(p!=2)
        {
            resetTree();
        }
        For(i,1,n)
        {
            //nums[arr[i-1]]+=dp[i-1][p-1];
            update(0,max1,1,arr[i-1],dp[i-1][p-1]);
            if(arr[i]==0)
            {
                dp[i][p]=dp[i][p];
            }
            else
            {
                int sum1=query(0,max1,1,0,arr[i]-1);
                dp[i][p]=(dp[i][p]%mod+sum1%mod)%mod;
                dp[i][p]%=mod;
            }
            
        }
    }
    
    /*cout<<"\n the dp table is \n";
    For(i,0,n)
    {
        Forall(j,1,k)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int res=0;
    For(i,0,n)
    {
        res=(res+dp[i][k])%mod;
    }
    //cout<<"\n the res is ";
    printn(res);
    blank;
}
