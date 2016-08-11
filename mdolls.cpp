#include "bits/stdc++.h"
using namespace std;
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

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}
int findNumberOfIncreasingSubsequences(vector<pair<int,int> >& dolls)
{
    sort(dolls.begin(),dolls.end(),cmp);
    vector<pair<int,int> >::iterator it;
    for(it=dolls.begin();it!=dolls.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<" \n";
    }
    cout<<"\n";
    vector<int> incomingEdges,outgoingEdges;
    vector<int> parents;
    vector<pair<int,int> > lis;
    int i,j,k;
    for(i=0;i<dolls.size();i++)
    {
        incomingEdges.push_back(0);
        outgoingEdges.push_back(0);
        if(lis.empty())
        {
            lis.push_back(make_pair(dolls[i].second,i));
            parents.push_back(i);
            continue;
        }
        int low=0,mid;
        int high=lis.size()-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            //cout<<"low = "<<low<<" high="<<high<<"\n";
            //cout<<"dolls["<<i<<"].second is "<<dolls[i].second<<" and lis["<<mid<<"].first is "<<lis[mid].first<<"\n";
            if(low==high)
            {
                if(dolls[i].second > lis[low].first)
                {
                    low=low+1;
                    break;
                }
                else
                {
                    //in essence the low remains the same
                    break;
                }
            }
            else if(dolls[i].second > lis[mid].first)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            
        }
        if(low==0)
        {
            parents.push_back(i);
            lis[0]=make_pair(dolls[i].second,i);
        }
        else
        {
            if(low>=lis.size())
            {
                parents.push_back(lis[low-1].second);
                lis.push_back(make_pair(dolls[i].second,i));
                incomingEdges[parents[i]]++;
                outgoingEdges[i]++;
             }
             else
             {
                parents.push_back(lis[low-1].second);
                lis[low]=make_pair(dolls[i].second,i);
                incomingEdges[parents[i]]++;
                outgoingEdges[i]++;
             }
        }
        //cout<<"Inserted at "<<low<<" in lis "<<lis[low].first<<","<<lis[low].second<<"\n";
    }
    //Now we traverse the incomingEdges and outgoingEdges such that we take those which
    //hae 0 outgoing edges and more than 1 incomong but no outging
    /*cout<<"lis is \n";
    for(i=0;i<dolls.size();i++)
    {
        cout<<lis[i].first<<"  "<<lis[i].second<<"\n";
    }*/
    
    int res=0;
    /*cout<<"incoming edges are\n";
    for(i=0;i<dolls.size();i++)
    {
        cout<<incomingEdges[i]<<" ";        
    }
    cout<<"\n";
    cout<<"outgoing edges are\n";
    for(i=0;i<dolls.size();i++)
    {
        cout<<outgoingEdges[i]<<" ";        
    }
    cout<<"\n";*/
    for(i=0;i<dolls.size();i++)
    {
        if(incomingEdges[i]==0)
        {
            res+=1;
        }
    }
    
    //cout<<"res is ";
    printn(res);
    blank;
}
int main()
{
    int t=getInt();
    int w,h,n;
    while(t--)
    {
        vector<pair<int,int> > dolls;
        n=getInt();
        while(n--)
        {
            w=getInt();
            h=getInt();
            dolls.push_back(make_pair(w,h));
            
        }
        findNumberOfIncreasingSubsequences(dolls);
    }
    return 0;
}
