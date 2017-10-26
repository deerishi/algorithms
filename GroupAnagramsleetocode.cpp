#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

class Solution {
public:
    
     static bool cmp(pair<string,int> a,pair<string,int> b){
        string s1=a.first,s2=b.first;
        int res=s1.compare(s2);
        if(res<0) return true;
        
        return false;
        }
        static bool cmp2(string a,string b){
       
        int res=a.compare(b);
        if(res<0) return true;
        
        return false;
     }
    
    
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        int i,j,k;string s1,prev;
        unordered_map<string,int> map1;
        vector<vector<string> > res;
        k=0;
        for(i=0;i<strs.size();i++){
            s1=strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(map1.find(s1)!=map1.end()){
                res[map1[s1]].push_back(strs[i]);
            }
            else{
                map1.insert(make_pair(s1,k+1));
                k++;
                res.push_back(vector<string>());
                res[k].push_back(strs[i]);
            }
        }
        
    return res;     
    }
};
