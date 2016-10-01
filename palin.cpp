#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
void findPalin(vector<int>& digits)
{
  
  if (digits.size()==1) {
    return 11;
  }
  bool isAll9=true;
  int n=digits.size();
  int i,j;
  if(n%2==0)
  {
    i=n/2 -1;
    j=i+1;
  }
  else
  {
    i=n/2 -1;
    j=n/2+1;
    if(digits[i+1]!=9)
    {
      isAll9=false;
    }
  }
  bool hasInc=false,hasChanged=false;
  for(;i>=0 and j<=n-1;i--,j++)
  {
    if(digits[i]!=9 or digits[j]!=9)
    {
      isAll9=false;
    }
    if(digits[i]<digits[j] and hasInc==false)
    {
      digits[i]++;
      digits[j]=digits[i];
      hasInc=true;
      hasChanged=true;
    }
    else if(digits[i]>digits[j])
    {
      digits[j]=digits[i];
      hasChanged=true;
    }
    else if(digits[i]<digits[j] and hasInc==true)
    {
      digits[j]=digits[i];
      hasChanged=true;
    }
  }

  if(hasChanged==false)
  {
    if(isAll9==true)
    {
      digits.clear();
      digits.push_back(1);
      For(i,0,n-2)
      {
        digits.push_back(0);
      }
      digits.push_back(1);
    }
    else
    {
      if(n%2==0)
      {
        if(digits[n/2]!=9)
        {
          digits[n/2]++;
          digits[n/2 - 1]++;
        }
        else
        {
          i=n/2 -1;
          j=i+1;
          while(digits[i]==9 and digits[j]==9)
          {
            digits[i]=(digits[i]+1)%10;
            digits[j]=(digits[j]+1)%10
                i--;
            j++;
          }
           digits[i]=(digits[i]+1)%10;
            digits[j]=(digits[j]+1)%10
          
        }
      }
      else
      {
        if(digits[n/2]!=9)
        {
          digits[n/2]++;
        }
        else
        {
          digits[n/2]=
        }
      }
    }
  }
                    
  
}

int main()
{
  std::ios::sync_with_stdio(false);
  int i,j,k,t;
  cin >> t;
  while(t--)
  {
    //cout<<"enter num \n";
    cin >> k;
    cout<<findPalin(k)<<"\n";
  }
  return 0;
}
