#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
char current[1<<10],ch;
//This is lexicographical topological sort
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
	ptr++;Bron–Kerbosch algorithm

	while(*ptr!='\0')
	{
		putc_unlocked(*ptr++,stdout);
	}
}

class order
{
    public:
      
      bool operator()(int a,int b)
      {
        return a>b;
      }  
};

priority_queue<int,vector<int>,order> queue1;

void printString(string s)
{
    int i;
    for(i=0;i<s.length();i++)
    {
        putc_unlocked(s[i],stdout);    
    }
}
int n,m;
int degree[111111];
bool visited[111111];
vector<int> adjacencyList[111111];
vector<int> results;
int main()
{
    n=getInt();
    m=getInt();
    vector<int>::iterator it1,it2;
    int i,j,k,counter,val,x,y,current;
    for(i=1;i<=n;i++)
    {
        visited[i]=false;
        degree[i]=0;
    }
    for(i=1;i<=m;i++)
    {
        x=getInt();
        y=getInt();
        
        degree[y]++;
        adjacencyList[x].push_back(y);
    }
    bool flag=false;
    for(i=1;i<=n;i++)
    {
       // cout<<"i= "<<i<<" degree[i] is "<<degree[i]<<"\n";
        if(degree[i]==0)
        {
            flag=true;
             //cout<<"initial pushing "<<i<<"\n";
            queue1.push(i);
        }
    }
    string str="Sandro fails.";
    if(flag==false)
    {
        
        printString(str);
        blank;
        return 0;
    }
    while(!queue1.empty())
    {
        current=queue1.top();
        //cout<<"current is "<<current<<"\n";
        results.push_back(current);
        queue1.pop();
        visited[current]=true;
        for(it1=adjacencyList[current].begin();it1!=adjacencyList[current].end();it1++)
        {
            //cout<<"*it1 is "<<(*it1)<<"\n";
            if(visited[*it1]==true)
            {
                continue;
            }
            degree[*it1]--;
            if(degree[*it1]==0)
            {
                //cout<<"pushing "<<(*it1)<<"\n";
                queue1.push(*it1);
            }
        }
    }
    if(results.size()!=n)
    {
        printString(str);
        blank;
        return 0;
    }
    for(it1=results.begin();it1!=results.end();it1++)
    {
        printf("%d ",*it1);
        //putc_unlocked(' ',stdout);
    }
    blank;
    return 0;
}

