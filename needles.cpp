#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	////cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*//cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		////cout<<" in while 2 with ch as "<<ch; 
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

vector<int> dp;
string pattern,str;
void kmpTable()
{
    int i,prevDp;
    //cout<<" strlen(pattern) is "<<pattern<<"\n";
    dp.clear();
    vector<int>::iterator it=dp.begin();
    //cout<<"hi\n";
    if(pattern.length()>0)
    {
       dp.push_back(0);
        it=dp.begin();
        for(i=1;i<pattern.length();i++)
        {
            it=dp.begin();
            prevDp= *(it+i-1);
            //cout<<"prevDp is"<<prevDp<<" pattern at prevdp is "<<(pattern[prevDp]==pattern[i])<<"\n";
            if(pattern[prevDp]==pattern[i])
            {
                //cout<<"p1\n";
                dp.push_back(prevDp+1);
               // it++;
                //cout<<"it is "<<*it<<"\n";
            }
            else
            {
                 //cout<<"p2\n";
                dp.push_back(0);
                //it++;
                //cout<<"it is "<<*it<<"\n";
            }

        }
    }
    

}

void kmp()
{
    vector<int>:: iterator it=dp.begin();
    
    int counter=0,prevDp,skipAhead,j,flag=0;
    int lenP=pattern.length();
    //cout<<"lenP is"<<lenP;
    char ch=getc_unlocked(stdin);
    int i=0;
    while(isalpha(ch))
    {
        //cout<<"ch is "<<ch<<" i is "<<i<<"\n";
        j=0;
        if(ch==pattern[counter])
        {
            for(j=counter;j<lenP and isalpha(ch);j++)
            {
                //cout<<"counter is "<<j<<"\n";

                if(ch!=pattern[j])
                {
                    //int len=j;
                     it=dp.begin();
                     prevDp=*(it + (j-1));
                     skipAhead=j-prevDp;
                     //i+=j;
                      counter=prevDp;
                     flag=1;
                     while(str[counter]!=ch)
                     {
                        //partialMatchLenth=counter-1
                        it=dp.begin();
                        if(counter==0)
                        {
                            flag=0;
                            break;
                        }
                        prevDp=*(it + (counter-1));
                        skipAhead=counter-prevDp;
                        counter=prevDp;
                     }
                     if(flag==0)
                     {
                        break;
                     }
                     j=counter-1;
                }
               
                    if(j+1!=lenP)
                    {           
                        ch=getc_unlocked(stdin);i++;
                        //cout<<"1 increamented i n j  are "<<i<<" "<<j<<"\n";
                    }
                
            }   
            //cout<<"j is "<<j<<" ch is "<<isalpha(ch)<<"\n";
            if(j>=pattern.length())
            {
                printf("%d\n",i-lenP+1);
                it=dp.begin();
                prevDp=*(it + (j-2));
                //skipAhead=j-prevDp;
                     //i+=j;
                counter=prevDp;
                //counter=0;


            }
        }
        
         if(j<lenP and isalpha(ch))      
         {
            ch=getc_unlocked(stdin);
            i++;
            //cout<<"1 increamented i n j  are "<<i<<" "<<j<<"\n";
           }
    }
    
}

int main()
{
    
    int d;
    scanf("%d",&d);
    while(d>0)
    {
        //scanf("%d",&d);
        char ch=getc_unlocked(stdin);
         ch=getc_unlocked(stdin);
        //cout<<"ch is "<<ch<<"\n";
        while(ch!='\n')
        {
            pattern+=ch;
            ch=getc_unlocked(stdin);
        }

        //scanf("%s",pattern);
        kmpTable();
        //cout<<"the kmp table is \n";
        vector<int> :: iterator it=dp.begin();
       /* for(;it!=dp.end();it++)
        {
            cout<<(*it)<<" ";
            
        }
        cout<<"\n";*/
        kmp(z   ;
        //char ch2=getc_unlocked(stdin);
        //cout<<"ch2 is "<<ch2<<"\n";
        //blank;
        cout<<"fg";
        int x=scanf("%d",&d);
        cout<<" x is "<<x;
    }
    return 0;
    
}
