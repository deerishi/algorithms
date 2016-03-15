#include "bits/stdc++.h"

using namespace std;
char temp[1<<10],ch;

long long int getInt()
{
    ch=getc_unlocked(stdin);
    while(ch<'-')
    {
        ch=getc_unlocked(stdin);
    }
    long long int sign=1,num=0;
    if(ch=='-')
    {
        sign=-1;
    }
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getc_unlocked(stdin);
    }
    return num*sign;
    
}

int main() 
{
	//char arr[20]="hello world";
	long long int x,y,exp,num,n2;
	char str[10];
	//cout<<"Int max is "<<INT_MAX<<"\n";
	//unordered_map m1;
	while(1)
	{   
	    scanf("%s",str);//cout<<" str is "<<str<<"\n";
	    if(strcmp(str,"00e0")==0)
	    {
	        return 0;
	    }
	    x=str[0]-'0';
	    y=str[1]-'0';
	    exp=str[3]-'0';
	    num=(x*10+y)*((long long int)(pow(10,exp)));
	    //cout<<"num is "<<num<<"\n";
	    if(num==1)
	    {
	        printf("%d\n",1);
	    }
	    exp=(long long int)(log2(num));
	    n2=(long long int)(pow(2,exp));
	    printf("%lld\n",1+(num-n2)*2);
	    
	}
    return 0;
}
