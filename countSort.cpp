#include "bits/stdc++.h"
using namespace std;


char temp[1<<10],ch;
#define For(i,start,end) for(i=start;i<=end;i++)
int arr[7]={0,4,1,2,7,5,2};

void countSort()
{
    int arr2[10];
    int i,j,k;
    For(i,0,10)
    {
        arr2[i]=0;
    }
    For(i,0,6)
    {
        arr2[arr[i]]++;
    }
    cout<<"arr2 is \n";
    For(i,0,9)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<"\n";
    For(i,1,9)
    {
        arr2[i]+=arr2[i-1];
    }
    cout<<"arr2 now is \n";
    For(i,0,9)
    {
        cout<<arr2[i]<<" ";
    }
    int arr3[8];
    For(i,0,6)
    {
        arr3[arr2[arr[i]]-1]=arr[i];
        arr2[arr[i]]--;
    }
    cout<<"the result is \n";
    For(i,0,6)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    countSort();
    return 0;
}
