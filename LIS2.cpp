#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
#define forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)


int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//cout<<" in while 2 with ch as "<<ch; 
		n=n*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n*sign; 
}
void printn(long n) 
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
vector<pair<int,int> > pairs;
int N;

class Order
{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
            return (a.first<b.first and a.second<b.second);
        }
};


int findLIS(vector<pair<int,int> >& pairs)
{
    int i,j,k;
    vector<int> parents(N);
    set<pair<int,int>,Order> lis;
    
    For(i,0,N)
    {
        if(i>=0)
        {
            parents[i]=i;
            lis.insert(pairs[i]);
            //continue;
        }
    }
    set<pair<int,int>,Order>::iterator it;
    for(it=lis.begin();it!=lis.end();it++)
    {
        cout<<(*it).first<<","<<(*it).second<<"\n";
    }
    return 0;
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>N;
    int i,j,k,x,y;
    for(i=0;i<N;i++)
    {
        cin>>x>>y;
        pairs.push_back(make_pair(x,y));
    }
    findLIS(pairs);
    return 0;
}
