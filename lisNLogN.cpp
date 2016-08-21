#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
#define For(i,start,end) for(i=start;i<=end;i++)
int dp[1001][1001],arr[1001];

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




int lengthOfLIS(vector<int>& nums) 
{
    if(nums.size()==0)
    return 0;
    vector<int> parents;
    vector<pair<int,int> > lis,indexes;
    
    int i,j,low,high,res=0,mid;
    for(i=0;i<nums.size();i++)
    {
        indexes.push_back(make_pair(nums[i],i));
        if(lis.empty())
        {
            lis.push_back(make_pair(nums[i],i));
            parents.push_back(i);
            res++;
        }
        else
        {
            low=0;
            high=lis.size()-1;
            
            while(low<=high)
            {
                mid=(low+high)/2;
                if(low==high)
                {
                    if(nums[i]>lis[low].first)
                    {
                        low=mid+1;
                        break;
                    }
                    else
                    {
                        low=mid;
                        break;
                    }
                }
                else if(nums[i]>lis[mid].first)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            
           // cout<<"For "<<nums[i]<<"low is "<<low<<" ,  ";
            if(low==lis.size())
            {
                lis.push_back(make_pair(nums[i],i));
                //cout<<"lis["<<low-1<<"].second is "<<lis[low-1].second<<"\n";
                parents.push_back(lis[low-1].second);
                //cout<<"parent is index "<<lis[low-1].second<<"\n";
                if(lis.size()>res)
                {
                    res=lis.size();
                }
            }
            else
            {
                if(low==0)
                {
                    lis[low]=make_pair(nums[i],i);
                    parents.push_back(i);
                     //cout<<"parent is index "<<i<<"\n";
                }
                else
                {
                    int parent=lis[low-1].second;
                    lis[low]=make_pair(nums[i],i);
                    parents.push_back(parent);
                     //cout<<"parent is index "<<parent<<"\n";
                }
                if(low+1>res)
                {
                    res=low+1;
                }
            }
        }
       
    }
    /*cout<<"Printing lis array\n";
    for(i=0;i<lis.size();i++)
    {
        cout<<lis[i].first<<" ";
    }
    cout<<"\nPrinting the actual sequence\n";*/
    int k=lis.size()-1;
    int lastIndex=lis[k].second;
    vector<int> ans;
    while(indexes[lastIndex].second!=parents[lastIndex])
    {
        //cout<<"indexes["<<lastIndex<<"].first = "<<indexes[lastIndex].first<<" \n";
        ans.push_back(indexes[lastIndex].first);
        lastIndex=parents[lastIndex];      
        if(indexes[lastIndex].second==parents[lastIndex])
        {
             ans.push_back(indexes[lastIndex].first);
        }  
    }
    vector<int>::reverse_iterator it;
    /*for(it=ans.rbegin();it!=ans.rend();it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";*/
    return res;
}

int main()
{
    int n,i,x;
    vector<int> nums;
    n=getInt();
    for(i=0;i<n;i++)
    {
        x=getInt();
        nums.push_back(x);
    }
  
    int res=lengthOfLIS(nums);
    //cout<<"The length of the LIS is "<<res<<"\n";
    printn(res);
    blank;
    
    return 0;
}
