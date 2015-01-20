#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
#define pre 1
#define in 2
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
int compare(const void * aa,const void* bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	if(a[0]<b[0]) 
	return -1;
	else if(a[0]==b[0])
	return 0;
	else
	return 1;
}
 	
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
class Party
{
	public:
    int party[100][2],max_budget,party_size,amt;
    vector<int> v1[100];
    
        int knapsack();
        void getInput();
        int budget();
};

void Party:: getInput()
{
    int i;
    for(i=0;i<(this->party_size);i++)
    {
        party[i][0]=getInt();
        party[i][1]=getInt();
    }
}
int Party:: knapsack()
{
    int i,j;
    qsort(party,party_size,sizeof(party[0]),compare);
    vector<int>:: iterator it1,it2,it3;
   // cout<<"\n in knapsack\n";
    for(i=0;i<=party_size;i++)
    {
    	v1[i].clear();
    	v1[i].push_back(0);
    }
    	
    for(i=0;i<=max_budget;i++)
    v1[0].push_back(0);
    
   // cout<<"\n party_size is "<<party_size<<" and max_bugdet is "<<max_budget<<"\n";
    for(i=1;i<=party_size;i++)
    {
    	
    	it2=v1[i-1].begin();
    	it3=it2;
        for(j=1;j<=max_budget;j++)
        {
        	it3=v1[i-1].begin()+j;
        	if(j>=party[i-1][0])
        	{
        		it2=v1[i-1].begin()+j-party[i-1][0];
        		
        		//cout<<"\n i "<<i<<" j= "<<j<<" party[i-1][1]= "<<party[i-1][1]<<" and it2= "<<*it2<<" and it3= "<<*it3;
        	
          		if( ((*it2) + party[i-1][1])>(*it3))
            	{
            		//cout<<" pushing "<<(*it2) +party[i-1][1]<<"\n";
            		v1[i].push_back((*it2) +party[i-1][1]);
           	 	}
           	 	else
            	{
            		v1[i].push_back((*it3));
            	}
            }
            else
            {
            	v1[i].push_back((*it3));
            }
         }
        // cout<<"\n i= "<<i<<" and vector["<<i<<"] is \n";
        /* for(it1=v1[i].begin();it1!=v1[i].end();it1++)
         cout<<*it1<<" ";
         cout<<"\n";*/

     }
     it1=v1[party_size].begin()+max_budget;
     return *it1;            
}
int Party:: budget()
{
	int i=party_size,j=max_budget;
	amt=0;
	vector<int>:: iterator it1,it2;
	//cout<<"\n in budget i="<<i<<" j= "<<j<<"\n";
	while(i!=0 and j!=0)
	{
		it1=v1[i].begin() + j;
		it2=v1[i-1].begin()+j;

		if(*it1!= *it2)
		{
			amt+=party[i-1][0];
			//cout<<"\n party[i="<<i<<"][j="<<j<<"] is "<<party[i-1][0]<<"\n";
			j=j-party[i-1][0];
			i=i-1;
		}
		else
		i=i-1;
	}
	return amt;
	for(i=0;i<=party_size;i++)
	v1[i].clear();
}
int main()
{
    Party p;
    p.max_budget=getInt();
    p.party_size=getInt();
    int i,j,res1,res2;
    vector<int>:: iterator it;
    while(p.max_budget!=0 or p.party_size!=0)
    {
        p.getInput();
    	res1=p.knapsack();
    	 /*for(i=0;i<=p.party_size;i++)
    	{	
    		it=p.v1[i].begin();
    		//cout<<" for i= "<<i<<"\n";
       	 	for(j=0;j<=p.max_budget;j++)
        	{
        		it+=j;
        		printn(*it);
        		putc_unlocked(' ',stdout);
        	}
       		 putc_unlocked('\n',stdout);
    	}*/
   		res2=p.budget();
   		printn(res2);putc_unlocked(' ',stdout);
   		printn(res1);blank;
   		getc_unlocked(stdin);
        p.max_budget=getInt();
    	p.party_size=getInt();
    }
    
    return 0;
}
     
    	
