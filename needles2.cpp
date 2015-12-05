#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
#define Getch() getc_unlocked(stdin)
typedef long long int ll;

ll getInt()  
{ 
	ch=getc_unlocked(stdin); 
	////////cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*//////cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	ll sign=1,n=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		////////cout<<" in while 2 with ch as "<<ch; 
		n=n*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n*sign; 
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
vector<ll> dpTable;
string pattern;
void kmpTable()
{
    ll i,prevdp,pprevdp,flag;
    vector<ll>::iterator it;
    
    dpTable.push_back(0);
    for(i=1;i<pattern.length();i++)
    {
        it=dpTable.begin();
        prevdp=*(it+i-1);
        ////cout<<"prevdp is "<<prevdp<<" i is "<<i<<" bool is  "<<(pattern[prevdp]==pattern[i])<<"\n";
        if(pattern[prevdp]==pattern[i])
        {
            dpTable.push_back(prevdp+1);
        }
        else if(prevdp >0)
        {
        
            it=dpTable.begin();
            pprevdp=*(it+ prevdp-1);
           // //cout<<"1 pprevdp is "<<pprevdp<<" i is "<<i<<" bool is  "<<(pattern[pprevdp]==pattern[i])<<"\n";
            flag=0;
            while(1)
            {
                ////cout<<"pprevdp is "<<pprevdp<<" i is "<<i<<" bool is  "<<(pattern[pprevdp]==pattern[i])<<"\n";
                if(pattern[pprevdp]==pattern[i])
                {
                    dpTable.push_back(pprevdp+1);
                    flag=1;
                    break;
                }
                else
                {
                    it=dpTable.begin();
                    pprevdp=*(it+ pprevdp-1);
                }
                if(pprevdp==0 and pattern[pprevdp]!=pattern[i])
                {
                    dpTable.push_back(0);
                    break;   
                }
             }
            
        }
        else
        {
            dpTable.push_back(0);
        }
     }

    
}

void kmp()
{
    char ch;
    ch=Getch();
    ll counter=0,flag,i,lenS=0;
    vector<ll>:: iterator it;
    while(isalpha(ch))
    {
        if(ch==pattern[counter])
        {
            flag=0;
            ////cout<<"ch is "<<ch<<" \n";
            for(i=counter;i<pattern.length() and isalpha(ch) and flag==0;i++)
            {
//cout<<"2 ch is "<<ch<<" i= "<<i<<" counter = "<<counter<<" bool is "<<(ch==pattern[i])<<" flag is "<<flag<<"\n";
                if(ch!=pattern[i] and i>0)
                {
                    it=dpTable.begin();
                    counter=*(it+i-1);
                    
                    while(ch!=pattern[counter])
                    {
                        //cout<<"in while\n";
                        if(counter==0)
                        {
                            ch=Getch();
                            lenS++;
                             flag=1;
                           
                            break;
                        }
                        it=dpTable.begin();
                        counter=*(it+i-1);
                        
                    }
                    //i=counter;
                    if(i+1==pattern.length())
                    {
                        i++;
                    }
                    //cout<<"after mismatch counter is "<<counter<<" flag is "<<flag<<"\n";
                }
                else 
                {
                    //cout<<"in else i="<<i<<"\n";
                    if(i+1==pattern.length())
                    {
                        it=dpTable.begin();
                        counter=*(it+i-1);
                        //counter=0;
                        i++;
                        break;
                    }
                    else
                    {
                        ch=Getch();
                        lenS++;
                    }
                }
            }
            if(i==pattern.length() )
            {
                printf("%lld\n",lenS-pattern.length()+1);
            }
        }
        else
        {
            ch=Getch();
            lenS++;
        }
    }
    //cout<<"\n";
}

int main()
{
    char ch;
    int t;
    //t=getInt();
    while(scanf("%d",&t)>0)
    {
        ////cout<<"t is "
        ch=Getch();
        ch=Getch();
        pattern.clear();
        while(ch!='\n')
        {
            pattern=pattern+ch;
            ch=Getch();
        }
        dpTable.clear();
        kmpTable();
        /*cout<<"the kmp table is \n";
        vector<int> :: iterator it=dpTable.begin();
        for(;it!=dpTable.end();it++)
        {
          cout<<(*it)<<" ";
            
        }
        cout<<"\n";*/
        kmp();
        blank;  
                //ch=Getch();
    }
   // return 0;   
}
