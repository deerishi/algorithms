#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

int maxSubArray(vector<int>& nums) 
{
        int maxSoFar,maxOverall,startIndex,endIndex,finalStartIndex,finalEndIndex,i,n=nums.size();
        maxSoFar=nums[0];
        maxOverall=nums[0];
        startIndex=0;
        endIndex=0;
        for(i=1;i<n;i++)
        {
            //cout<<"maxSoFar is "<<maxSoFar<<" and maxOverall is "<<maxOverall<<" and startIndex is "<<startIndex<<" and endIndex is "<<endIndex<<"\n";
            if(nums[i]>maxSoFar and maxSoFar<0)
            {
                maxSoFar=nums[i];
                startIndex=i;
                endIndex=i;
            }
            else
            {
                maxSoFar+=nums[i];
                
            }
            if(maxSoFar>maxOverall)
            {
                maxOverall=maxSoFar;
                endIndex=i;
                finalStartIndex=startIndex;
                finalEndIndex=endIndex;
            }
        }
        /*cout<<"maxOverall is "<<maxOverall<<"\n";
        cout<<"startIndex is "<<finalStartIndex<<" endIndex is "<<finalEndIndex<<"\n";
        cout<<"max subarray is \n ";
        Forall(i,finalStartIndex,finalEndIndex)
        {
            cout<<nums[i]<<" ";
        }
        cout<<"\n";*/
        return maxOverall;
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
    maxSubArray(arr);
    return 0;
    
}
