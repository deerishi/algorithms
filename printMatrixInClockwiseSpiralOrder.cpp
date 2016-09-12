#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<vector<int> > arr;
void printSprial(int r,int c)
{
    int sr=0,sc=0,er=r-1,ec=c-1;
    int i,j,k;
    while(sr<=er and sc<=ec)
    {
        Forall(i,sr,er)
        {
            cout<<arr[i][sc]<<" ";
        }
        Forall(j,sc+1,ec)
        {
            cout<<arr[er][j]<<" ";
        }
        for(i=er-1;i>=sr;i--)
        {
            cout<<arr[i][ec]<<" ";
        }
        for(j=ec-1;j>sc;j--)
        {
            cout<<arr[sr][j]<<" ";
        }
        cout<<"\n";
        sr++;
        er--;
        sc++;
        ec--;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k;
    Forall(i,1,5)
    {
        arr.push_back(vector<int>());
        Forall(j,1,5)
        {
            arr[i-1].push_back((i-1)*5+j);
        }
    }
    cout<<"the original matrix is\n";
    For(i,0,5)
    {
        For(j,0,5)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n the clockwise spiral is \n";
    printSprial(5,5);
    return 0;
}
