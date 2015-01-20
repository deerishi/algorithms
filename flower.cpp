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
int size;
class FlowerGarden
{
	public:
		int order[100];
		int *getOrdering(int a[100],int b[100],int c[100]);
};
int* FlowerGrden ::getOrdering(int height[100],int bloom[100],int wilt[100])
{
	int	i,j,k;
	set<int> backup;
	backup.clear();

		
		for(i=0;i<size;i++)
		{
			order[i]=height[i];
			if(backup.count(j)==1) continue;
			else
			{
				for(j=i;;k<size;k++)
				{
					if(
				
			
	 

