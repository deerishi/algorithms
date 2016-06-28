#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define For(i,start,end) for(i=start;i<=end;i++)
char current[1<<10],ch;
//This is lexicographical topological sort
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//////cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*////cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//////cout<<" in while 2 with ch as "<<ch; 
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
	ptr++;

	while(*ptr!='\0')
	{
		putc_unlocked(*ptr++,stdout);
	}
}
int arr[100005];
bool isPrime(int n)
{
    int i,j;
    for(i=2;i<sqrt(n)+1;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
unordered_map<int,bool> visited;
int findGcd(int a, int b)
{
  
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return findGcd(b,a%b);
    }
}
void printResult(int L)
{
    printn(L);
    blank;
}

int main()
{
    int N,K,i,j,L,gcd;
    N=getInt();
    K=getInt();
    for(i=0;i<N;i++)
    {
        arr[i]=getInt();
    }
     if(N==1)
    {
           if(isPrime(arr[0]))
           {
                if(K>=arr[0])
                {
                    //Find the first multiple of N in K
                    L=K-(K%arr[0]);
                    printResult(L);
                    return 0;
                }
                else
                {
                    L=0;
                    printResult(L);
                    return 0;
                }
           }
           else
           {
                if(arr[0]%2==0)
                {
                    L=K-K%2;
                    printResult(L);
                    return 0;
                }
                else
                {
                    L=K-K%3;
                    printResult(L);
                    return 0;
                }
            }
    }
    else
    {
        sort(arr,arr+N);
        gcd=arr[0];
        visited[arr[0]]=true;
        for(i=1;i<N;i++)
        {
            if(visited[arr[i]]==true)
            {
                continue;
            }
            visited[arr[i]]=true;
            gcd=findGcd(gcd,arr[i]);
        }
        //  n   ow we have the CDG of the numbers
        //cout<<"gcd is "<<gcd<<"\n";
        if(K>=gcd)
        {
            if(isPrime(gcd))
            {
                L=K-K%gcd;
                //cout<<"K-K%gcd; is "<<K%gcd<<"\n";
                printResult(L);
                return 0;
            }
            else
            {
                for(j=K;j>1;j--)
                {
                    if(findGcd(gcd,j)!=1)
                    {
                        L=j;
                        printResult(L);
                        return 0;
                    }
                }
            }
        }
        else
        {
            for(j=K;j>1;j--)
            {
                if(findGcd(gcd,j)!=1)
                {
                    L=j;
                    printResult(L);
                    return 0;
                }
            }
        }
    }
    printn(0);
    blank;    
    return 0;
}
