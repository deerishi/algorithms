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
int arr[101],arr1[1000001],arr2[1000001];
int value;
bool binary(int start,int end)
{
    int mid;
   // mid=(start+end)/2;
    while(start<end)
    {
        mid=(start+end)/2;
        if(arr2[mid]==value)
        {
            return true;
        }
        else if(arr2[mid]<value)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        
    }
    return false;
}
int main()
{
	int n=getInt(),i,a,b,c,len1=0,len2=1;
	for(i=1;i<=n;i++)
	{
	    arr[i]=getInt();
	}
	for(a=1;a<=n;a++)
	{
	    for(b=1;b<=n;b++)
	    {
	        for(c=1;c<=n;c++)
	        {
	            arr1[c+n*(b-1)+n*n*(a-1)]=arr[a]*arr[b]+arr[c];
	            //cout<<"va is "<< c+n*(b-1)+n*n*(a-1)<<"\n";
	            len1++;
	            if(arr[a]!=0)
	            {
	                arr2[len2++]=arr[a]*(arr[b]+ arr[c]);
	                
	            }
	        }
	    }
	}
	//sort(arr1,arr1+len1);
	/*cout<<"arr1 is \n";
	for(i=1;i<=len1;i++)
	{
	    cout<<arr1[i]<<" ";
	}
	cout<<"\narr2 is \n";
	for(i=1;i<len2;i++)
	{
	    cout<<arr2[i]<<" ";
	}
	cout<<"\n";*/
	
	sort(arr2+1,arr2+len2);
	long long int res=0;
	unordered_map<int,int> m1;
	for(i=1;i<len2;i++)
	{
	    //cout<<"arr2[i] is "<<arr2[i]<<"\n";
	    if(m1.count(arr2[i])>0)
	    {
	        m1[arr2[i]]++;
	    }
	    else
	    {
	        m1[arr2[i]]=1;
	    }
	}
	//cout<<"map is  \n";
	//unordered_map<int,int>::iterator it;
	/*for(it=m1.begin();it!=m1.end();it++)
	{
	    cout<<it->first<<" "<<it->second<<"\n";
	}*/
	for(i=1;i<=len1;i++)
	{
	    if(binary_search(arr2+1,arr2+len2,arr1[i]))
	    {
	        res+=m1[arr1[i]];
	    }
	}
	printf("%lld\n",res);
	
}
