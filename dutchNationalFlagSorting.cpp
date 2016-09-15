//Geek for geeks Minimum Initial Points to Reach Destination

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<int> nums;
void sortTheDutchFlag()
{
    int i,j,k,m,n=nums.size();
    i=0;j=0;k=nums.size()-1;
    while(i<=j and j<=k and i<=k)
    {
               
        switch(nums[j])
        {
            case 1:j++;break;
            case 0: nums[j]=nums[i]; nums[i]=0;i++;j++;break;
            case 2: nums[j]=nums[k];nums[k]=2;k--;break;
        }
        
    }   
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,n,x;
    cin>>n;
    For(i,0,n)
    {
        cin>>x;
        nums.push_back(x);
    }    
    sortTheDutchFlag();

}
