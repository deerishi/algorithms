#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout)
#define forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

int findLIS(vector<int> nums)
{
    set<int> lis;
    set<int>::iterator it;
    int i,j;
    For(i,0,nums.size())
    {
       it=lis.lower_bound(nums[i]);
       if(it!=lis.end())
       {
            lis.erase(it);
       } 
       lis.insert(nums[i]);      
    }
    return lis.size();
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N,x;
    cin>>N;
   
    vector<int> nums;
    while(N--)
    {
        cin>>x;
        nums.push_back(x);
    }
    cout<<findLIS(nums)<<"\n";
    return 0;
    
}
