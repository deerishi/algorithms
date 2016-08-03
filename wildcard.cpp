#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
#define For(i,start,end) for(i=start;i<=end;i++)
int dp[1001][1001],arr[1001];

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
bool isMatch(string s, string p) 
{
    int i,j;
    vector<bool> arr[p.length()+1];
    arr[0].push_back(1);
    For(i,1,s.length())
    {
        arr[0].push_back(0);
    }        
    For(i,1,p.length())
    {
        if(p[i-1]=='*')
        {
            //cout<<"arr[i-1][0] is "<<arr[i-1][0]<<"\n";
            arr[i].push_back(arr[i-1][0]);
        }
        else
        {
            //cout<<"p["<<i-1<<"] is "<<p[i-1]<<"\n";
            arr[i].push_back(0);
            //arr[i][0]=0;
            //cout<<"2 arr["<<i<<"][0] is "<<arr[i][0]<<"\n";
        }
        //cout<<"i is "<<i<<"\n";
    }
    //cout<<"hi\n";
    
    For(i,1,p.length())
    {
        For(j,1,s.length())
        {
            //cout<<"p["<<i-1<<"] is "<<p[i-1]<<" and s["<<j-1<<"] is "<<s[j-1]<<"\n";
            if(p[i-1]=='?' or p[i-1]==s[j-1])
            {
                arr[i].push_back(arr[i-1][j-1]);
            }
            else if(p[i-1]=='*')
            {
                arr[i].push_back(arr[i-1][j]||arr[i][j-1]);
            }
            else
            {
                arr[i].push_back(0);
            }
        }
    }
    /*For(i,0,p.length())
    {
        For(j,0,s.length())
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    return arr[p.length()][s.length()];
}
    
int main()
{
    string s="baaabab",p="ba*?";
    cout<<isMatch(s,p)<<"\n";
    return 0;
}
