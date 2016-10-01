//Geek for geeks Find number of times a string occurs as a subsequence in given string
#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
string str1,str2;
vector<vector<int> > dp;
int findRes(int s1,int s2)
{
   int res=0;
  if(s1<0 or s2<0)
  {
    return 0;
  }
  else if(dp[s1][s2]!=-1)
  {
    cout<<"dp["<<s1<<"]["<<s2<<"] = "<<dp[s1][s2]<<"\n";
    return dp[s1][s2];
  }
  else if(str1[s1]==str2[s2] and s2!=0)
  {
    res+=findRes(s1-1,s2-1)+findRes(s1-1,s2);
  }
  else if(str1[s1]!=str2[s2])
  {
     res+=findRes(s1-1,s2);
  }
  else if(s2==0 and str1[s1]==str2[s2])
  {
    return res+=1+findRes(s1-1,s2);
  }
  cout<<"for string 0 to "<<s1<<" and pattern 0 to "<<s2<<" we have "<<res<<"\n";
  return dp[s1][s2]=res;

}
int main()
{
  std::ios::sync_with_stdio(false);
  cin>>str1>>str2;
  int s=(str1.length()+1)*(str2.length()+1);
  memset(dp,-1,s*sizeof(*dp));
  cout<<"str1 is "<<str1<<" str2 is "<<str2<<"\n";
  cout<<"the result is "<<findRes(str1.length()-1,str2.length()-1)<<"\n";
  return 0;
}
