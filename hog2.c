#include<stdio.h>

char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
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
int max(int a ,int b)
{
	return (a>b)?a:b ;
}
int main()
{
	int arr[100][100],h,w,tiles,i,j,k,max_num,t, dp_max[100][100];
	t=getInt();
	while(t--)
	{
		
		h=getInt();
		w=getInt();
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				arr[i][j]=getInt();
			}
		}
		/*cout<<"\n the tiles are \n";
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			putc_unlocked('\n',stdout);
		}*/
	
		for(i=0,j=0;j<w;j++)
		dp_max[i][j]=arr[i][j];
		for(i=1;i<h;i++)
		{
			//cout<<"\n i is "<<i+1<<"\n";
			for(j=0;j<w;j++)
			{
				if((j-1)>=0 && (j+1)<w)
				{
					max_num=max(dp_max[i-1][j-1],dp_max[i-1][j]);
					max_num=max(dp_max[i-1][j+1],max_num); 
					//cout<<"\n choosing "<<max_num<<"\n";
					dp_max[i][j]=arr[i][j]+max_num;
				}
				else if((j-1)>=0 && (j+1)>=w)
				{
					dp_max[i][j]=arr[i][j]+max(dp_max[i-1][j-1],dp_max[i-1][j]);
					//cout<<"\n choosing "<<max(arr[i-1][j-1],arr[i-1][j])<<"\n";
				}
				else if((j-1)<0 && (j+1)<w)
				{
					dp_max[i][j]=arr[i][j]+max(dp_max[i-1][j+1],dp_max[i-1][j]);
					//cout<<"\n choosing "<<max(arr[i-1][j+1],arr[i-1][j])<<"\n";
				}
				else if((j-1)<0 && (j+1)>=w)
				{
					dp_max[i][j]=arr[i][j]+dp_max[i-1][j];
				}
			}
			/*cout<<"dp_max is \n";
			for(k=0;k<w;k++)
			cout<<dp_max[i][k]<<" ";*/
		}
		max_num=dp_max[h-1][0];
		for(i=h-1,j=1;j<w;j++)
		{
			if(max_num<dp_max[i][j]) max_num=dp_max[i][j];
		}
		printf("%d\n",max_num);
	}
			
	return 0;
}			
			
	
	
