//spoj plaindrome

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

string str1,str2;

void findRes()
{
  
 
  int i,j,k,len1=str1.length();
  str2=str1;
  if(len1%2==0)
  {
    i=(len1/2)-1;
    j=i+1;
  }
  else
  {
    i=(len1/2)-1;
    j=i+2;
  }
  while(i>=0 and j<len1)
  {
    str2[j]=str2[i];
    i--;j++;
  }
  i=j=(len1/2);
  if(len1%2==0)
  {
    i--;
   
  }
  //cout<<"so far str2 is "<<str2<<"\n";
  if(str2>str1)
  {
    return;
  }
  while(str2[i]=='9' and str2[j]=='9' and i>=0 and j<len1)
  {
    str2[i]='0';
    str2[j]='0';
    i--;
    j++;
  }
  if(i<0)
  {
    //str2=str2+'1';
    str2='1'+str2;
    str2[len1]='1';
    return;
  }
  k=str2[i]-'0';
  k++;
  str2[i]=str2[j]=k+'0';  
}

int main()
{
  std::ios::sync_with_stdio(false);
  int i,j,k,x,t;
  cin>>t;
  while(t--)
  {
    cin>>str1;
    //cout<<"str1 is "<<str1<<"\n";
    findRes();
    cout<<str2<<"\n";
  }
  return 0;
}
