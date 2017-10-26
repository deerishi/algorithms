#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)
string num;

string max1;
int findRes(string num,int index,int k){
    //cout<<"k is "<<k<<"\n";
    int i;
    if(k==0 or index==int(num.length())){
        return 0;
    }
    int res=0;
    For(i,index+1,int(num.length())){
        string str2=num;
        if(num[i]>num[index] and res+i-index<=k){
            char ch=str2[i];
            str2[i]=str2[index];
            str2[index]=ch;
            res+=i-index;
            res+=findRes(str2,index+1,k-res);

        }
    }
    res+=findRes(num,index+1,k);
    return res;

}

int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
    int k=3;
    int n=8;
    int i;
    For(i,1,n+1){
        num+=to_string(i);
    }
    cout<<"num is "<<num<<"\n";
  max1=num;
  int res=findRes(num,0,k);
    cout<<"res is "<<res<<"\n";
  return 0;
}
