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
int arr[100],heap[256],sorted_heap[256];
void restore_heap(int end);
void build(int start,int end)
{
	heap[0]=arr[1];
	int i;
	for(i=start;i<=end;i++)
	{
		heap[i+1]=arr[i];
		restore_heap(i+1);
	}
}
void restore_heap(int end)//percolation up
{
	int i=end;
	int temp=heap[end];
	while(((i/2)>0) and heap[i/2]>heap[i])
	{
		heap[i]=heap[i/2];
		heap[i/2]=temp;
		i/=2;
	}
}

void restore_heap_percolation_down(int start,int end)
{
	heap[start]=heap[end];
	int i=start;
	int temp=heap[start];
	while((2*i<end and heap[i]>heap[2*i]) or ((2*i+1)<end and heap[i]>heap[2*i+1]))
	{
		if(heap[2*i]<heap[2*i+1])
		{
			heap[i]=heap[2*i];
			heap[2*i]=temp;
			i=2*i;
		}
		else
		{
			heap[i]=heap[2*i+1];
			heap[2*i+1]=temp;
			i=2*i+1;
		}
	}
	cout<<"\npartially  the heap is \n";
	for(i=start;i<end;i++)
	cout<<heap[i]<<" ";
	cout<<"\n";			
}	 

void heap_sort(int end)
{
	int i;
	for(i=1;i<end;i++)
	{	
		sorted_heap[i]=heap[1];
		restore_heap_percolation_down(1,end-i+1);
	}
	sorted_heap[i]=heap[i];
}
	

	
int main()
{
	int i,j,k,n;
	n=getInt();
	for(i=0;i<n;i++)
	arr[i]=getInt();
	build(0,n-1);
	cout<<"\n the heap is \n";
	for(i=1;i<=n;i++)
	cout<<heap[i]<<" ";
	cout<<"\n";
	cout<<"\n the sorted heap is \n";
	heap_sort(n);
	for(i=1;i<=n;i++)
	cout<<sorted_heap[i]<<" ";
	cout<<"\n";
	return 0;
}
	
