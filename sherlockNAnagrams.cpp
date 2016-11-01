#include "bits/stdc++.h"
#define For(i,start,end) for(i=start;i<end;i++)
using namespace std;
string str;
int findRes(){
    int i,j,n=str.length(),res=0;
    unordered_map<string,int> map1;
    For(i,0,n){
        For(j,1,n-i+1){
            string str2=str.substr(i,j);
            string str3=str2;
            sort(str2.begin(),str2.end());
            //cout<<"substr is "<<str2<<"\n";
            //cout<<"str2 is "<<str2<<"\n";
            if(map1.find(str2)!=map1.end()){
                //cout<<"found "<<str3<<"\n";
                res+=map1[str2];
                map1[str2]++;
            }
            else{
                map1.insert(make_pair(str2,1));
            }
        }
    }
    return res;
        
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    std::ios::sync_with_stdio(false);
    int t,i,j,r;
    cin>>t;
    while(t--){
        cin>>str;
        r=findRes();
        cout<<r<<"\n";
    }
    
    return 0;
}

