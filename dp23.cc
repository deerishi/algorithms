#include "bits/stdc++.h"
using namespace std;
typedef  long long int ll;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

int maxProduct(vector<int>& nums)
{
    int i,j,maxProduct= nums[0],curProduct= nums[0],numNegativeNumbers=0;
    For(i,0,nums.size())
    {
        if(nums[i]<0) numNegativeNumbers++;
    }
    int neg2=numNegativeNumbers;
    if( nums[0]<0) numNegativeNumbers--;
    
    For(i,1,nums.size())
    {
        //cout<<"in 1 curProduct is "<<curProduct<<" maxProduct is "<<maxProduct<<"\n";
        if(maxProduct<curProduct) maxProduct=curProduct;
        
        if( nums[i]<0 )
        {
            numNegativeNumbers--;
            if(curProduct==0) curProduct=nums[i];
            else curProduct*= nums[i];
            
        }
        else if( nums[i]==0)
        {
            curProduct=0;
        }
        else if( nums[i]>0)
        {
            if(curProduct==0) curProduct= nums[i];
            else if(curProduct<0 and numNegativeNumbers==0) curProduct= nums[i];
            //else if(curProduct<0 and numNegativeNumbers>0) curProduct*= nums[i];
            else curProduct*= nums[i]; 
        }
    }
    if(maxProduct<curProduct) maxProduct=curProduct;
    return maxProduct;
}
int maxProduct2(vector<int> &nums)
{   
    int n=nums.size()-1;
    int i,j,maxProduct= nums[n],curProduct= nums[n],numNegativeNumbers=0;
    For(i,0,nums.size())
    {
        if(nums[i]<0) numNegativeNumbers++;
    }
    int neg2=numNegativeNumbers;
    if( nums[n]<0) numNegativeNumbers--;
    
    for(i=n-1;i>=0;i--)
    {
        if(maxProduct<curProduct) maxProduct=curProduct;
        
        if( nums[i]<0 )
        {
            numNegativeNumbers--;
            if(curProduct==0) curProduct=nums[i];
            else curProduct*= nums[i];

        }
        else if( nums[i]==0)
        {
            curProduct=0;
        }
        else if( nums[i]>0)
        {
            if(curProduct==0) curProduct= nums[i];
            else if(curProduct<0 and numNegativeNumbers==0) curProduct= nums[i];
            //else if(curProduct<0 and numNegativeNumbers>0) curProduct*= nums[i];
            else curProduct*= nums[i]; 
        }
    }
    if(maxProduct<curProduct) maxProduct=curProduct;
    return maxProduct;
}
int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> nums;
    int i,j,k,n,x,res;
    cin>>n;
    For(i,0,n)
    {
        cin>>x;
        nums.push_back(x);
    }   
    cout<<max(maxProduct(nums),maxProduct2(nums))<<"\n";
    
    return 0;
}
