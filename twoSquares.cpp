#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
ll arr[1000000],n,end;
bool possible(ll diff)
{
   /* ll start=0,last=end;
    ll mid=(start+last)/2;
    while(start<last)
    {
        mid=(start+last)/2;
        if(arr[mid]==diff)
        {
            return true;
        }
        else if(arr[mid]>diff)99
        {
            last=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    return false;*/
    ll res=sqrt(diff);
    if(res*res==diff)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    ll i,diff,m;
    int flag=0;
   
    int c;
    scanf("%d",&c);
    for(m=0;m<c;m++)
    {
        scanf("%lld",&n);
        flag=0;
         end=(ll)sqrt(n) +1;
        for(i=0;i<=(end)+1 ;i++)
        {
            diff=n- (i*i);
            bool res=possible(diff);
            if(res)
            {
                //cout<<"diff was "<<diff<<"\n";
                printf("Yes\n");  
                flag=1; 
                break;
            }
        }
        if(flag==0)
        {
            printf("No\n");
        }
    }
    return 0;
}
