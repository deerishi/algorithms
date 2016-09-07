#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

int maxProduct(vector<int>& nums) 
{
    int i,j,k,n=nums.size();
    
    int maxProductSoFar=nums[0],maxProductOverall=nums[0],startIndex=0,endIndex=0,finalEndIndex,finalStartIndex;
    int minNegativeProductSoFar=1,maxPositiveProductSoFar=1;
    /*if(nums[0]>0)
    {
        maxPositiveProductSoFar=nums[0];
        minNegativeProductSoFar=0;
    }
    else if(nums[0]<0)
    {
        maxPositiveProductSoFar=0;
        minNegativeProductSoFar=nums[0];
    }
    else
    {
        maxPositiveProductSoFar=0;
        minNegativeProductSoFar=0;
    }*/
    For(i,0,n)   
    {
        if(nums[i]>0)
        {
            maxPositiveProductSoFar*=nums[i];
        }
        else if(nums[i]<0)
        {
            minNegativeProductSoFar*=nums[i]);
            if(maxProductOverall<minNegativeProductSoFar)
            {
                maxProductOverall=minNegativeProductSoFar;
                maxPositiveProductSoFar=maxProductOverall
            }
            if(minNegativeProductSoFar<maxPositiveProductSoFar)
            {
                maxPositiveProductSoFar=1;
            }
        }
        
        if(maxProductSoFar>maxProductOverall)
        {
            maxProductOverall=maxProductOverall;
            endIndex=i;
            finalEndIndex=endIndex;
            finalStartIndex=startIndex;
        }
    }     
}

int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> arr;
    int x,n,i;
    cin>>n;
    For(i,0,n)
    {
        cin>>x;
        arr.push_back(x);
    }
    maxProduct(arr);
    return 0;
    
}
