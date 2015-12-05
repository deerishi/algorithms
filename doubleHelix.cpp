#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);

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
int intersections[10001],path1[10001],path2[10002],len1,len2,leni;

int main()
{
    int n1,n2,i,j,p1,p2,sum1,sum2;
    n1=getInt();
    unordered_map<int,int> m1;
    while(n1!=0)
    {
        len1=n1;
        m1.clear();
        for(i=0;i<n1;i++)
        {
            path1[i]=getInt();
            m1[path1[i]]=1;
        }   
        n2=getInt();
        len2=n2;
        for(i=0;i<n2;i++)
        {
            path2[i]=getInt();
        }
        j=0;
        for(i=0;i<len2;i++)
        {
            if(m1.count(path2[i])>0)
            {
                intersections[j++]=path2[i];
            }
        }
        leni=j;
        p1=0;p2=0;long long int res=0;
        for(i=0;i<leni;i++)
        {
            sum1=0;
            while(p1<len1 and path1[p1]!=intersections[i])
            {
                sum1+=path1[p1];
                p1++;
            }
            sum2=0;
            while(p2<len2 and path2[p2]!=intersections[i])
            {
                sum2+=path2[p2];
                p2++;
            }
            res+=max(sum1,sum2);
        }    
        sum1=0;
         while(p1<len1 )
            {
                sum1+=path1[p1];
                p1++;
            }
            sum2=0;
            while(p2<len2)
            {
                sum2+=path2[p2];
                p2++;
            }
            res+=max(sum1,sum2);
        printf("%lld \n",res); 
        n1=getInt();   
    }
}
