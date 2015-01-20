#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;

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

class AvoidRoads
{
	public:
		long numWays(int width, int height, vector<string> bad);
		int check_bad(int i1,int j1,int i2,int j2,vector<string> bad);
};
int AvoidRoads::check_bad(int i1,int j1,int i2,int j2,vector<string> bad)
{
	int i,p1,p2,p3,p4;char str[100];
	cout<<"\n size is "<<sizeof(bad)/sizeof(bad[0]);
	vector<string>:: iterator it=bad.begin();
	//cout<<"\nstr is "<<*it;
	for(it=bad.begin();it!=bad.end();it++)
	{
		strcpy(str,(*it).c_str());
		cout<<"\n bad["<<i<<"] is "<<bad[i];
		sscanf(str,"%d%d%d%d",&p1,&p2,&p3,&p4);
		cout<<"\n i1="<<i1<<" j1="<<j1<<" i2="<<i2<<" j2="<<j2;
		cout<<"\n p1="<<p1<<" p2="<<p2<<" p3="<<p3<<" p4="<<p4;
		if(((i1==p1 and j1==p2) and (i2==p3 and j2==p4)) or ((i1==p3 and j1==p4) and (i2==p1 and j2==p2)))
		{
			cout<<"\n return 1";
			return 1;
		}
	} 
	cout<<"\n return 0";
	return 0;
}
long AvoidRoads::numWays(int width, int height, vector<string> bad)
{
	int i,j,p1,p2,p3,p4,is_bad,k;
	char str[100];
	
	long DP[100][100];
	for(i=0;i<=width;i++)
		for(j=0;j<=height;j++)
			DP[i][j]=-1;
	//DP[0][0]=1;
	for(i=0;i<=width;i++)
	{
		for(j=0;j<=height;j++)
		{
			(i==0 and j==0)?DP[i][j]=1:DP[i][j]=0;
			if(i==0 && j==0) continue;
			cout<<"\n currently i="<<i<<" and j="<<j<<" and DP[i][j]="<<DP[i][j]<<"\n";
			
				if((i-1)>=0)
				{
					is_bad=check_bad(i,j,i-1,j,bad);
					if(is_bad==0 and DP[i-1][j]!=-1)
					{
						DP[i][j]+=DP[i-1][j];
						cout<<"\n in 1(i-1) i="<<i<<" j="<<j<<" DP[i][j]="<<DP[i][j];	
					}
				}

				
				if((j-1)>=0)
				{
					is_bad=check_bad(i,j,i,j-1,bad);
					if(is_bad==0 and DP[i][j-1]!=-1)
					{
						DP[i][j]+=DP[i][j-1];
						cout<<"\n in 4 (j-1) i="<<i<<" j="<<j<<" DP[i][j]="<<DP[i][j];	
					}		
				}
		
		}
	}
	cout<<"\n the result is "<<DP[width-1][height-1]<<"\n";
	return DP[width][height];
}		
				 
int main()
{	
	AvoidRoads ob1;
	vector<string> s;
	s.clear();
	 s.push_back("20 13 21 13");s.push_back( "13 21 13 20");s.push_back( "0 20 0 21");s.push_back( "5 17 6 17");s.push_back( "6 23 5 23");s.push_back( "23 7 23 8");s.push_back( "11 24 12 24");s.push_back( "1 12 2 12");s.push_back( "6 20 6 19");s.push_back( "17 10 17 11");s.push_back( "8 2 8 3");s.push_back( "6 17 6 16");s.push_back( "17 20 17 21");s.push_back( "12 15 11 15");s.push_back( "21 0 22 0");s.push_back( "17 8 17 9");s.push_back( "21 1 21 0");s.push_back( "13 21 13 22");s.push_back( "22 12 22 13");s.push_back( "19 1 20 1");s.push_back( "13 4 14 4");s.push_back( "13 6 13 5");s.push_back( "6 4 7 4");s.push_back( "10 19 11 19");s.push_back( "11 7 12 7");s.push_back( "10 8 10 9");s.push_back( "4 20 4 19");s.push_back( "21 10 20 10");s.push_back( "3 15 3 16");s.push_back( "1 20 1 21");s.push_back( "7 13 7 14");s.push_back( "24 1 24 0");s.push_back( "7 15 8 15");s.push_back( "13 0 13 1");s.push_back( "21 23 22 23");s.push_back( "7 1 7 2");s.push_back( "21 5 21 4");s.push_back( "18 23 17 23");s.push_back( "2 17 2 18");s.push_back( "4 22 5 22");s.push_back( "11 4 12 4");s.push_back( "8 20 8 21");s.push_back( "1 5 1 4");s.push_back( "1 1 1 0");s.push_back( "4 19 5 19");s.push_back( "18 11 17 11");s.push_back( "23 18 23 17");s.push_back( "12 3 11 3");s.push_back( "1 16 1 17");s.push_back( "21 11 20 11");
	//s.push_back("1 2 2 2");
	cout<<"\n size is "<<sizeof(s)/sizeof(s[0]);
	long res=ob1.numWays(24,24,s);
	cout<<"\n res is ";//<<res<<"\n";
	printn(res);
	putc_unlocked('\n',stdout);
	return 0;
}				
				 
