#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ROW 1234
#define COL 5678
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
	ptr++;
	while(*ptr!='\0')
	{
		putc_unlocked(*ptr++,stdout);
	}
}
int arr[1235][5679],row[1235],col[5679];

void initialize()
{
    int i,j;
    for(i=0;i<1235;i++)
    {
        row[i]=i;
    }
    for(i=0;i<5679;i++)
    {
        col[i]=i;
    }
}
void swapCol(int x,int y)
{
    int temp;
    temp=col[x];
    col[x]=col[y];
    col[y]=temp;
    
}

void swapRow(int x,int y)
{
    int temp;
    temp=row[x];
    row[x]=row[y];
    row[y]=temp;
}

pair<int,int> findPosition(int z)
{
    int k,r1,c1,i;
    if(z%COL==0)
    {
        r1=z/COL;
    }
    else
    {
        r1=int(z/COL) +1;
    }
    c1=z-COL*(r1-1);
    //Now we find at which position c1 is in col, and at which position r1 is in row
    int posR,posCol;
    for(i=0;i<1235;i++)
    {
        if(row[i]==r1)
        {
            posR=i;
            break;
        }
    }
    for(i=0;i<5679;i++)
    {
        if(col[i]==c1)
        {
            posCol=i;
            break;
        }
    }
    return make_pair(posR,posCol);
}
int main()
{
     initialize();
     char ch2;
     int i,j,x,y,z, r1,c1;
     pair<int,int> res;
     while(scanf("%c",&ch2)>0)
     {
        switch(ch2)
        {
            case 'R': x=getInt();
                      y=getInt();
                      swapRow(x,y);
                      break;
            case 'C':x=getInt();
                      y=getInt();
                      swapCol(x,y);
                      //blank;
                      break;
            case 'Q':x=getInt();
                      y=getInt();
                      printn((row[x]-1)*COL + col[y]);
                      blank;
                      break;
            case 'W': z=getInt();
                      res=findPosition(z);
                      printn(res.first);
                      putc_unlocked(' ',stdout);
                      printn(res.second);
                      blank;
                       break;
                      
        }
        
     }
}
