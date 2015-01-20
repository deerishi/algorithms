#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
class Party
{
	public:
	int amt,max_budget,party_size,party[101][2];
	int parties[101][502];
	void getInput();
	friend int getInt();
	friend int printn();
	int knapsack();

};
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
void Party:: getInput()
{
	int i,j;
	//cout<<" in inp\n";
	for(i=1;i<=party_size;i++)
	{
		party[i][0]=getInt(); //entrance fees to a party
		party[i][1]=getInt(); //fun at party
	}
}
int Party:: knapsack()
{
	int i,j;
	for(i=0;i<=party_size;i++)
	parties[i][0]=0;
	for(i=0;i<=max_budget;i++)
	parties[0][i]=0;
	for(i=1;i<=party_size;i++)
	{
		for(j=0;j<=max_budget;j++)
		{
			if(j>=party[i][0])
			{
				//cout<<"j="<<j<<" and party[i][0]="<<party[i][0]<<" prev val="<<parties[i-1][j]<<" and new val "<<party[i][1]+ parties[i-1][j-party[i][0]]<<"\n";
				parties[i][j]=max(parties[i-1][j],party[i][1]+ parties[i-1][j-party[i][0]]);
			}
			else
				parties[i][j]=parties[i-1][j];
		}
	}
//	cout<<"\n the mat is \n";
	/*for(i=0;i<=party_size;i++)
	{
		for(j=0;j<=max_budget;j++)
		{
			cout<<parties[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	for(i=0;i<=max_budget;i++)
	{
		if(parties[party_size][i]==parties[party_size][max_budget])
		{	
			amt=i;
			//cout<<"i = "<<i<<"\n";
			break;
		}
	}
	return parties[party_size][max_budget];
}	
		 
int main()
{
	int res1,res2,i,j;
	Party p;
	char ch;
	p.max_budget=getInt();
	p.party_size=getInt();
	while(p.party_size!=0 or p.max_budget!=0)
	{
		//cout<<"starting budget= "<<p.max_budget<<" and size= "<<p.party_size<<"\n"; 
		p.getInput();
		res1=p.knapsack();
		printn(p.amt);putc_unlocked(' ',stdout);
		printn(res1);blank;
		ch=getc_unlocked(stdin);
		p.max_budget=getInt();
		p.party_size=getInt();
		//cout<<"size ="<<p.party_size<<" and bud = "<<p.max_budget<<"\n";
	}
	return 0;
}
