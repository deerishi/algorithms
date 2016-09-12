//Geek for geeks Bitmasking and Dynamic Programming | Set 1 (Count ways to assign unique cap to every person)
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<vector<int> >dp,arr;


int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,capnum,n,x;
    cin>>n>>capnum;
    Forall(i,0,n)
    {
        arr.push_back(vector<int>(capnum+1,0));
    }
    int lim=1<<n;
    lim--;
    Forall(i,0,capnum)
    {
        dp.push_back(vector<int>(lim+1,0));

    }
    string temp,str;
    getline(cin,str);
    Forall(i,1,n)
    {
        getline(cin,str);
        stringstream ss(str);
        while(ss>>temp)
        {
            stringstream s;
            s<<temp;
            s>>x;
            arr[i][x]=1;
        }
    }
    dp[0][0]=1;
    cout<<"input complete arr is \n";
    Forall(i,1,n)
    {
        Forall(j,0,capnum)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    Forall(i,1,capnum)
    {
        Forall(j,0,lim)
        {
            int people=j,count=1;
            while(people)
            {
                int p=people&1;
                people=people>>1;
                if(p==1 and arr[count][i]==1)
                {
                    int mask=j&(~(1<<(count-1)));
                    dp[i][j]+=dp[i-1][mask];
                }
                count++;
            }
            dp[i][j]+=dp[i-1][j];
        }
    }
    cout<<"\n the dp table is \n";
    Forall(i,0,capnum)
    {
        Forall(j,0,lim)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}
